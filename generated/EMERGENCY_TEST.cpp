#include "EMERGENCY_TEST.hpp"
#include "Context.hpp"
#include <iostream>

void EMERGENCY_TEST::enter(Context& context) {
    std::cout << "Entering state: EMERGENCY_TEST" << std::endl;
}

void EMERGENCY_TEST::doActivity(Context& context) {
    std::cout << "Executing activity in state: EMERGENCY_TEST" << std::endl;
}

void EMERGENCY_TEST::exit(Context& context) {
    std::cout << "Exiting state: EMERGENCY_TEST" << std::endl;
}

void EMERGENCY_TEST::transition(Context& context) {
    // Transition to INITIAL
    context.setState(std::make_unique<INITIAL>()); 
    return;
}

const char* EMERGENCY_TEST::name() const {
    return "EMERGENCY_TEST";
}
