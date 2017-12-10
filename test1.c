#include <stdio.h>

#define MAX(x,y) ((x) > (y)? (x):(y))
int main()
{
    int a=1;
    int b=2;
    printf("the number is %d\n",MAX(b,a));
    return 0;
}