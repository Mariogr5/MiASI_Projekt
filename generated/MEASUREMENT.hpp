#pragma once
#include "State.hpp"
#include "RESULT_SAVING.hpp"

class MEASUREMENT : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;
};
