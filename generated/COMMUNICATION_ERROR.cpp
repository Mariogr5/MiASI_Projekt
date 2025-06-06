#include "COMMUNICATION_ERROR.hpp"
#include "Context.hpp"
#include <iostream>

void COMMUNICATION_ERROR::enter(Context& context) {
    std::cout << "Entering state: COMMUNICATION_ERROR" << std::endl;
}

void COMMUNICATION_ERROR::doActivity(Context& context) {
    std::cout << "Executing activity in state: COMMUNICATION_ERROR" << std::endl;
}

void COMMUNICATION_ERROR::exit(Context& context) {
    std::cout << "Exiting state: COMMUNICATION_ERROR" << std::endl;
}

void COMMUNICATION_ERROR::transition(Context& context) {
    // Transition to EMERGENCY_RESET
    context.setState(std::make_unique<EMERGENCY_RESET>()); 
    return;
}

const char* COMMUNICATION_ERROR::name() const {
    return "COMMUNICATION_ERROR";
}
