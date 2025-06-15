#include "EmergencyReset.hpp"
#include <iostream>

void EmergencyReset::enter(Context& context) { return; }

void EmergencyReset::doActivity(Context& context) { return; }

void EmergencyReset::exit(Context& context) { return; }

const char* EmergencyReset::name() const {
    return "EMERGENCY_RESET";
}

