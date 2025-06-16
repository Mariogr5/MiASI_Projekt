#pragma once
#include "State.hpp"
#include "Context.hpp"

class ResultSaving : public State {
public:
	ResultSaving() : State("RESULT_SAVING") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
