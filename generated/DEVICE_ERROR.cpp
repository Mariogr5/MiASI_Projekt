#include "DEVICE_ERROR"
#include "Context.hpp"
#include <iostream>

void DEVICE_ERROR::enter(Context& context) {
}
void DEVICE_ERROR::do(Context& context) {
}
void DEVICE_ERROR::exit(Context& context) {
}
void DEVICE_ERROR::transition(Context& context) {
}

const char* DEVICE_ERROR::name() const {
    return "DEVICE_ERROR";
}
