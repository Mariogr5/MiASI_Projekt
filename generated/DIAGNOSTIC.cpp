#include "Diagnostic.hpp"
#include <iostream>

void Diagnostic::enter(Context& ctx) {
	std::cout << "Entering state: " << name() << std::endl;
    // Your code for CHECK_IF_CONFIGURATION_EXISTS goes here.
}

void Diagnostic::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void Diagnostic::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

