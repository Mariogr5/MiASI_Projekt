#include "DIAGNOSTIC.hpp"
#include "Context.hpp"
#include <iostream>

void DIAGNOSTIC::enter(Context& context) {
    std::cout << "Entering state: DIAGNOSTIC" << std::endl;
}

void DIAGNOSTIC::doActivity(Context& context) {
    std::cout << "Executing activity in state: DIAGNOSTIC" << std::endl;
}

void DIAGNOSTIC::exit(Context& context) {
    std::cout << "Exiting state: DIAGNOSTIC" << std::endl;
}

void DIAGNOSTIC::transition(Context& context) {
    // Transition to READY
    context.setState(std::make_unique<READY>()); 
    return;
    // Transition to NETWORK_CONFIGURATION
    context.setState(std::make_unique<NETWORK_CONFIGURATION>()); 
    return;
}

const char* DIAGNOSTIC::name() const {
    return "DIAGNOSTIC";
}
