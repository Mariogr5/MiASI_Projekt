#pragma once
#include "State.hpp"
#include "Context.hpp"

class DataTransmission : public State {
public:
	DataTransmission() : State("DATA_TRANSMISSION") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
