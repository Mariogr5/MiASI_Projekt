#include "DEVICE_ERROR.hpp"
#include "Context.hpp"
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
    // Transition to EMERGENCY_TEST
    context.setState(std::make_unique<EMERGENCY_TEST>()); 
    return;
}

const char* DEVICE_ERROR::name() const {
    return "DEVICE_ERROR";
}
