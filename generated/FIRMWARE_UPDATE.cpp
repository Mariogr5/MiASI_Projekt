#include "FIRMWARE_UPDATE.hpp"
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
    context.setState(std::make_unique<DEVICE_ERROR>());
    return;
    context.setState(std::make_unique<EMERGENCY_TEST>());
    return;
    std::cout << "No valid transition from state: FIRMWARE_UPDATE" << std::endl;
}

const char* FIRMWARE_UPDATE::name() const {
    return "FIRMWARE_UPDATE";
}



