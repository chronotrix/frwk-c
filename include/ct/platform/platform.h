
#ifndef _C_CHRONOTRIX_PLATFORM_H_
#define _C_CHRONOTRIX_PLATFORM_H_


#include <ct/config/types.h>
#include <ct/platform/export.h>


CCT_PLATFORM_API ct_bool ct_platformInit();

CCT_PLATFORM_API ct_bool ct_platformTerminate();

CCT_PLATFORM_API void ct_platformPollEvents();


#endif