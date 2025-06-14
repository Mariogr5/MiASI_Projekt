#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "SERVICE_MODE.hpp"
#include "FIRMWARE_UPDATE.hpp"
#include "MEASUREMENT.hpp"

// Device is read to work state. User could perform action using buttons (service_mode) 
class READY : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    void transition(Context& ctx) override;
    const char* name() const override;

private:
    bool firmware_update_available_guard(Context& context);
    void download_new_firmware(Context& context);
};
