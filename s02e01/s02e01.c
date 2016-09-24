#include<stdio.h>
int p1[2],p2[2];


void child(){
	int n1,n2;
	char buff[16];
	printf("\nChild process\n*************\nData to send: ");		
		scanf("%d",&n1);
		write(p1[1],&n1,sizeof(n1));

		read(p2[0],&n2,sizeof(n2));
		printf("\nChild process\n*************\nData from parent: %d\n",n2);

}
void parent(){
		int n1,n2;
		char buff[16];
		read(p1[0],&n1,sizeof(n1));
		printf("\nParent process\n**************\nData from Child: %d\n",n1);
		printf("\nData to send: ");
		scanf("%d",&n2);
		write(p2[1],&n2,sizeof(n2));
		
}
void main(){
	int k;	
	pipe(p1);
	pipe(p2);
	k=fork();
	if(k==0)
		child();
	else
		parent();
}
	
