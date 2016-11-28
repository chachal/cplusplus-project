#ifndef STATEMACHINE_HPP_INCLUDED
#define STATEMACHINE_HPP_INCLUDED
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#ifdef FLAG_IMPLEMENT_NAME
#define STATE_IMPLEMENT_NAME_METHOD(xxmethod) \
    virtual const char* name() const \
    { \
        return #xxmethod; \
    }
#else
    #define STATE_IMPLEMENT_NAME_METHOD(xx)
#endif


class CTimeoutEvent {
public:
};


class StateMachine;

// Inherit state classes from this class
class State {
public:
    State();
    virtual const char* name() const = 0;

    virtual void onEnter(StateMachine& sm) = 0;
    virtual void onExit(StateMachine& sm) = 0;
    virtual void onEvent(StateMachine& sm, const CTimeoutEvent& event) = 0;

    void setTimer(int timeout);
    int m_start_time;
    int m_timeout;

    void run(StateMachine& sm);

}; // State





// Inherit state machines from this class
class StateMachine
{
public:
    typedef State StateType;

    virtual const char* name() = 0;
    const char* get_state_name();

private:
    StateType* m_state;
    bool m_state_changed;

protected:
    StateType* getState();

public:

    StateMachine();
    void nextState(StateType& pNextState);
    void run(); // check if there are events to send

}; // StateMachine



#endif // STATEMACHINE_HPP_INCLUDED
