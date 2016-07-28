#include <stdio.h>



void piper(){
int pip[2];
          char buff[11];
          printf("------PIPING------");
          printf("\nForking\n" );
  
          int pipereturn = pipe(pip);          
          if(pipereturn != -1)
          {          	          
	         	
          	if(fork() == 0){
          	          // Chld process sends data to parent
          	          write(pip[1],"YO YO TINTU", 11);
          	          printf("WRITING DONE!");
          	}
          	else{
          	          //Parent process
          	          read(pip[0], buff, 11);
          	          printf("\n Value given to parent from child is: %s", buff);
          	          printf("\n");
          	}
	
          }
          else{
                    printf("\nPIPING ERROR");
          }
}
int main() {

       piper();   

}
