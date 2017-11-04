#include<iostream>
#include<cmath>
#include<string.h>
#include<stack>
using namespace std;
int main()
{
    long a,b,c;
    scanf("%ld %ld",&a,&b);
    c=a+b;
    if(c<0)
    {
        printf("-");
        c=-c;
    }
    if(c==0) printf("0");
    stack<int> res;
    while(c)
    {
        res.push(c%10);
        c=c/10;
    }
    int flag=1;
    while(!res.empty())
    {
        int size=res.size();
        if(size%3==0 && flag!=1)
        {
            printf(",");
        }
        printf("%d",res.top());
        res.pop();
        flag=0;
    }
    return 0;
}