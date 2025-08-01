#include "Initial.hpp"
#include <iostream>

void Initial::enter(Context& ctx) {
	std::cout << "Entering state: " << name() << std::endl;
    // Your code for INIT goes here.
}

void Initial::doActivity(Context& ctx) {
	std::cout << "Executing activity 'INIT_COMPONENTS' in state: " << name() << std::endl;
    // Your code for INIT_COMPONENTS goes here.
}

void Initial::exit(Context& ctx) {
	std::cout << "Exiting state: " << name() << std::endl;
    // Your code for DISABLE_INITIALIZATION_FUNCTIONS goes here.
}

