
#include <stdio.h>

#include <ct/platform/platform.h>
#include <ct/platform/window.h>

int main(int argc, const char* argv[])
{
	if (!ct_platformInit()) {
		printf("Could not start platform correctly.");
		return 1;
	}

	ctWindow* window = ct_createWindowWithStyle(800, 600, "My C Chronotrix Window", ct_Default);

	ct_windowSetVisible(window, ct_true);

	while (ct_windowIsVisible(window)) {
		ct_platformPollEvents();
	}

	if (!ct_platformTerminate()) {
		return 1;
	}
	return 0;
}