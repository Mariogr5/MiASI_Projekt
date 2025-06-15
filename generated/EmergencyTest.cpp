#include "EmergencyTest.hpp"
#include <iostream>

void EmergencyTest::enter(Context& context) { return; }

void EmergencyTest::doActivity(Context& context) { return; }

void EmergencyTest::exit(Context& context) { return; }

const char* EmergencyTest::name() const {
    return "EMERGENCY_TEST";
}

