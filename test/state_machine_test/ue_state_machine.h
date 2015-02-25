#ifndef _UE_STATE_MACHINE_H_
#define _UE_STATE_MACHINE_H_

#include "idle_state.h"
#include "connect_state.h"
#include "state_machine_base.h"

enum UEEventType {
	UE_EVENT_CONNECT = 0,
	UE_EVENT_RELEASE,
	UE_EVENT_MAX,
};

enum UEStateType {
	UE_STATE_IDLE = 0,
	UE_STATE_CONNECT = 1,
	UE_STATE_MAX,
};

class UEStateMachine : public StateMachineBase {
public:
	UEStateMachine() :
		mIdleState(nullptr),
		mConnectState(nullptr) {
		printf("UEStateMachine()\n");

		mIdleState = new IdleState(UE_STATE_IDLE);
		mConnectState = new ConnectState(UE_STATE_CONNECT);

		setInitialState(mIdleState);
	}
	virtual ~UEStateMachine() {
		printf("~UEStateMachine()\n");
		if (mIdleState != nullptr) {
			delete mIdleState;
			mIdleState = nullptr;
		}
		if (mConnectState != nullptr) {
			delete mConnectState;
			mConnectState = nullptr;
		}
	}
	virtual int handleEvent(int ev) {
		printf("handleEvent(%d)\n", ev);
		int result = 0;
		switch (mCurrentState->getStateId()) {
		case UE_STATE_IDLE:
			printf("UE_STATE_IDLE\n");
			result = handleIdleEvent(ev);
			break;
		case UE_STATE_CONNECT:
			printf("UE_STATE_CONNECT\n");
			result = handleConnectEvent(ev);
			break;
		default:
			result = -1;
			break;
		}
		return result;
	}
	virtual int handleIdleEvent(int ev) {
		printf("handleIdleEvent(%d)\n", ev);
		switch (ev) {
		case UE_EVENT_CONNECT:
			assert(mCurrentState == mIdleState);
			mIdleState->exit();
			printf("UE_EVENT_CONNECT\n");
			mCurrentState = mConnectState;
			mConnectState->enter();
			break;
		default:
			break;
		}
		return 0;
	}
	virtual int handleConnectEvent(int ev) {
		printf("handleConnectEvent(%d)\n", ev);
		switch (ev) {
		case UE_EVENT_RELEASE:
			assert(mCurrentState == mConnectState);
			mConnectState->exit();
			printf("UE_EVENT_RELEASE\n");
			mCurrentState = mIdleState;
			mIdleState->enter();
			break;
		default:
			break;
		}
		return 0;
	}
protected:
	IdleState *mIdleState;
	ConnectState *mConnectState;
};

#endif // _UE_STATE_MACHINE_H_
