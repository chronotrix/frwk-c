
#ifndef _C_PURPURINA_TYPES_HPP_
#define _C_PURPURINA_TYPES_HPP_

    // 8 bits integer types
    typedef signed   char p_i8;
    typedef unsigned char p_ui8;

    // 16 bits integer types
    typedef signed   short p_i16;
    typedef unsigned short p_ui16;

    // 32 bits integer types
    typedef signed   int p_i32;
    typedef unsigned int p_ui32;

    // 64 bits integer types
    #if defined(_MSC_VER)
        typedef signed   __int64 p_i64;
        typedef unsigned __int64 p_ui64;
    #else
        typedef signed   long long p_i64;
        typedef unsigned long long p_ui64;
    #endif

    typedef const char * p_cstr;

    typedef int p_bool;

    #define p_false 0
    #define p_true 1

#endif