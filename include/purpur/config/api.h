
#ifndef _C_PURPURINA_API_HPP_
#define _C_PURPURINA_API_HPP_

    #include <purpur/config/os_detection.h>

    // extern "C"
    #ifdef __cplusplus
        #define CPPR_EXTERN_C extern "C"
    #else
        #define CPPR_EXTERN_C extern
    #endif


    #ifdef CPPR_OS_WINDOWS

        // export and import
        #define CPPR_API_EXPORT extern "C" __declspec(dllexport)
        #define CPPR_API_IMPORT CPPR_EXTERN_C __declspec(dllimport)

        // turn off this annoying C4251 warning
        #ifdef _MSC_VER
            #pragma warning(disable : 4251)
        #endif

    #else // Unix systems

        #if __GNUC__ >= 4

            // GCC 4 has special keywords for showing/hidding symbols,
            // the same keyword is used for both importing and exporting
            #define API_EXPORT extern "C" __attribute__ ((__visibility__ ("default")))
            #define API_IMPORT CPPR_EXTERN_C __attribute__ ((__visibility__ ("default")))

        #else

            // GCC < 4 has no mechanism to explicitely hide symbols
            #define API_EXPORT extern "C"
            #define API_IMPORT CPPR_EXTERN_C

        #endif

    #endif

#endif