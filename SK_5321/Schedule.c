#include<stdio.h>

struct Process
{
int at,bt,TAT,RT,WT;
};

int main()
{
struct Process p1,p2,p3;

p1.at = 0;
p2.at = 5;
p3.at = 9;
p1.bt = 20;
p2.bt = 8;
p3.bt = 13;

p1.TAT = p1.bt - p1.at;
p2.TAT = p2.bt - p1.at;
p3.TAT = p3.bt - p3.at;

p1.WT = p1.TAT - p1.bt;
p2.WT = p2.TAT - p2.bt;
p3.WT = p3.TAT - p3.bt;

p1.RT = p1.WT;
p2.RT = p2.WT;
p3.RT = p3.WT;

printf("P1 : TAT = %d, WT = %d, RT = %d \n",p1.TAT,p1.WT,p1.RT);
printf("P2 : TAT = %d, WT = %d, RT = %d \n",p2.TAT,p2.WT,p2.RT);
printf("P3 : TAT = %d, WT = %d, RT = %d \n",p3.TAT,p3.WT,p3.RT);
}
