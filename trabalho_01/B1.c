#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int exit_child = 0;
void change(int a) {exit_child = a;}
int main() {
	signal(SIGUSR1, change);
	signal(SIGUSR2, change);
	pause();
	if (!fork()) exit(0);
	pause();
	wait(0);
	pause();
	return 0;
}
