/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>  / for htons

void error(char *msg)
{
    printf("Error : %s", msg);
    exit(0);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
/*
	struct sockaddr_in {
	    short            sin_family;   // e.g. AF_INET, AF_INET6
	    unsigned short   sin_port;     // e.g. htons(3490)
	    struct in_addr   sin_addr;     // see struct in_addr, below
	    char             sin_zero[8];  // zero this if you want to
	};
*/
     int n;
     if (argc < 2) {
         printf("ERROR, no port provided\n");
//         exit(1);
	 return 0;
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);  //socket initiaised with AF_INET = ipv4, SOCK_STREAM = 2 way reliable conn.
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));  //byte-zero initialized as zero
     portno = atoi(argv[1]); 
     serv_addr.sin_family = AF_INET;  x
     serv_addr.sin_addr.s_addr = INADDR_ANY; 	//INADDR_ANY alows server to receive packets destined to any of the interfaces
/*
struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};
*/
     serv_addr.sin_port = htons(portno); //converts the unsigned short integer hostshort from host byte order to network byte order
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");	// assign a local socket address address to a socket identified by descriptor socket that has no local socket address assigned. 
     listen(sockfd,5);   		//II arg is the maximum length that the queue of pending connections may grow to. 
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     return 0; 
}

