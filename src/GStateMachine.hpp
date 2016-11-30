#ifndef GSTATEMACHINE_HPP_INCLUDED
#define GSTATEMACHINE_HPP_INCLUDED
#include "StateMachine.hpp"
#include <string.h>


class GStateMachine: public StateMachine
{

    public:
        template <class EVENT>
        void onEvent(const EVENT& event) {
            BaseState* state = reinterpret_cast<BaseState*> (getState());
            state->onEvent(*this, event);
        }
        GStateMachine();

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
            virtual void onEnter();
            virtual void onEnter(StateMachine& sm);
            virtual void onExit(StateMachine& sm);
            virtual void onEvent(StateMachine& sm);
        }; // Initial
        friend class Initial;


    class LoadingThrow : public BaseState{
        public: 
            STATE_IMPLEMENT_NAME_METHOD(LoadingThrow);
            virtual void onEnter(StateMachine& sm);
            virtual void onEvent(StateMachine& sm);
            virtual void onExit(StateMachine& sm);

    }; // LoadingThrow    
        friend class LoadingThrow;


    class Paused : public BaseState{
        public: 
            STATE_IMPLEMENT_NAME_METHOD(Paused);
            virtual void onEnter(StateMachine& sm);
            virtual void onEvent(StateMachine& sm);
            virtual void onExit(StateMachine& sm);

    }; // LoadingThrow
        friend class Paused;

    class Load : public BaseState{
        public: 
            STATE_IMPLEMENT_NAME_METHOD(Load);
            virtual void onEnter(StateMachine& sm);
            virtual void onExit(StateMachine& sm);

    };
    friend class Load;
// ==================================================================
// State objects
// ==================================================================
public:
};




#endif // GSTATEMACHINE_HPP_INCLUDED
