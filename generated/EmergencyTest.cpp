#include "EmergencyTest.hpp"
#include <iostream>

void EmergencyTest::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void EmergencyTest::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void EmergencyTest::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

