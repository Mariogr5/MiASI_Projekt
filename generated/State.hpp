#pragma once

class State {
protected:
	const char *name;
public:
	explicit State(const char* _name) : name(_name) {}
    virtual ~State() = default;
    virtual void enter(Context &ctx) = 0;
    virtual void doActivity(Context &ctx) = 0;
    virtual void exit(Context &ctx) = 0;
    const char *name() const { return name; }
};

class PseudoState : public State {
public:
	void enter(Context &ctx) override { return; }
	void doActivity(Context &ctx) override { return; }
	void exit(Context &ctx) override { return; }
};
