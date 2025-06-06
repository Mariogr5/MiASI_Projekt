#include "SERVICE_MODE.hpp"
#include "Context.hpp"
#include <iostream>

void SERVICE_MODE::enter(Context& context) {
    std::cout << "Entering state: SERVICE_MODE" << std::endl;
}

void SERVICE_MODE::doActivity(Context& context) {
    std::cout << "Executing activity in state: SERVICE_MODE" << std::endl;
}

void SERVICE_MODE::exit(Context& context) {
    std::cout << "Exiting state: SERVICE_MODE" << std::endl;
}

void SERVICE_MODE::transition(Context& context) {
    // Transition to READY
    context.setState(std::make_unique<READY>()); 
    return;
}

const char* SERVICE_MODE::name() const {
    return "SERVICE_MODE";
}
