#include "FIRMWARE_UPDATE.hpp"
#include "Context.hpp"
#include <iostream>

void FIRMWARE_UPDATE::enter(Context& context) {
    std::cout << "Entering state: FIRMWARE_UPDATE" << std::endl;
}

void FIRMWARE_UPDATE::doActivity(Context& context) {
    std::cout << "Executing activity in state: FIRMWARE_UPDATE" << std::endl;
}

void FIRMWARE_UPDATE::exit(Context& context) {
    std::cout << "Exiting state: FIRMWARE_UPDATE" << std::endl;
}

void FIRMWARE_UPDATE::transition(Context& context) {
    // Transition to EMERGENCY_TEST
    context.setState(std::make_unique<EMERGENCY_TEST>()); 
    return;
    // Transition to DEVICE_ERROR
    context.setState(std::make_unique<DEVICE_ERROR>()); 
    return;
}

const char* FIRMWARE_UPDATE::name() const {
    return "FIRMWARE_UPDATE";
}
