#include "DIAGNOSTIC"
#include "Context.hpp"
#include <iostream>

void DIAGNOSTIC::enter(Context& context) {
}
void DIAGNOSTIC::do(Context& context) {
}
void DIAGNOSTIC::exit(Context& context) {
}
void DIAGNOSTIC::transition(Context& context) {
}

const char* DIAGNOSTIC::name() const {
    return "DIAGNOSTIC";
}
