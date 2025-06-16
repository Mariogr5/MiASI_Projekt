#include "CommunicationError.hpp"
#include <iostream>

void CommunicationError::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void CommunicationError::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void CommunicationError::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

