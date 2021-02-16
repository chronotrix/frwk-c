

// TODO

#if 0

    // windows export and import
    #define API_EXPORT extern "C" __declspec(dllexport)
    #define API_IMPORT PPR_EXTERN_C __declspec(dllimport)

    // turn off this annoying C4251 warning
    #ifdef _MSC_VER
        #pragma warning(disable : 4251)
    #endif

#else // Unix systems

    #if __GNUC__ >= 4

        // GCC 4 has special keywords for showing/hidding symbols,
        // the same keyword is used for both importing and exporting
        #define API_EXPORT extern "C" __attribute__ ((__visibility__ ("default")))
        #define API_IMPORT PPR_EXTERN_C __attribute__ ((__visibility__ ("default")))

    #else

        // GCC < 4 has no mechanism to explicitely hide symbols, everything's exported
        #define API_EXPORT extern "C"
        #define API_IMPORT PPR_EXTERN_C

    #endif

#endif