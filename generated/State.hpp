#pragma once
class Context;

class State {
public:
    virtual ~State() = default;
    virtual void enter(Context& context) = 0;
    virtual void doActivity(Context& context) = 0;
    virtual void exit(Context& context) = 0;
    virtual void transition(Context& context) = 0;
    virtual const char* name() const = 0;
};
