#pragma once
#include "State.hpp"
#include "Context.hpp"

class EmergencyReset : public State {
public:
	EmergencyReset() : State("EMERGENCY_RESET") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
