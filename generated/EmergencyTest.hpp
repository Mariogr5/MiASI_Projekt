#pragma once
#include "State.hpp"
#include "Context.hpp"

class EmergencyTest : public State {
public:
	EmergencyTest() : State("EMERGENCY_TEST") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
