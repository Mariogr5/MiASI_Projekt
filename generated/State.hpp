#pragma once
#include "Context.hpp"

class State {
protected:
	const char *stateName;
public:
	explicit State(const char* _name) : stateName(_name) {}
    virtual ~State() = default;
    virtual void enter(Context &ctx) = 0;
    virtual void doActivity(Context &ctx) = 0;
    virtual void exit(Context &ctx) = 0;
    const char *name() const { return stateName; }
};

class PseudoState : public State {
public:
	PseudoState() : State("START") {}
	void enter(Context &ctx) override { return; }
	void doActivity(Context &ctx) override { return; }
	void exit(Context &ctx) override { return; }
};
