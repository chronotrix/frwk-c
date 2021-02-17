

#ifndef _C_PURPURINA_WINDOW_H_
#define _C_PURPURINA_WINDOW_H_


#include <purpur/config/types.h>
#include <purpur/platform/export.h>

/**
 * @brief Basic window style
 */
typedef enum
{
    p_Borderless    = 0,       //< No border
    p_Title         = 1 << 0,  //< Title bar
    p_Resize        = 1 << 1,  //< Resizable box + maximize button
    p_Close         = 1 << 2,  //< Close button
    p_Default       = p_Title | p_Resize | p_Close ///< Default window style
} pprWindowStyle;

/** @brief Window object.
 *
 *  @ingroup platform
 */
typedef struct pprWindow pprWindow;


CPPR_PLATFORM_API pprWindow* ppr_createWindowWithStyle(p_ui32 width, p_ui32 height, p_cstr title, p_ui32 style);

CPPR_PLATFORM_API p_bool ppr_windowIsVisible(const pprWindow* window);

CPPR_PLATFORM_API void ppr_windowSetVisible(const pprWindow* window, p_bool visible);

CPPR_PLATFORM_API void ppr_destroyWindow(const pprWindow * window);

#endif