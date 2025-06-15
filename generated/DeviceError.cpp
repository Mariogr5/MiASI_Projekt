#include "DeviceError.hpp"
#include <iostream>

void DeviceError::enter(Context& context) { return; }

void DeviceError::doActivity(Context& context) { return; }

void DeviceError::exit(Context& context) { return; }

const char* DeviceError::name() const {
    return "DEVICE_ERROR";
}

