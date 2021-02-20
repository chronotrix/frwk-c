
#ifndef _C_CHRONOTRIX_TYPES_HPP_
#define _C_CHRONOTRIX_TYPES_HPP_

    // 8 bits integer types
    typedef signed   char ct_i8;
    typedef unsigned char ct_ui8;

    // 16 bits integer types
    typedef signed   short ct_i16;
    typedef unsigned short ct_ui16;

    // 32 bits integer types
    typedef signed   int ct_i32;
    typedef unsigned int ct_ui32;

    // 64 bits integer types
    #if defined(_MSC_VER)
        typedef signed   __int64 ct_i64;
        typedef unsigned __int64 ct_ui64;
    #else
        typedef signed   long long ct_i64;
        typedef unsigned long long ct_ui64;
    #endif

    typedef const char * ct_cstr;

    typedef int ct_bool;

    #define ct_false 0
    #define ct_true 1

#endif