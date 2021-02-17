
#ifndef _C_PURPURINA_PLATFORM_H_
#define _C_PURPURINA_PLATFORM_H_


#include <purpur/config/types.h>
#include <purpur/platform/export.h>


CPPR_PLATFORM_API p_bool ppr_platformInit();

CPPR_PLATFORM_API p_bool ppr_platformTerminate();

CPPR_PLATFORM_API void ppr_platformPollEvents();


#endif