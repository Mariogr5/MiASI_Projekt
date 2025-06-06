#pragma once
#include "State.hpp"
#include "NETWORK_CONFIGURATION.hpp"
#include "READY.hpp"

class DIAGNOSTIC : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;
};
