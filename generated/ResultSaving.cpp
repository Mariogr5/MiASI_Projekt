#include "ResultSaving.hpp"
#include <iostream>

void ResultSaving::enter(Context& ctx) { 
	std::cout << "Entering state: " << name() << std::endl;
}

void ResultSaving::doActivity(Context& ctx) { 
	std::cout << "Executing no activity in state: " << name() << std::endl;
}

void ResultSaving::exit(Context& ctx) { 
	std::cout << "Exiting state: " << name() << std::endl;
}

