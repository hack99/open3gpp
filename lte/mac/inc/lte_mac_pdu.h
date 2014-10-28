#ifndef _LTE_MAC_PDU_H_
#define _LTE_MAC_PDU_H_

#include "common_define.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#pragma pack(push, 1)
typedef struct _lte_mac_header_l7_t {
	uint8 lcid:5;
	uint8 e:1;
	uint8 r2:1;
	uint8 r1:1;
	uint8 l:7;
	uint8 f:1;
} lte_mac_header_l7_t;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct _lte_mac_header_l15_t {
	uint8 lcid:5;
	uint8 e:1;
	uint8 r2:1;
	uint8 r1:1;
	uint8 l1:7;
	uint8 f:1;
	uint8 l2;
} lte_mac_header_l15_t;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct _lte_mac_header_nl_t {
	uint8 lcid:5;
	uint8 e:1;
	uint8 r2:1;
	uint8 r1:1;
} lte_mac_header_nl_t;
#pragma pack(pop)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _LTE_MAC_PDU_H_