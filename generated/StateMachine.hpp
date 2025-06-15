#pragma once
#include <vector>
#include "Context.hpp"
#include "State.hpp"
#include "Transition.hpp"
#include "Guard.hpp"
#include "Event.hpp"
#include "FirmwareUpdate.hpp"
#include "DeviceError.hpp"
#include "ResultSaving.hpp"
#include "EmergencyTest.hpp"
#include "NetworkConfiguration.hpp"
#include "Diagnostic.hpp"
#include "Measurement.hpp"
#include "WaitOnSynchronization.hpp"
#include "ServiceMode.hpp"
#include "Ready.hpp"
#include "EmergencyReset.hpp"
#include "Initial.hpp"
#include "DataTransmission.hpp"
#include "CommunicationError.hpp"

class StateMachine {
public:
	State *state;
	Context ctx;
	std::vector<State*> states;
	std::vector<Transition*> transitions;
	
	~StateMachine() = default;
	StateMachine() {
		State *start = new PseudoState("START");
		state = start;
		states.push_back(start);

		State *firmwareUpdate = new State("FIRMWARE_UPDATE");
		states.push_back(firmwareUpdate);
		State *deviceError = new State("DEVICE_ERROR");
		states.push_back(deviceError);
		State *resultSaving = new State("RESULT_SAVING");
		states.push_back(resultSaving);
		State *emergencyTest = new State("EMERGENCY_TEST");
		states.push_back(emergencyTest);
		State *networkConfiguration = new State("NETWORK_CONFIGURATION");
		states.push_back(networkConfiguration);
		State *diagnostic = new State("DIAGNOSTIC");
		states.push_back(diagnostic);
		State *measurement = new State("MEASUREMENT");
		states.push_back(measurement);
		State *waitOnSynchronization = new State("WAIT_ON_SYNCHRONIZATION");
		states.push_back(waitOnSynchronization);
		State *serviceMode = new State("SERVICE_MODE");
		states.push_back(serviceMode);
		State *ready = new State("READY");
		states.push_back(ready);
		State *emergencyReset = new State("EMERGENCY_RESET");
		states.push_back(emergencyReset);
		State *initial = new State("INITIAL");
		states.push_back(initial);
		State *dataTransmission = new State("DATA_TRANSMISSION");
		states.push_back(dataTransmission);
		State *communicationError = new State("COMMUNICATION_ERROR");
		states.push_back(communicationError);
		
		transitions.assign({
			new Transition(ready, measurement, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(waitOnSynchronization, communicationError, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(serviceMode, ready, Event::CALL_EVENT_EXIT_MAINTANANCE, nullptr, nullptr),
			new Transition(communicationError, emergencyReset, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(resultSaving, dataTransmission, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(ready, serviceMode, Event::CALL_EVENT_SERVICE_COMMAND, nullptr, nullptr),
			new Transition(start, initial, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(initial, diagnostic, Event::SIGNAL_EVENT_INIT_COMPLETE, nullptr, nullptr),
			new Transition(dataTransmission, communicationError, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(diagnostic, networkConfiguration, Event::NONE_EVENT, Guard::missingConfigurationGuard, nullptr),
			new Transition(networkConfiguration, communicationError, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(emergencyTest, initial, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(firmwareUpdate, emergencyTest, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(dataTransmission, ready, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(networkConfiguration, waitOnSynchronization, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(deviceError, emergencyTest, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(ready, firmwareUpdate, Event::SIGNAL_EVENT_FIRMWARE_UPDATE_AVAILABLE, Guard::firmwareUpdateAvailableGuard, nullptr),
			new Transition(waitOnSynchronization, ready, Event::TIME_EVENT_AFTER_5MS, nullptr, nullptr),
			new Transition(measurement, resultSaving, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(resultSaving, deviceError, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(diagnostic, ready, Event::NONE_EVENT, Guard::checkConfigurationGuard, nullptr),
			new Transition(firmwareUpdate, deviceError, Event::NONE_EVENT, nullptr, nullptr),
		});
	}

	int execute(Event event) {
		// RC 0 -> transition successfully done.
		// RC 1 -> no transitions from current state.
		// RC 2 -> transition blocked by guard.
		// RC 3 -> trigger does not match.
		int rc = 1;
		std::vector<Transition*> outgoing;
		for (auto* t : transitions) {
    		if (t->from == state) {
        		outgoing.push_back(t);
    		}
		}
		if (outgoing.empty()) {
			return rc;
		}
		
		for (auto* t : outgoing) {
		    if (t->trigger != Event::NONE_EVENT && t->trigger != event) {
				rc = 3;
				continue;
			}
		    if (t->guard && !t->guard(*ctx)) {
				rc = 2;
				continue;
			}

		    state->exit(*ctx);
		    if (t->activity) t->activity(*ctx);
		    state = t->to;
		    state->enter(*ctx);
		    state->doActivity(*ctx);
		    rc = 0;
			break;
		}
		return rc;
	}
};
