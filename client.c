#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>


void error(const char *msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
	int sockfd,portno,n;
	
	struct sockaddr_in serve; //Address of server
	struct hostent *server; //Hostname
	
	char buffer[300];
	
	if(argc < 3)
	{
	fprintf(stderr,"hostname port %s",argv[0]);
	exit(0);
	}
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0 )
	{
	error("ERROR socket");
	}
	
	server  = gethostbyname(argv[1]);
	if(server == NULL)
	{
		fprintf(stderr, "Error"); //If user provides incorrect info 
	}
	
	bzero((char*) &serve, sizeof(serve));
	serve.sin_family = AF_INET;
	bcopy((char *) server ->h_addr, (char *) &serve.sin_addr.s_addr, server ->h_length); //Transfers info from *server to serve
	serve.sin_port = htons(portno);
	
	if(connect(sockfd, (struct sockaddr *) &serve, sizeof(serve)) < 0)
	{
		error("Connection failed");
	}
	
	while(1)
	{
	bzero(buffer, 300);
	fgets(buffer, 300, stdin);
	n = write(sockfd, buffer, strlen(buffer));
	
	if(n<0)
	{
		error("Writing error");
	}
	
	bzero(buffer , 300); //clear for client to take the string from server
	n = read(sockfd, buffer, 300);
	if(n<0)
	{
		error("Error Reading");
	}
	
	printf("Server %s", buffer); 
	
	int i = strncmp("Bye", buffer, 3);
		
		if(i == 0) //End convo if Bye is written
		break;
	}
	close(sockfd);
	return 0;
}
