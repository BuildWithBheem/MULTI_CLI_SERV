#include<stdio.h>

int main()
{

int a;
printf("A\n");

a = fork();

if(a == 0)
{
printf("B\n");
}
else
{
printf("C\n");
}

}

