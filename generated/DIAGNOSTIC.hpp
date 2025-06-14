#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "NETWORK_CONFIGURATION.hpp"
#include "READY.hpp"

class DIAGNOSTIC : public State {
public:
    void enter(Context& context) override;
    void doActivity(Context& context) override;
    void exit(Context& context) override;
    void transition(Context& context) override;
    const char* name() const override;

private:
    void Check_if_configuration_exists(Context& context);
    bool missing_configuration_guard(Context& context);
    bool check_configuration_guard(Context& context);
    void start_configuration(Context& context);
};
