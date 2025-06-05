#include "COMMUNICATION_ERROR"
#include "Context.hpp"
#include <iostream>

void COMMUNICATION_ERROR::enter(Context& context) {
}
void COMMUNICATION_ERROR::do(Context& context) {
}
void COMMUNICATION_ERROR::exit(Context& context) {
}
void COMMUNICATION_ERROR::transition(Context& context) {
}

const char* COMMUNICATION_ERROR::name() const {
    return "COMMUNICATION_ERROR";
}
