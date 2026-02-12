#include<stdio.h>

int b = 1;
int main()
{
int a = 2;
a++;
fork();
printf("a=%d\n",a);
b++;
printf("b=%d\n",b);
}
