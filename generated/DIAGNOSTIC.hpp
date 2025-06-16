#pragma once
#include "State.hpp"
#include "Context.hpp"

class Diagnostic : public State {
public:
	Diagnostic() : State("DIAGNOSTIC") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
