#include <stdio.h>

int main() {

	int processId = getpid();
	int parentPID = getppid();

	int realUserID = getuid();
	int groupID = getgid();

	int EUserID = geteuid();
	int EgroupID = getegid();

	printf("Process ID %d \n", processId);
	printf("Parent Process ID %d \n", parentPID );

	printf("Real user ID %d \n", realUserID );
	printf("Real Group ID %d \n", groupID );


	printf("Effective  user ID %d \n", EUserID );
	printf("Effective Group ID %d \n", EgroupID );


	return 0;
}
