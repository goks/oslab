#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

unsigned Count = 0; 

void mypause(int sign) {
alarm(2);
  signal(SIGALRM, mypause); 
  printf("\nAlive\n");
  signal(SIGINT, mypause);
  switch (sign) {
  case SIGINT:
    printf("\nPressed CTR-C\n");
    Count++;
    printf("You pressed CTR-C %d times", Count);
    break;
  case SIGQUIT:
    printf("\nPressed CTR-\\ \n");
    
 
    break;
  }
}

int main() {
  signal(SIGALRM, mypause);
  alarm(2);
  signal(SIGINT, mypause);
 signal(SIGQUIT, mypause);
  printf("\nWaiting for a signal\n");
  while (1) {}
  return (0);
}
