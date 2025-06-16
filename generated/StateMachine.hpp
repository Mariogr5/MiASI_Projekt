#pragma once
#include <vector>
#include "Context.hpp"
#include "State.hpp"
#include "Transition.hpp"
#include "Guard.hpp"
#include "Event.hpp"
#include "Activity.hpp"
#include "ServiceMode.hpp"
#include "FirmwareUpdate.hpp"
#include "CommunicationError.hpp"
#include "EmergencyTest.hpp"
#include "DeviceError.hpp"
#include "EmergencyReset.hpp"
#include "Initial.hpp"
#include "Ready.hpp"
#include "DataTransmission.hpp"
#include "ResultSaving.hpp"
#include "NetworkConfiguration.hpp"
#include "Measurement.hpp"
#include "WaitOnSynchronization.hpp"
#include "Diagnostic.hpp"

class StateMachine {
public:
	State *state;
	Context ctx;
	std::vector<State*> states;
	std::vector<Transition*> transitions;
	
	~StateMachine() = default;
	StateMachine() {
		State *start = new PseudoState();
		state = start;
		states.push_back(start);

		State *serviceMode = new ServiceMode();
		states.push_back(serviceMode);
		State *firmwareUpdate = new FirmwareUpdate();
		states.push_back(firmwareUpdate);
		State *communicationError = new CommunicationError();
		states.push_back(communicationError);
		State *emergencyTest = new EmergencyTest();
		states.push_back(emergencyTest);
		State *deviceError = new DeviceError();
		states.push_back(deviceError);
		State *emergencyReset = new EmergencyReset();
		states.push_back(emergencyReset);
		State *initial = new Initial();
		states.push_back(initial);
		State *ready = new Ready();
		states.push_back(ready);
		State *dataTransmission = new DataTransmission();
		states.push_back(dataTransmission);
		State *resultSaving = new ResultSaving();
		states.push_back(resultSaving);
		State *networkConfiguration = new NetworkConfiguration();
		states.push_back(networkConfiguration);
		State *measurement = new Measurement();
		states.push_back(measurement);
		State *waitOnSynchronization = new WaitOnSynchronization();
		states.push_back(waitOnSynchronization);
		State *diagnostic = new Diagnostic();
		states.push_back(diagnostic);
		
		transitions.assign({
			new Transition(networkConfiguration, waitOnSynchronization, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(networkConfiguration, communicationError, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(diagnostic, ready, Event::NONE_EVENT, Guard::checkConfigurationGuard, nullptr),
			new Transition(dataTransmission, ready, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(waitOnSynchronization, communicationError, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(start, initial, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(ready, measurement, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(ready, serviceMode, Event::CALL_EVENT_SERVICE_COMMAND, nullptr, nullptr),
			new Transition(deviceError, emergencyTest, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(measurement, resultSaving, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(resultSaving, dataTransmission, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(waitOnSynchronization, ready, Event::TIME_EVENT_AFTER_5MS, nullptr, nullptr),
			new Transition(resultSaving, deviceError, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(serviceMode, ready, Event::CALL_EVENT_EXIT_MAINTANANCE, nullptr, nullptr),
			new Transition(firmwareUpdate, deviceError, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(diagnostic, networkConfiguration, Event::NONE_EVENT, Guard::missingConfigurationGuard, Activity::startConfiguration),
			new Transition(emergencyTest, initial, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(communicationError, emergencyReset, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(firmwareUpdate, emergencyTest, Event::NONE_EVENT, nullptr, nullptr),
			new Transition(initial, diagnostic, Event::SIGNAL_EVENT_INIT_COMPLETE, nullptr, nullptr),
			new Transition(ready, firmwareUpdate, Event::SIGNAL_EVENT_FIRMWARE_UPDATE_AVAILABLE, Guard::firmwareUpdateAvailableGuard, Activity::downloadNewFirmware),
			new Transition(dataTransmission, communicationError, Event::NONE_EVENT, nullptr, nullptr),
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
		    if (t->guard && !t->guard(ctx)) {
				rc = 2;
				continue;
			}

		    state->exit(ctx);
		    if (t->activity) t->activity(ctx);
		    state = t->to;
		    state->enter(ctx);
		    state->doActivity(ctx);
		    rc = 0;
			break;
		}
		return rc;
	}
};
