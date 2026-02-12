#include<stdio.h>
#include<unistd.h>

int main()
{
fork();
p = fork();
if(p == 0)
{
	if(p > 0)
	{
		fork();
	}
}
}

