#ifndef _CONNECT_STATE_H_
#define _CONNECT_STATE_H_

#include "state_base.h"

class ConnectState : public StateBase {
public:
	ConnectState(int stateId) : StateBase(stateId) {
		printf("ConnectState(%d)\n", stateId);
	}

	virtual ~ConnectState() {
		printf("~ConnectState()\n");
	}

	virtual int enter() {
		printf("enter ConnectState\n");
		return 0;
	}

	virtual int exit() {
		printf("exit ConnectState\n");
		return 0;
	}
};

#endif // _CONNECT_STATE_H_