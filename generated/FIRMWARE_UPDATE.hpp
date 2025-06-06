#pragma once
#include "State.hpp"
#include "EMERGENCY_TEST.hpp"
#include "DEVICE_ERROR.hpp"

class FIRMWARE_UPDATE : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;
};
