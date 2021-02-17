
#ifndef _C_PURPURINA_OS_DETECTION_HPP_
#define _C_PURPURINA_OS_DETECTION_HPP_

    #if defined(_WIN32) || defined(__WIN32__)

        #define CPPR_OS_WINDOWS
        #define CPPR_OS_WIN32

    #elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)

        #define CPPR_OS_MACOS

    #elif defined(__linux__) || defined(__linux)

        #define CPPR_OS_LINUX

    #else
        // Unsupported system
        #error This operating system is not supported by Purpurina Framework
    #endif

#endif