#pragma once
#include "State.hpp"
#include "EMERGENCY_TEST.hpp"

class DEVICE_ERROR : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;
};
