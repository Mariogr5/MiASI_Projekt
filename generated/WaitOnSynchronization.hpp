#pragma once
#include "State.hpp"
#include "Context.hpp"

class WaitOnSynchronization : public State {
public:
	WaitOnSynchronization() : State("WAIT_ON_SYNCHRONIZATION") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
