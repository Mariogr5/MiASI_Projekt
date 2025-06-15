#pragma once
#include "State.hpp"
#include "Context.hpp"

// Device is read to work state. User could perform action using buttons (service_mode) 
class Ready : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
    const char* name() const override;
};
