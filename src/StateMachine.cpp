#include "StateMachine.hpp"



const char* StateMachine::get_state_name()
{
    return getState()->name();
}

StateMachine::StateType* StateMachine::getState()
{
    if (!m_state) {
        while(1);
    }
    return m_state;
} // getState




StateMachine::StateMachine()
    : m_state(0)
    , m_state_changed(false)
{
}

void StateMachine::nextState(StateType& pNextState)
{
    StateMachine* sm = reinterpret_cast<StateMachine*>(this);
    StateType* oldState = m_state;

    if (oldState) {
        oldState->onExit(*sm);
    }
    m_state = &pNextState;
    m_state_changed = true;
    run(StateMachine& sm);
} // nextState

void StateMachine::run()
{
    if (!m_state) {
        return;
    }
    StateMachine* sm = reinterpret_cast<StateMachine*>(this);
    while (m_state_changed) {
        m_state_changed = false;
        m_state->onEnter(*sm);
    }
    // Always run the state.run to check the timer
    m_state->run(*sm);
}





void State::run(StateMachine& sm)
{
    onEvent(sm);
} // checkTimer

