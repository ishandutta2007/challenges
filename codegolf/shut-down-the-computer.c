/*

Challenge:

In the programming language of your choice, shut down the machine that your code was executed on.
Rules

    No shutting down by resource exhaustion (e.g.: forkbomb to force shutdown)
    You are allowed to write code that only works in a specific environment/OS, if you wish.
    Standard loopholes are forbidden

This is code-golf, thus the lowest amount of bytes wins!


*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>

enum {
	LINUX_REBOOT_MAGIC1 = 0xfee1dead,
	LINUX_REBOOT_MAGIC2 = 672274793,

	LINUX_REBOOT_CMD_POWER_OFF = 0x4321FEDC,
};

int
main(void)
{
	int cmd;

	cmd = LINUX_REBOOT_CMD_POWER_OFF;
	sync();
	if (syscall(__NR_reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, cmd, NULL) < 0)
		printf("%s\n", strerror(errno));

	return 0;
}
