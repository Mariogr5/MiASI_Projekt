#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "FIRMWARE_UPDATE.hpp"
#include "SERVICE_MODE.hpp"
#include "MEASUREMENT.hpp"

// Device is read to work state. User could perform action using buttons (service_mode) 
class READY : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;

private:
    bool firmware_update_avaiable_guard(Context& context);
    void download_new_firmware(Context& context);
};
