#include "EmergencyReset.hpp"
#include <iostream>

void EmergencyReset::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void EmergencyReset::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void EmergencyReset::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

