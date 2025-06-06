#include "MEASUREMENT.hpp"
#include "Context.hpp"
#include <iostream>

void MEASUREMENT::enter(Context& context) {
    std::cout << "Entering state: MEASUREMENT" << std::endl;
}

void MEASUREMENT::doActivity(Context& context) {
    std::cout << "Executing activity in state: MEASUREMENT" << std::endl;
}

void MEASUREMENT::exit(Context& context) {
    std::cout << "Exiting state: MEASUREMENT" << std::endl;
}

void MEASUREMENT::transition(Context& context) {
    // Transition to RESULT_SAVING
    context.setState(std::make_unique<RESULT_SAVING>()); 
    return;
}

const char* MEASUREMENT::name() const {
    return "MEASUREMENT";
}
