#pragma once
#include "State.hpp"
#include "Context.hpp"

class ResultSaving : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    const char* name() const override;
};
