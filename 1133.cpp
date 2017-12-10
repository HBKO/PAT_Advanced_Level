#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
    int value;
    int next;
};


struct node a[100001];


int main()
{

    int start,n,k;
//    cin>>start>>n>>k;
    scanf("%d %d %d",&start,&n,&k);
    for(int i=0;i<n;++i)
    {
        int address,value,next;
        scanf("%d %d %d",&address,&value,&next);
        a[address].value=value;
        a[address].next=next;
        
    }

    vector<int> v[3];
    while(start!=-1)
    {
        if(a[start].value<0)
        {
            v[0].push_back(start);
        }
        else if(a[start].value<=k)
        {
            v[1].push_back(start);
        }
        else
        {
            v[2].push_back(start);
        }
        start=a[start].next;
    }
    int flag=0;

    for(int i=0;i<3;++i)
    {
        for(int j=0;j<v[i].size();++j)
        {
            if(flag==0)
            {
                printf("%05d %d ",v[i][j],a[v[i][j]].value);
                flag=1;
            }
            else
            {
                printf("%05d\n%05d %d ",v[i][j],v[i][j],a[v[i][j]].value);
            }
        }
    }
    printf("-1");
    return 0;
}
