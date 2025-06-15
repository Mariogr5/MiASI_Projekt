#include "ServiceMode.hpp"
#include <iostream>

void ServiceMode::enter(Context& context) { return; }

void ServiceMode::doActivity(Context& context) { return; }

void ServiceMode::exit(Context& context) { return; }

const char* ServiceMode::name() const {
    return "SERVICE_MODE";
}

