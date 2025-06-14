#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "COMMUNICATION_ERROR.hpp"
#include "READY.hpp"

class WAIT_ON_SYNCHRONIZATION : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;

private:
};
