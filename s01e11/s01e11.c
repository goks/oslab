#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
void signalHandler(int signal)
{
	printf("SIGCHLD acivated\n");
}

int main()
{
	signal(SIGCHLD,signalHandler);

	if (!fork()) {
		printf("Child running\n");
		sleep(2);
		printf("Child terminating\n");
		return 0;
	}
	else{
		printf("Parent running. PID=%d. Press ENTER to exit.\n",getpid());
		getchar();
		printf("Parent terminating\n");
		return 0;
	}
}
