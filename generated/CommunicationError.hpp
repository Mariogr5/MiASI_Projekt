#pragma once
#include "State.hpp"
#include "Context.hpp"

class CommunicationError : public State {
public:
	CommunicationError() : State("COMMUNICATION_ERROR") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
