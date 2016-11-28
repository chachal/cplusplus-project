#ifndef GSTATEMACHINE_HPP_INCLUDED
#define GSTATEMACHINE_HPP_INCLUDED
#include "StateMachine.hpp"
#include <string.h>


class GStateMachine: public StateMachine{

    public:
        template <class EVENT>
        void onEvent(const EVENT& event) {
            BaseState* state = reinterpret_cast<BaseState*> (getState());
            state->onEvent(*this, event);
        }

    private:
// ==================================================================
// Base class for all states
// ==================================================================

        class BaseState: public StateType {
        public:

            virtual void onEnter(StateMachine& sm);
            virtual void onExit(StateMachine& sm);
            virtual void onEvent(StateMachine& sm);

        }; // BaseState
        friend class BaseState;

    class Initial : public BaseState {
        public:
            STATE_IMPLEMENT_NAME_METHOD(Initial);
            virtual void onEnter(StateMachine& sm);
            virtual void onExit(StateMachine& sm);
            virtual void onEvent(StateMachine& sm);
        }; // Initial
        friend class Initial;

// ==================================================================
// State objects
// ==================================================================
public:

};





#endif // GSTATEMACHINE_HPP_INCLUDED
