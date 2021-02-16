
typedef enum
{
    Borderless    = 0,       //< No border
    Title         = 1 << 0,  //< Title bar
    Resize        = 1 << 1,  //< Resizable box + maximize button
    Close         = 1 << 2,  //< Close button
    Default       = Title | Resize | Close ///< Default window style
} ppr_WindowStyle;