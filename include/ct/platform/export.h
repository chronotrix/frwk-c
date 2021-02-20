
#ifndef _C_CHRONOTRIX_PLATFORM_EXPORT_H_
#define _C_CHRONOTRIX_PLATFORM_EXPORT_H_

    #include <ct/config/api.h>

    #if defined(CCT_PLATFORM_EXPORTS)

        #define CCT_PLATFORM_API CCT_API_EXPORT

    #else

        #define CCT_PLATFORM_API CCT_API_IMPORT

    #endif

#endif