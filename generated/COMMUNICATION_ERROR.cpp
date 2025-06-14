#include "COMMUNICATION_ERROR.hpp"
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
    context.setState(std::make_unique<EMERGENCY_RESET>());
    return;
    std::cout << "No valid transition from state: COMMUNICATION_ERROR" << std::endl;
}

const char* COMMUNICATION_ERROR::name() const {
    return "COMMUNICATION_ERROR";
}



