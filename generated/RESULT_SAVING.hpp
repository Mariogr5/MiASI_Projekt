#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "DEVICE_ERROR.hpp"
#include "DATA_TRANSMISSION.hpp"

class RESULT_SAVING : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    void transition(Context& ctx) override;
    const char* name() const override;

private:
};
