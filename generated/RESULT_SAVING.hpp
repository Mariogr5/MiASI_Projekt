#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "DEVICE_ERROR.hpp"
#include "DATA_TRANSMISSION.hpp"

class RESULT_SAVING : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;

private:
};
