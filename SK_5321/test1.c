#include<stdio.h>

int main()
{
printf("A\n");
fork();
printf("B %d -- %d\n",getpid(),getppid());
printf("C %d -- %d\n",getpid(),getppid());
}
