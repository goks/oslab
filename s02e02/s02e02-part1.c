#include<stdio.h>
void main()
{
	int fd;
	mkfifo("fifoforipc",0777);
	fd=open("fifoforipc",2);
	printf("Data sent to listener\n");
	write(fd,"Hello from sender",40);
}
