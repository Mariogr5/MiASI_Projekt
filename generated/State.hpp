#pragma once
class Context;

class State {
public:
    virtual ~State() = default;
    virtual void enter() = 0;
    virtual void do() = 0;
    virtual void exit() = 0;
    virtual void transition(Context& context) = 0;
    virtual const char* name() const = 0;
};
