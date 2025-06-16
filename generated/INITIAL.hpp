#pragma once
#include "State.hpp"
#include "Context.hpp"

// Initial State
class Initial : public State {
public:
	Initial() : State("INITIAL") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
