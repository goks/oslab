#include <stdio.h>

void waitFun() {
	
	int forkReturn = fork();

	//child process
	if(forkReturn == 0) {
		printf("child process 1. id : %d \n",getpid());
	}

	//parent process
	else {
		printf("parent process. id : %d \n",getpid());

		int status;

		int forkReturn2 = fork();
		
		//second child
		if(forkReturn2 == 0) {
			printf("child process 2. id : %d \n",getpid());
		}
		
		//parent process
		else {
			printf("parent process after creating 2 children \n");

			int idOfProcessEnded = wait(&status);
			printf("process Ended %d \n", idOfProcessEnded);
			int idOfProcessEnded2 = wait(&status);
			printf("process Ended %d\n", idOfProcessEnded2);
			
		}
		
	
	
	}


}
int main()
{
	/* code */
	waitFun();
	return 0;
}