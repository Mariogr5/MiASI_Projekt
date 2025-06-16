#include <iostream>
#include "StateMachine.hpp"

int main() {
    std::cout << "===== STARTING FINITE STATE MACHINE (FSM) TEST =====\n";
    StateMachine sm;

    std::cout << "Initial state: " << sm.state->name() << "\n";

    // 0. START -> INITIAL
    int rc0 = sm.execute(Event::NONE_EVENT);
    std::cout << "RC: " << rc0 << std::endl;
    // 1. INITIAL -> DIAGNOSTIC
    int rc1 = sm.execute(Event::SIGNAL_EVENT_INIT_COMPLETE);
    std::cout << "RC: " << rc1 << std::endl;

    // 2. DIAGNOSTIC -> READY / NETWORK_CONFIGURATION
    int rc2 = sm.execute(Event::NONE_EVENT);
    std::cout << "RC: " << rc2 << std::endl;
    // 3. READY -> SERVICE_MODE
    // int rc3 = sm.execute(Event::CALL_EVENT_SERVICE_COMMAND);

    std::cout << "===== FSM TEST COMPLETE =====\n";

    return 0;
}
