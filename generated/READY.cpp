#include "READY.hpp"
#include <iostream>

void READY::enter(Context& context) {
    std::cout << "Entering state: READY" << std::endl;
}

void READY::doActivity(Context& context) {
    std::cout << "Executing activity in state: READY" << std::endl;
}

void READY::exit(Context& context) {
    std::cout << "Exiting state: READY" << std::endl;
}

void READY::transition(Context& context) {
    context.setState(std::make_unique<MEASUREMENT>());
    return;
    std::cout << "Event: service_command" << std::endl;
    context.setState(std::make_unique<SERVICE_MODE>());
    return;
    std::cout << "Event: Firmware_update_avaliable" << std::endl;
    // Checking if firmware update is avaiable
    if (firmware_update_available_guard(context)) {
    	download_new_firmware(context);
	    context.setState(std::make_unique<FIRMWARE_UPDATE>());
	    return;
    }
    std::cout << "No valid transition from state: READY" << std::endl;
}

const char* READY::name() const {
    return "READY";
}


bool READY::firmware_update_available_guard(Context& context) {
    return context.get_firmware_update_available() == true;
}

void READY::download_new_firmware(Context& context) {
    std::cout << "Executing effect download_new_firmware" << std::endl;
}
