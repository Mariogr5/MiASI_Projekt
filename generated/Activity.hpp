#pragma once
#include "Context.hpp"

namespace Activity {
    void downloadNewFirmware(Context& ctx) { std::cout << "Doing activity: downloadNewFirmware" << std::endl; };
    void startConfiguration(Context& ctx) { std::cout << "Doing activity: startConfiguration" << std::endl; };
}
