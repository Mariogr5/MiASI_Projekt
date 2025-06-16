#pragma once
#include "State.hpp"
#include "Context.hpp"

class NetworkConfiguration : public State {
public:
	NetworkConfiguration() : State("NETWORK_CONFIGURATION") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
