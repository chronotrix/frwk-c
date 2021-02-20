
#ifndef _C_CHRONOTRIX_OS_DETECTION_HPP_
#define _C_CHRONOTRIX_OS_DETECTION_HPP_

    #if defined(_WIN32) || defined(__WIN32__)

        #define CCT_OS_WINDOWS
        #define CCT_OS_WIN32

    #elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)

        #define CCT_OS_MACOS

    #elif defined(__linux__) || defined(__linux)

        #define CCT_OS_LINUX

    #else
        // Unsupported system
        #error This operating system is not supported by Chronotrix Framework
    #endif

#endif