#include "RESULT_SAVING.hpp"
#include "Context.hpp"
#include <iostream>

void RESULT_SAVING::enter(Context& context) {
    std::cout << "Entering state: RESULT_SAVING" << std::endl;
}

void RESULT_SAVING::doActivity(Context& context) {
    std::cout << "Executing activity in state: RESULT_SAVING" << std::endl;
}

void RESULT_SAVING::exit(Context& context) {
    std::cout << "Exiting state: RESULT_SAVING" << std::endl;
}

void RESULT_SAVING::transition(Context& context) {
    // Transition to DEVICE_ERROR
    context.setState(std::make_unique<DEVICE_ERROR>()); 
    return;
    // Transition to DATA_TRANSMISSION
    context.setState(std::make_unique<DATA_TRANSMISSION>()); 
    return;
}

const char* RESULT_SAVING::name() const {
    return "RESULT_SAVING";
}
