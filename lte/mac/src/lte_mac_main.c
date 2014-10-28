#include <stdio.h>
#include "lte_mac_pdu.h"

int main() {
	lte_mac_header_nl_t h = {0};

	printf("sizeof(h)=%d\n", sizeof(h));

	h.r1 = 1;
	h.r2 = 1;
	h.e = 1;
	h.lcid = 5;

	printf("h=0x%02X\n", *(uint8*)&h);
	return 0;
}
