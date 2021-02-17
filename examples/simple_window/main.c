
#include <stdio.h>

#include <purpur/platform/platform.h>
#include <purpur/platform/window.h>

int main(int argc, const char* argv[])
{
	if (!ppr_platformInit()) {
		printf("Could not start platform correctly.");
		return 1;
	}

	pprWindow* window = ppr_createWindowWithStyle(800, 600, "My C Purpurina Window", p_Default);

	ppr_windowSetVisible(window, p_true);

	while (ppr_windowIsVisible(window)) {
		ppr_platformPollEvents();
	}

	if (!ppr_platformTerminate()) {
		return 1;
	}
	return 0;
}