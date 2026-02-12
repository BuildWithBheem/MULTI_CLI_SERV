#include<stdio.h>

int main()
{

int a,b;
printf("A\n");

a = fork();

if(a == 0)
{

printf("B\n");
b=fork();

if(b == getppid())
{
printf("C\n");
}

}

}
