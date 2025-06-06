#include "READY.hpp"
#include "Context.hpp"
#include <iostream>

void READY::enter(Context& context) {
    std::cout << "Entering state: READY" << std::endl;
}

void READY::doActivity(Context& context) {
    std::cout << "Executing activity in state: READY" << std::endl;
}

void READY::exit(Context& context) {
    std::cout << "Exiting state: READY" << std::endl;
}

void READY::transition(Context& context) {
    // Transition to SERVICE_MODE
    context.setState(std::make_unique<SERVICE_MODE>()); 
    return;
    // Transition to MEASUREMENT
    context.setState(std::make_unique<MEASUREMENT>()); 
    return;
    // Transition to FIRMWARE_UPDATE
    context.setState(std::make_unique<FIRMWARE_UPDATE>()); 
    return;
}

const char* READY::name() const {
    return "READY";
}
