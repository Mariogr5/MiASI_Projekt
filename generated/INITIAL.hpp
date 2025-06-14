#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "DIAGNOSTIC.hpp"

// Initial State
class INITIAL : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    void transition(Context& ctx) override;
    const char* name() const override;

private:
    void init(Context& context);
    void Init_components(Context& context);
    void disable_initialization_functions(Context& context);
};
