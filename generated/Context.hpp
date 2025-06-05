#pragma once
#include <memory>
#include <iostream>
#include "State.hpp"

class Context {
private:
    std::unique_ptr<State> currentState;

public:
    Context(std::unique_ptr<State> initialState)
        : currentState(std::move(initialState)) {}

    void setState(std::unique_ptr<State> newState) {
        currentState = std::move(newState);
    }

    void transition() {
        currentState->transition(*this);
    }

    void printState() const {
        std::cout << "Current state: " << currentState->name() << std::endl;
    }
};
