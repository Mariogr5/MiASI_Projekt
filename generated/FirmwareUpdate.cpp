#include "FirmwareUpdate.hpp"
#include <iostream>

void FirmwareUpdate::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void FirmwareUpdate::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void FirmwareUpdate::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

