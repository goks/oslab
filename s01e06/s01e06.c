#include<stdio.h>
void main()
{
	printf("Hello from outer prgm %d\n",getpid());	
	int d=execl("pathforexecl/hello",0);
	printf("Error in execl");
}
		

