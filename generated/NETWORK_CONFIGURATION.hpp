#pragma once
#include "State.hpp"
#include "COMMUNICATION_ERROR.hpp"
#include "WAIT_ON_SYNCHRONIZATION.hpp"

class NETWORK_CONFIGURATION : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;
};
