#pragma once
#include "State.hpp"
#include "Context.hpp"

class ServiceMode : public State {
public:
	ServiceMode() : State("SERVICE_MODE") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
