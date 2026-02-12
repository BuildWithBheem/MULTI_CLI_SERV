#include<stdio.h>
#include<unistd.h>

int main()
{
        printf("%d \n %d \n",getpid(),getppid());
       int X = fork();
        if(X == 0)
                {
                        printf("P3\n");
                }
       int Y = fork();
        if(Y == 0)
                {
                        printf("P2\n");
                        if(fork() == 0)
                                {
                                        printf("P4\n");
                                }
                        return 0;
                }
        printf("P1\n");

        return 0;
}
