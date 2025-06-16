#include "WaitOnSynchronization.hpp"
#include <iostream>

void WaitOnSynchronization::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void WaitOnSynchronization::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void WaitOnSynchronization::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

