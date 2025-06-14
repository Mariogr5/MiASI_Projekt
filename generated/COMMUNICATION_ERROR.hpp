#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "EMERGENCY_RESET.hpp"

class COMMUNICATION_ERROR : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;

private:
};
