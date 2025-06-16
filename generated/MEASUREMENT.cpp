#include "Measurement.hpp"
#include <iostream>

void Measurement::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void Measurement::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void Measurement::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

