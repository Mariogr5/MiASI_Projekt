#include "WAIT_ON_SYNCHRONIZATION.hpp"
#include "Context.hpp"
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
    // Transition to READY
    context.setState(std::make_unique<READY>()); 
    return;
    // Transition to COMMUNICATION_ERROR
    context.setState(std::make_unique<COMMUNICATION_ERROR>()); 
    return;
}

const char* WAIT_ON_SYNCHRONIZATION::name() const {
    return "WAIT_ON_SYNCHRONIZATION";
}
