#include <stdio.h>
#include <syscall.h>

DEFN_SYSCALL0(getuid, 23);
DEFN_SYSCALL0(reboot, 26);

int main(int argc, char ** argv) {
	printf("uid is %d\n", syscall_getuid());
	if (syscall_reboot() < 0) {
		printf("%s: need to be root.\n", argv[0]);
	}
	return 1;
}