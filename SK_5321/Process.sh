#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("%d %d",getpid(),getppid());
	X = fork();
	if(X == 0)
		{
			printf("P3");
		}
	Y = fork();
	if(Y == 0)
		{
			printf("P2");
			if(fork() == 0)
				{
					printf("P4");
				}
			return 0;
		}
	printf("P1");

	return 0;
}
