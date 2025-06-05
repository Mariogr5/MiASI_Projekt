#pragma once
#include "State.hpp"

class EMERGENCY_RESET : public State {
public:
	void enter() override;
	void do() override;
	void exit() override;
	void transition(Context& context) override;
    const char* name() const override;
}
