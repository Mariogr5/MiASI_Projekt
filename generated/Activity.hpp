#pragma once
#include "Context.hpp"

namespace Activity {
    void startConfiguration(Context& ctx) { std::cout << "Doing activity: startConfiguration" << std::endl; };
    void downloadNewFirmware(Context& ctx) { std::cout << "Doing activity: downloadNewFirmware" << std::endl; };
}
