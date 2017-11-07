#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;



char cow[2005];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>cow[i];
    }

    int a=0,b=n-1,count=0;
    while(a<=b)
    {
        bool left=false;
        for(int i=0;a+i<=b;++i)
        {
            if(cow[a+i]<cow[b-i])
            {
                left=true;
                count++;
                break;
            }
            else if(cow[a+i]>cow[b-i])
            {
                left=false;
                count++;
                break;
            }
        }
        if(left) putchar(cow[a++]);
        else putchar(cow[b--]);
        if(count%80==0) cout<<endl;
    }
    cout<<endl;
    return 0;
}