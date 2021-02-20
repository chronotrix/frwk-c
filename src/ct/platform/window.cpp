
#include <ct/platform/window.hpp>

#include <ct/platform/window.h>

struct ctWindow {
    ct::WindowPtr ptr;
};

ctWindow* ct_createWindowWithStyle(ct_ui32 width, ct_ui32 height, ct_cstr title, ct_ui32 style) {

    ctWindow * win = new ctWindow;

    win->ptr = ct::create::window(width, height, title, style);

    return win;
}

ct_bool ct_windowIsVisible(const ctWindow* window) {
    if (window) {
        return window->ptr->isVisible() ? ct_true : ct_false;
    }
    return ct_false;
}

void ct_windowSetVisible(const ctWindow* window, ct_bool visible) {
    if (window) {
        return window->ptr->setVisible((bool)visible);
    }
}

void ct_destroyWindow(const ctWindow* window) {
    if (window) {
        delete window;
        window = nullptr;
    }
}