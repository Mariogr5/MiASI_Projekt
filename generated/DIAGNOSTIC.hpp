#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "NETWORK_CONFIGURATION.hpp"
#include "READY.hpp"

class DIAGNOSTIC : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    void transition(Context& ctx) override;
    const char* name() const override;

private:
    void Check_if_configuration_exists(Context& context);
    bool missing_configuration_guard(Context& context);
    bool check_configuration_guard(Context& context);
    void start_configuration(Context& context);
};
