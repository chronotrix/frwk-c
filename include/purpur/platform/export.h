
#ifndef _C_PURPURINA_PLATFORM_EXPORT_H_
#define _C_PURPURINA_PLATFORM_EXPORT_H_

    #include <purpur/config/api.h>

    #if defined(CPPR_PLATFORM_EXPORTS)

        #define CPPR_PLATFORM_API CPPR_API_EXPORT

    #else

        #define CPPR_PLATFORM_API CPPR_API_IMPORT

    #endif

#endif