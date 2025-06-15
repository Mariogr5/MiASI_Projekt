#include "Measurement.hpp"
#include <iostream>

void Measurement::enter(Context& context) { return; }

void Measurement::doActivity(Context& context) { return; }

void Measurement::exit(Context& context) { return; }

const char* Measurement::name() const {
    return "MEASUREMENT";
}

