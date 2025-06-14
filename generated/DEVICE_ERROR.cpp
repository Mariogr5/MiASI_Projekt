#include "DEVICE_ERROR.hpp"
#include <iostream>

void DEVICE_ERROR::enter(Context& context) {
    std::cout << "Entering state: DEVICE_ERROR" << std::endl;
}

void DEVICE_ERROR::doActivity(Context& context) {
    std::cout << "Executing activity in state: DEVICE_ERROR" << std::endl;
}

void DEVICE_ERROR::exit(Context& context) {
    std::cout << "Exiting state: DEVICE_ERROR" << std::endl;
}

void DEVICE_ERROR::transition(Context& context) {
    context.setState(std::make_unique<EMERGENCY_TEST>());
    return;
    std::cout << "No valid transition from state: DEVICE_ERROR" << std::endl;
}

const char* DEVICE_ERROR::name() const {
    return "DEVICE_ERROR";
}



