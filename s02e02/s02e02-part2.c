#include<stdio.h>
void main()
{
	char buff[40];
	int fd=open("fifoforipc",2);
	read(fd,buff,40);
	write(1,buff,40);
}
