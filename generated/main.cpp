#include <iostream>
#include "StateMachine.hpp"

int main() {
    StateMachine sm;
    std::cout << "Initial state: " << sm.state->name() << "\n";

	// START -> INITIAL
    int rc = sm.execute(Event::NONE_EVENT);
    std::cout << "RC: " << rc << std::endl;

    return 0;
}
