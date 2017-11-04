#include<iostream>
#include<string.h>
#include<cmath>
#include<stack>
using namespace std;
char Wordnumber[10][100]={"zero","one","two","three","four","five","six","seven","eight","nine"};


int main()
{
    char num[1000];
    while(scanf("%s",&num)!=EOF)
    {
        int sum=0;
        int size=strlen(num);
        for(int i=0;i<size;++i)
        {
            sum+=num[i]-'0';
        }
        if(sum==0)
        { 
            printf("%s\n",Wordnumber[0]);
            continue;
        }
        stack<int> res;
        while(sum)
        {
            res.push(sum%10);
            sum/=10;
        }
        while(!res.empty())
        {
            int number=res.top();
            if(res.size()!=1)
            {
                printf("%s ",Wordnumber[number]);
            }
            else
            {
                printf("%s\n",Wordnumber[number]);
            }
            res.pop();
        }
    }
    return 0;
}

