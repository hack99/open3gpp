#ifndef _LOG_MANAGER_H_
#define _LOG_MANAGER_H_

#include "common_define.h"

#define LOG_FATAL_PREFIX(format) \
	__FILE__"(%d)[F] : " format "\n", __LINE__, 

#define LOG_ERROR_PREFIX(format) \
	__FILE__"(%d)[E] : " format "\n", __LINE__, 

#define LOG_DEBUG_PREFIX(format) \
	__FILE__"(%d)[D] : " format "\n", __LINE__, 

#define LOG_FATAL(format,...) \
	printf(LOG_FATAL_PREFIX(format) ##__VA_ARGS__)

#define LOG_ERROR(format,...) \
	printf(LOG_ERROR_PREFIX(format) ##__VA_ARGS__)

#define LOG_DEBUG(format,...) \
	printf(LOG_DEBUG_PREFIX(format) ##__VA_ARGS__)

#endif // _LOG_MANAGER_H_
