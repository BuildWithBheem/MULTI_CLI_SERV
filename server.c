#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error (const char *msg) // Common error message
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]) // For command line arguments
{
	if(argc < 2) // Arguments shouldn´t be less than 2
	{
		fprintf(stderr,"Port Number not specified");
		exit(1);
	}
	int sockfd, newsockfd, portno, n;
	char buffer[300]; // Buffer to send 
	
	struct sockaddr_in serv, cli; //Internet address
	socklen_t cl_len;
	
	sockfd = socket (AF_INET, SOCK_STREAM,0);
	
	if(sockfd < 0)
	{
		error("Error Opening the socket !");
	} 
	
	portno = atoi(argv[1]);
	
	serv.sin_family = AF_INET; 
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons(portno);
	
	if(bind(sockfd, (struct sockaddr *) &serv, sizeof(serv)) < 0 )
	{
		error("Binding failed");
	}
	
	listen(sockfd, 5);
	cl_len = sizeof(cli);
	
	newsockfd = accept(sockfd, (struct sockaddr *) &cli, &cl_len);
	
	if(newsockfd < 0 )
	{
		error("Cant accept");
	}
	int pid = fork();
	if(pid < 0)
	error("Fork fail");
	
	if(pid == 0) //Child 
	{
	close(sockfd); //Only parent is used for new connections
	
	while(1)
	{
		bzero(buffer, 300); //Store message
		
		n = read(newsockfd, buffer, 300);
		
		if(n<0)
		{
		error("Error on reading");
		}
		printf("Client : %s\n",buffer);
		
		bzero(buffer, 300);
		fgets(buffer, 300, stdin); //Reply from server
		
		n = write(newsockfd, buffer, strlen(buffer)); //Posts it over network
		
		if(n<0)
		{
		error("Error on writing");
		}
		
		int i = strncmp("Bye", buffer, 3);
		
		if(i == 0) //End convo if Bye is written
		break;
	}
	
	close(newsockfd);
	exit(0);
	}
	else 
	{
	close(newsockfd);
	}
	return 0;
}
