#include "WAIT_ON_SYNCHRONIZATION"
#include "Context.hpp"
#include <iostream>

void WAIT_ON_SYNCHRONIZATION::enter(Context& context) {
}
void WAIT_ON_SYNCHRONIZATION::do(Context& context) {
}
void WAIT_ON_SYNCHRONIZATION::exit(Context& context) {
}
void WAIT_ON_SYNCHRONIZATION::transition(Context& context) {
}

const char* WAIT_ON_SYNCHRONIZATION::name() const {
    return "WAIT_ON_SYNCHRONIZATION";
}
