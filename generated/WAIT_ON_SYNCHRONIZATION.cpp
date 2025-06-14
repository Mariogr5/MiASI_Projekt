#include "WAIT_ON_SYNCHRONIZATION.hpp"
#include <iostream>

void WAIT_ON_SYNCHRONIZATION::enter(Context& context) {
    std::cout << "Entering state: WAIT_ON_SYNCHRONIZATION" << std::endl;
}

void WAIT_ON_SYNCHRONIZATION::doActivity(Context& context) {
    std::cout << "Executing activity in state: WAIT_ON_SYNCHRONIZATION" << std::endl;
}

void WAIT_ON_SYNCHRONIZATION::exit(Context& context) {
    std::cout << "Exiting state: WAIT_ON_SYNCHRONIZATION" << std::endl;
}

void WAIT_ON_SYNCHRONIZATION::transition(Context& context) {
    context.setState(std::make_unique<COMMUNICATION_ERROR>());
    return;
    std::cout << "Event: synchronization_ended" << std::endl;
    context.setState(std::make_unique<READY>());
    return;
    std::cout << "No valid transition from state: WAIT_ON_SYNCHRONIZATION" << std::endl;
}

const char* WAIT_ON_SYNCHRONIZATION::name() const {
    return "WAIT_ON_SYNCHRONIZATION";
}



