#include "INITIAL.hpp"
#include "Context.hpp"
#include <iostream>

void INITIAL::enter(Context& context) {
    std::cout << "Entering state: INITIAL" << std::endl;
}

void INITIAL::doActivity(Context& context) {
    std::cout << "Executing activity in state: INITIAL" << std::endl;
}

void INITIAL::exit(Context& context) {
    std::cout << "Exiting state: INITIAL" << std::endl;
}

void INITIAL::transition(Context& context) {
    // Transition to DIAGNOSTIC
    // Trigger: init_complete
    context.setState(std::make_unique<DIAGNOSTIC>()); 
    return;
}

const char* INITIAL::name() const {
    return "INITIAL";
}
