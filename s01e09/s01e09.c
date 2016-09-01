#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char **argv)
{
	if(argc != 2)
		return 1;

	struct stat fileStat;

    if(lstat(argv[1],&fileStat) < 0)    
        return 1;

    printf("The file %s is a ",argv[1]);

    switch (fileStat.st_mode & S_IFMT) 
    {
    	
    	case S_IFREG:  printf("regular file.\n");
					   break;
		case S_IFDIR:  printf("directory.\n");
					   break;
		case S_IFBLK:  printf("block special file.\n");
					   break;
		case S_IFCHR:  printf("character special file.\n");
					   break;		
		case S_IFIFO:  printf("FIFO file.\n");
					   break;
		case S_IFLNK:  printf("symbolic link.\n");
					   break;		
		case S_IFSOCK: printf("socket file.\n");
					   break;
		default: 	   printf("unknown file.\n");
	}

	
}
