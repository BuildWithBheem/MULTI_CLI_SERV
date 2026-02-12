#include<stdio.h>
#include<unistd.h>

int main()
{
int p = fork();

if(p > 0)
{
	printf("Parent\n");
}

else if(p == 0)
{
	printf("Child\n");
}

else if(p == -1)
{
	printf("Error\n");
}
}
