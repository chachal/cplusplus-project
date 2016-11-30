#include "GStateMachine.hpp"
#include "StateMachine.hpp"
#include <iostream>
#include <string.h>

using namespace std;

GStateMachine::Initial GStateMachine::Initial_State;

void GStateMachine::Initial::onEnter()
{
	cout << "INITIAL -- ONENTER"<<endl;
    //Load map
};

void GStateMachine::Initial::onExit(StateMachine& sm)
{
    cout <<"-- INITIAL -- ONEXIT"<< endl;

};

void GStateMachine::Initial::onEvent(StateMachine& sm)
{
    GStateMachine& appsm = reinterpret_cast<GStateMachine&>(sm);

}


void GStateMachine::LoadingThrow::onEnter(StateMachine& sm){
    cout <<" LOADING THROW"<< endl;
    // mouse event

};


void GStateMachine::LoadingThrow::onEvent(StateMachine& sm){
	cout << " LOADING THROW ON EVENT"<<endl;
	// mouse event
};


void GStateMachine::LoadingThrow::onExit(StateMachine& sm){

};

void GStateMachine::Paused::onEvent(StateMachine& sm){

};

void GStateMachine::Load::onEvent(StateMachine& sm){



};