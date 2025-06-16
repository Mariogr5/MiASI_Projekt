#pragma once
#include "State.hpp"
#include "Context.hpp"

class FirmwareUpdate : public State {
public:
	FirmwareUpdate() : State("FIRMWARE_UPDATE") {}
    void enter(Context& ctx) override;
    void doActivity(Context& ctx) override;
    void exit(Context& ctx) override;
};
