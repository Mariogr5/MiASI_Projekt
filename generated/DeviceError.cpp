#include "DeviceError.hpp"
#include <iostream>

void DeviceError::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void DeviceError::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void DeviceError::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

