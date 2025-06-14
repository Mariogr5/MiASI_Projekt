#pragma once
#include "State.hpp"
#include "Context.hpp"
#include "WAIT_ON_SYNCHRONIZATION.hpp"
#include "COMMUNICATION_ERROR.hpp"

class NETWORK_CONFIGURATION : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    void transition(Context& ctx) override;
    const char* name() const override;

private:
    void network_configuration(Context& context);
    void start_network_configuration(Context& context);
    void save_network_ssid_password(Context& context);
};
