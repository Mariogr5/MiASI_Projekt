#include "DataTransmission.hpp"
#include <iostream>

void DataTransmission::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void DataTransmission::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void DataTransmission::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

