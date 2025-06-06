#include "EMERGENCY_RESET.hpp"
#include "Context.hpp"
#include <iostream>

void EMERGENCY_RESET::enter(Context& context) {
    std::cout << "Entering state: EMERGENCY_RESET" << std::endl;
}

void EMERGENCY_RESET::doActivity(Context& context) {
    std::cout << "Executing activity in state: EMERGENCY_RESET" << std::endl;
}

void EMERGENCY_RESET::exit(Context& context) {
    std::cout << "Exiting state: EMERGENCY_RESET" << std::endl;
}

void EMERGENCY_RESET::transition(Context& context) {
}

const char* EMERGENCY_RESET::name() const {
    return "EMERGENCY_RESET";
}
