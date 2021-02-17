
#include <purpur/platform/platform.hpp>

#include <purpur/platform/platform.h>

p_bool ppr_platformInit() {
    if (ppr::Platform::init()) {
        return p_true;
    }
    return p_false;
}

p_bool ppr_platformTerminate() {
    if (ppr::Platform::terminate()) {
        return p_true;
    }
    return p_false;
}

void ppr_platformPollEvents() {
    ppr::Platform::poll_events();
}
