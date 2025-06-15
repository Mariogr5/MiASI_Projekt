#include "Ready.hpp"
#include <iostream>

void Ready::enter(Context& context) { return; }

void Ready::doActivity(Context& context) { return; }

void Ready::exit(Context& context) { return; }

const char* Ready::name() const {
    return "READY";
}

