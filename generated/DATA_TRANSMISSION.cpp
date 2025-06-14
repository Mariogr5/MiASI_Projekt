#include "DATA_TRANSMISSION.hpp"
#include <iostream>

void DATA_TRANSMISSION::enter(Context& context) {
    std::cout << "Entering state: DATA_TRANSMISSION" << std::endl;
}

void DATA_TRANSMISSION::doActivity(Context& context) {
    std::cout << "Executing activity in state: DATA_TRANSMISSION" << std::endl;
}

void DATA_TRANSMISSION::exit(Context& context) {
    std::cout << "Exiting state: DATA_TRANSMISSION" << std::endl;
}

void DATA_TRANSMISSION::transition(Context& context) {
    context.setState(std::make_unique<COMMUNICATION_ERROR>());
    return;
    context.setState(std::make_unique<READY>());
    return;
    std::cout << "No valid transition from state: DATA_TRANSMISSION" << std::endl;
}

const char* DATA_TRANSMISSION::name() const {
    return "DATA_TRANSMISSION";
}



