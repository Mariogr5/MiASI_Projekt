#include "ServiceMode.hpp"
#include <iostream>

void ServiceMode::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void ServiceMode::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void ServiceMode::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

