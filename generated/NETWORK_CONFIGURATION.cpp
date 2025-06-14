#include "NETWORK_CONFIGURATION.hpp"
#include <iostream>

void NETWORK_CONFIGURATION::enter(Context& context) {
    std::cout << "Entering state: NETWORK_CONFIGURATION" << std::endl;
    network_configuration(context);
}

void NETWORK_CONFIGURATION::doActivity(Context& context) {
    std::cout << "Executing activity in state: NETWORK_CONFIGURATION" << std::endl;
    start_network_configuration(context);
}

void NETWORK_CONFIGURATION::exit(Context& context) {
    std::cout << "Exiting state: NETWORK_CONFIGURATION" << std::endl;
    save_network_ssid_password(context);
}

void NETWORK_CONFIGURATION::transition(Context& context) {
    context.setState(std::make_unique<WAIT_ON_SYNCHRONIZATION>());
    return;
    context.setState(std::make_unique<COMMUNICATION_ERROR>());
    return;
    std::cout << "No valid transition from state: NETWORK_CONFIGURATION" << std::endl;
}

const char* NETWORK_CONFIGURATION::name() const {
    return "NETWORK_CONFIGURATION";
}

void NETWORK_CONFIGURATION::network_configuration(Context& context) {
    std::cout << "Executing network_configuration" << std::endl;
}
void NETWORK_CONFIGURATION::start_network_configuration(Context& context) {
    std::cout << "Executing start_network_configuration" << std::endl;
}
void NETWORK_CONFIGURATION::save_network_ssid_password(Context& context) {
    std::cout << "Executing save_network_ssid_password" << std::endl;
}


