
#include <purpur/platform/window.hpp>

#include <purpur/platform/window.h>

struct pprWindow {
    ppr::WindowPtr ptr;
};

pprWindow* ppr_createWindowWithStyle(p_ui32 width, p_ui32 height, p_cstr title, p_ui32 style) {

    pprWindow * win = new pprWindow;

    win->ptr = ppr::create::window(width, height, title, style);

    return win;
}

p_bool ppr_windowIsVisible(const pprWindow* window) {
    if (window) {
        return window->ptr->isVisible() ? p_true : p_false;
    }
    return p_false;
}

void ppr_windowSetVisible(const pprWindow* window, p_bool visible) {
    if (window) {
        return window->ptr->setVisible((bool)visible);
    }
}

void ppr_destroyWindow(const pprWindow* window) {
    if (window) {
        delete window;
        window = nullptr;
    }
}