#include "INITIAL.hpp"
#include <iostream>

void INITIAL::enter(Context& context) {
    std::cout << "Entering state: INITIAL" << std::endl;
    init(context);
}

void INITIAL::doActivity(Context& context) {
    std::cout << "Executing activity in state: INITIAL" << std::endl;
    Init_components(context);
}

void INITIAL::exit(Context& context) {
    std::cout << "Exiting state: INITIAL" << std::endl;
    disable_initialization_functions(context);
}

void INITIAL::transition(Context& context) {
    std::cout << "Event: init_complete" << std::endl;
    // Initial to diagnostic comment
    context.setState(std::make_unique<DIAGNOSTIC>());
    return;
    std::cout << "No valid transition from state: INITIAL" << std::endl;
}

const char* INITIAL::name() const {
    return "INITIAL";
}

void INITIAL::init(Context& context) {
    std::cout << "Executing init" << std::endl;
}
void INITIAL::Init_components(Context& context) {
    std::cout << "Executing Init_components" << std::endl;
}
void INITIAL::disable_initialization_functions(Context& context) {
    std::cout << "Executing disable_initialization_functions" << std::endl;
}


