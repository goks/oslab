#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
int main ( int argc, char *argv[])
{
	struct stat filesun;
	if(argc != 2)
		return -1;

	if (stat(argv[(1)], &filesun) < 0)
		return -1;
	printf( "Permissions: " );
	printf( (S_ISDIR(filesun.st_mode)) ? "d" : "-");
	printf( (filesun.st_mode & S_IRUSR) ? "r" : "-");
	printf( (filesun.st_mode & S_IWUSR) ? "w" : "-");
	printf( (filesun.st_mode & S_IXUSR) ? "x" : "-");
	printf( (filesun.st_mode & S_IRGRP) ? "r" : "-");
	printf( (filesun.st_mode & S_IWGRP) ? "w" : "-");
	printf( (filesun.st_mode & S_IXGRP) ? "x" : "-");
	printf( (filesun.st_mode & S_IROTH) ? "r" : "-");
	printf( (filesun.st_mode & S_IWOTH) ? "w" : "-");
	printf( (filesun.st_mode & S_IXOTH) ? "x" : "-");
	printf("\nI node number: %d ",filesun.st_ino );
	printf("Time of last file access: %s",asctime(localtime(&filesun.st_atime)) );
	printf("Time of last file modification: %s",asctime(localtime(&filesun.st_mtime)) );
	printf("File size: %d bytes\n",filesun.st_size );

	return 0;
}
