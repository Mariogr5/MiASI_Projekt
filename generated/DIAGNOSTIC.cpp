#include "DIAGNOSTIC.hpp"
#include <iostream>

void DIAGNOSTIC::enter(Context& context) {
    std::cout << "Entering state: DIAGNOSTIC" << std::endl;
    Check_if_configuration_exists(context);
}

void DIAGNOSTIC::doActivity(Context& context) {
    std::cout << "Executing activity in state: DIAGNOSTIC" << std::endl;
}

void DIAGNOSTIC::exit(Context& context) {
    std::cout << "Exiting state: DIAGNOSTIC" << std::endl;
}

void DIAGNOSTIC::transition(Context& context) {
    // To network configuration
    if (missing_configuration_guard(context)) {
    	start_configuration(context);
	    context.setState(std::make_unique<NETWORK_CONFIGURATION>());
	    return;
    }
    if (check_configuration_guard(context)) {
	    context.setState(std::make_unique<READY>());
	    return;
    }
    std::cout << "No valid transition from state: DIAGNOSTIC" << std::endl;
}

const char* DIAGNOSTIC::name() const {
    return "DIAGNOSTIC";
}

void DIAGNOSTIC::Check_if_configuration_exists(Context& context) {
    std::cout << "Executing Check_if_configuration_exists" << std::endl;
}

bool DIAGNOSTIC::missing_configuration_guard(Context& context) {
    return context.get_missing_configuration() == true;
}
bool DIAGNOSTIC::check_configuration_guard(Context& context) {
    return context.get_missing_configuration() == false;
}

void DIAGNOSTIC::start_configuration(Context& context) {
    std::cout << "Executing effect start_configuration" << std::endl;
}
