/* PSPDX Abandoned Demo: a homebrew whose author doesn't take part.
 *
 * The same hello world as PSPDX Demo, published without a .pspdx: this
 * file, a Makefile that packs the four media files into the EBOOT, and a
 * release with the zip. The catalog lists it from its own listed/ folder.
 * The program itself prints a few lines and waits for the pad. */

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>

PSP_MODULE_INFO("PSPDX Abandoned Demo", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

/* The firmware asks the program to leave through a callback. Registering
 * one is what makes HOME work; without it the exit dialog says yes and
 * nothing happens. */
static int exit_callback(int arg1, int arg2, void *common)
{
	sceKernelExitGame();
	return 0;
}

/* The callback needs a thread that sleeps waiting for it, since the main
 * thread is busy with the pad. */
static int callback_thread(SceSize args, void *argp)
{
	int cb = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cb);
	sceKernelSleepThreadCB();
	return 0;
}

static void setup_callbacks(void)
{
	int thid = sceKernelCreateThread("update_thread", callback_thread, 0x11, 0xFA0, 0, 0);
	if (thid >= 0)
		sceKernelStartThread(thid, 0, 0);
}

int main(void)
{
	SceCtrlData pad;
	unsigned int last = 0;

	setup_callbacks();
	pspDebugScreenInit();

	pspDebugScreenPrintf("Hello, PSP.\n\n");
	pspDebugScreenPrintf("This is PSPDX Abandoned Demo:\n");
	pspDebugScreenPrintf("a release with the EBOOT, but no .pspdx.\n");
	pspDebugScreenPrintf("The catalog lists it anyway.\n\n");
	pspDebugScreenPrintf("X says hello again. HOME leaves.\n\n");

	/* sceCtrlReadBufferPositive waits for the next sample, so this loop
	 * runs once a frame. A press is the edge, not the held button. */
	for (;;) {
		sceCtrlReadBufferPositive(&pad, 1);
		if ((pad.Buttons & PSP_CTRL_CROSS) && !(last & PSP_CTRL_CROSS))
			pspDebugScreenPrintf("Hello again.\n");
		last = pad.Buttons;
	}

	return 0;
}
