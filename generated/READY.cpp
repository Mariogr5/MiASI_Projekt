#include "Ready.hpp"
#include <iostream>

void Ready::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void Ready::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void Ready::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

