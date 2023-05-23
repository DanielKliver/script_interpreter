#include<stdio.h>
int main()
{
float n;
scanf("%f", &n);
float min;
scanf("%f", &min);
double  i=0;
while(i < n )
{
float x;
scanf("%f", &x);
if(min > x )
{
 min = x;
}
 i = i + 1;
}
printf("%f",  i);
return 0;
}
