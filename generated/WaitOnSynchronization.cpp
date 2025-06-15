#include "WaitOnSynchronization.hpp"
#include <iostream>

void WaitOnSynchronization::enter(Context& context) { return; }

void WaitOnSynchronization::doActivity(Context& context) { return; }

void WaitOnSynchronization::exit(Context& context) { return; }

const char* WaitOnSynchronization::name() const {
    return "WAIT_ON_SYNCHRONIZATION";
}

