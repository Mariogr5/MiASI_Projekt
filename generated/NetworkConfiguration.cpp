#include "NetworkConfiguration.hpp"
#include <iostream>

void NetworkConfiguration::enter(Context& ctx) {
	std::cout << "Entering state: " << name() << std::endl;
    // Your code for NETWORK_CONFIGURATION goes here.
}

void NetworkConfiguration::doActivity(Context& context) {
	std::cout << "Executing activity in state: " << name() << std::endl;
    // Your code for START_NETWORK_CONFIGURATION goes here.
}

void NETWORK_CONFIGURATION::exit(Context& ctx) {
	std::cout << "Exiting state: " << name() << std::endl;
    // Your code for SAVE_NETWORK_SSID_PASSWORD goes here.
}

