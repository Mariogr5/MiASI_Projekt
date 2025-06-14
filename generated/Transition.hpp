#pragma once
#include "Context.hpp"
#include "Event.hpp"
#include "State.hpp"

class Transition {
public:
	State *from;
	State *to;
	Event trigger;
	bool (*guard)(Context&);
	void (*activity)(Context&);
	
	~Transition() = default;
	Transition(State *_from, State *_to, Event _trigger = Event::NONE_EVENT, bool (*_guard)(Context&) = nullptr), void (*_activity(Context&) = nullptr
        : from(_from), to(_to), trigger(_trigger), guard(_guard), activity(_activity) {}
};
