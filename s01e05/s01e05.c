#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
 
void child(char *path)
{
    int fd;
    char buf[] = "123456789";
 
    fd = open(path, O_WRONLY);
    write(fd, buf, sizeof(buf));
    printf("Child send: %s\n", buf);
    close(fd);
}
 
void parent(char *path)
{
    int fd;
    char buf[512];
 
    fd = open(path, O_RDONLY);
    read(fd, buf, sizeof(buf));
    printf("Parent receive: %s\n", buf);
    close(fd);
}
 
int main()
{
    char *path = "/tmp/fifo";
    int pid;
 
    //setlinebuf(stdout);
    unlink(path);
    mkfifo(path, 0600);
 
    pid = fork();
    if (pid == 0) {
        child(path);
    } else {
        parent(path);
    }
    return 0;
}
