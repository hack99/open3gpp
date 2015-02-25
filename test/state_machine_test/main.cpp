#include <cstdio>

#include "ue_state_machine.h"

int main() {
	UEStateMachine sm;

	printf("main() begin\n");
	sm.execute();
	sm.handleEvent(UE_EVENT_CONNECT);
	sm.handleEvent(UE_EVENT_RELEASE);
	printf("main() end\n");
	return 0;
}
