#ifndef _STATE_BASE_H_
#define _STATE_BASE_H_

class StateBase {
public:
	StateBase(int stateId) : mStateId(stateId) {
	}

	virtual ~StateBase() {
	}

	virtual int enter() = 0;
	virtual int exit() = 0;

	inline const int getStateId() const { return mStateId; }
protected:
	const int mStateId;
};

#endif // _STATE_BASE_H_
