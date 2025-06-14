#pragma once
#include <memory>
#include <iostream>
#include <chrono>
#include "State.hpp"

class Context {
private:
    std::unique_ptr<State> currentState;
    std::chrono::steady_clock::time_point stateStartTime;

    bool missing_configuration = false;
    bool firmware_update_avaiable = false;

public:
    Context(std::unique_ptr<State> initialState)
        : currentState(std::move(initialState)), stateStartTime(std::chrono::steady_clock::now()) {}

    void setState(std::unique_ptr<State> newState) {
        currentState = std::move(newState);
        stateStartTime = std::chrono::steady_clock::now();
    }

    void transition() {
        currentState->transition(*this);
    }

    void printState() const {
        std::cout << "Current state: " << currentState->name() << std::endl;
    }

    bool get_missing_configuration() const { return missing_configuration; }
    void set_missing_configuration(bool val) { missing_configuration = val; }

    bool get_firmware_update_available() const { return firmware_update_avaiable; }
    void set_firmware_update_available(bool val) { firmware_update_avaiable = val; }

    bool isTimeElapsed(int milliseconds) const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - stateStartTime).count() >= milliseconds;
    }
};
