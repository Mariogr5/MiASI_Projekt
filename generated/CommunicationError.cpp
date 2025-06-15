#include "CommunicationError.hpp"
#include <iostream>

void CommunicationError::enter(Context& context) { return; }

void CommunicationError::doActivity(Context& context) { return; }

void CommunicationError::exit(Context& context) { return; }

const char* CommunicationError::name() const {
    return "COMMUNICATION_ERROR";
}

