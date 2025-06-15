#pragma once
#include "State.hpp"
#include "Context.hpp"

class CommunicationError : public State {
public:
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
