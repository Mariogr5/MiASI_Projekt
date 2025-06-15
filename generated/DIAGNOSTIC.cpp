#include "Diagnostic.hpp"
#include <iostream>

void Diagnostic::enter(Context& ctx) {
	std::cout << "Entering state: " << name() << std::endl;
    // Your code for CHECK_IF_CONFIGURATION_EXISTS goes here.
}

void Diagnostic::doActivity(Context& context) { return; }

void Diagnostic::exit(Context& ctx) { return; }

