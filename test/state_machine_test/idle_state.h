#ifndef _IDLE_STATE_H_
#define _IDLE_STATE_H_

#include "state_base.h"

class IdleState : public StateBase {
public:
	IdleState(int stateId) : StateBase(stateId) {
		printf("IdleState(%d)\n", stateId);
	}
	virtual ~IdleState() {
		printf("~IdleState()\n");
	}

	virtual int enter() {
		printf("enter IdleState\n");
		return 0;
	}

	virtual int exit() {
		printf("exit IdleState\n");
		return 0;
	}
};

#endif // _IDLE_STATE_H_
