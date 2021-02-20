

#ifndef _C_CHRONOTRIX_WINDOW_H_
#define _C_CHRONOTRIX_WINDOW_H_


#include <ct/config/types.h>
#include <ct/platform/export.h>

/**
 * @brief Basic window style
 */
typedef enum
{
    ct_Borderless    = 0,       //< No border
    ct_Title         = 1 << 0,  //< Title bar
    ct_Resize        = 1 << 1,  //< Resizable box + maximize button
    ct_Close         = 1 << 2,  //< Close button
    ct_Default       = ct_Title | ct_Resize | ct_Close ///< Default window style
} ctWindowStyle;

/** @brief Window object.
 *
 *  @ingroup platform
 */
typedef struct ctWindow ctWindow;


CCT_PLATFORM_API ctWindow* ct_createWindowWithStyle(ct_ui32 width, ct_ui32 height, ct_cstr title, ct_ui32 style);

CCT_PLATFORM_API ct_bool ct_windowIsVisible(const ctWindow* window);

CCT_PLATFORM_API void ct_windowSetVisible(const ctWindow* window, ct_bool visible);

CCT_PLATFORM_API void ct_destroyWindow(const ctWindow * window);

#endif