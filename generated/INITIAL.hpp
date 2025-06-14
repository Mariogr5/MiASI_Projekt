#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "DIAGNOSTIC.hpp"

// Initial State
class INITIAL : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;

private:
    void init(Context& context);
    void Init_components(Context& context);
    void disable_initialization_functions(Context& context);
};
