#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "DEVICE_ERROR.hpp"
#include "EMERGENCY_TEST.hpp"

class FIRMWARE_UPDATE : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    void transition(Context& ctx) override;
    const char* name() const override;

private:
};
