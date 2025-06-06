#include "NETWORK_CONFIGURATION.hpp"
#include "Context.hpp"
#include <iostream>

void NETWORK_CONFIGURATION::enter(Context& context) {
    std::cout << "Entering state: NETWORK_CONFIGURATION" << std::endl;
}

void NETWORK_CONFIGURATION::doActivity(Context& context) {
    std::cout << "Executing activity in state: NETWORK_CONFIGURATION" << std::endl;
}

void NETWORK_CONFIGURATION::exit(Context& context) {
    std::cout << "Exiting state: NETWORK_CONFIGURATION" << std::endl;
}

void NETWORK_CONFIGURATION::transition(Context& context) {
    // Transition to WAIT_ON_SYNCHRONIZATION
    context.setState(std::make_unique<WAIT_ON_SYNCHRONIZATION>()); 
    return;
    // Transition to COMMUNICATION_ERROR
    context.setState(std::make_unique<COMMUNICATION_ERROR>()); 
    return;
}

const char* NETWORK_CONFIGURATION::name() const {
    return "NETWORK_CONFIGURATION";
}
