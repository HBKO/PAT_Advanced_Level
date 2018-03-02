#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;



int main()
{
    int n,num;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&num);
        int len=0,tmpnum=num;
        while(tmpnum!=0)
        {
            tmpnum=tmpnum/10;
            len++;
        }
        int d=pow(10,len/2);
        int a=num%d,b=num/d;
        if(a*b!=0 && num%(a*b)==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}