
#include <ct/platform/platform.hpp>

#include <ct/platform/platform.h>

ct_bool ct_platformInit() {
    if (ct::Platform::init()) {
        return ct_true;
    }
    return ct_false;
}

ct_bool ct_platformTerminate() {
    if (ct::Platform::terminate()) {
        return ct_true;
    }
    return ct_false;
}

void ct_platformPollEvents() {
    ct::Platform::poll_events();
}
