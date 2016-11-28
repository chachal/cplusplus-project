#include "GStateMachine.hpp"
#include "StateMachine.hpp"
#include <iostream>
#include <string.h>

using namespace std;


void GStateMachine::Initial::onEnter(StateMachine& sm)
{
    StateMachine& gameState = reinterpret_cast<GStateMachine&>(sm);
};

void GStateMachine::Initial::onExit(StateMachine& sm)
{
    cout <<"-- INITIAL -- ONEXIT"<< endl;

};

void GStateMachine::Initial::onEvent(StateMachine& sm)
{
    GStateMachine& appsm = reinterpret_cast<GStateMachine&>(sm);

}
