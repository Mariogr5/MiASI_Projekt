#include "MEASUREMENT.hpp"
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
    context.setState(std::make_unique<RESULT_SAVING>());
    return;
    std::cout << "No valid transition from state: MEASUREMENT" << std::endl;
}

const char* MEASUREMENT::name() const {
    return "MEASUREMENT";
}



