#ifndef _STATE_MACHINE_BASE_H_
#define _STATE_MACHINE_BASE_H_

#include <cassert>
#include "state_base.h"

class StateMachineBase {
public:
	StateMachineBase() : 
	  mCurrentState(nullptr),
	  mInitialState(nullptr) {
	}
	virtual ~StateMachineBase() {
	}
	virtual void setInitialState(StateBase* initialState) {
		assert(mInitialState == nullptr);
		mInitialState = initialState;
	}
	virtual int execute() {
		assert(mInitialState != nullptr);
		mCurrentState = mInitialState;
		mCurrentState->enter();
		return 0;
	}
	virtual int handleEvent(int ev) = 0;
protected:
	StateBase* mInitialState;
	StateBase* mCurrentState;
};

#endif // _STATE_MACHINE_BASE_H_
