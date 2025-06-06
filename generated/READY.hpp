#pragma once
#include "State.hpp"
#include "SERVICE_MODE.hpp"
#include "FIRMWARE_UPDATE.hpp"
#include "MEASUREMENT.hpp"

class READY : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;
};
