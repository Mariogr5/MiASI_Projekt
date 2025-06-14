#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "COMMUNICATION_ERROR.hpp"
#include "READY.hpp"

class DATA_TRANSMISSION : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    void transition(Context& ctx) override;
    const char* name() const override;

private:
};
