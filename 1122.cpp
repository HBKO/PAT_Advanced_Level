#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> G[1000];
int visit[1000];

int main()
{
    int V,E;
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;++i)
    {
        int s,t;
        scanf("%d %d",&s,&t);
        G[s].push_back(t);
        G[t].push_back(s);
    }
    int k;
    scanf("%d",&k);
    int flag=0;
    for(int i=0;i<k;++i)
    {
        flag=0;
        fill(visit,visit+1000,0);
        int m;
        scanf("%d",&m);
        vector<int> cycle;
        for(int j=0;j<m;++j)
        {
            int tmp;
            scanf("%d",&tmp);
            cycle.push_back(tmp);
        }
        visit[cycle[0]]=1;
        int j=1;
        for(j=1;j<cycle.size();++j)
        {
            int temp1=cycle[j-1];
            auto it=find((G[temp1]).begin(),(G[temp1]).end(),cycle[j]);
            if(it==G[temp1].end())
            {
                flag=1;
                break;
            }
            visit[cycle[j]]++;
        }
        if(flag==1 || visit[cycle[0]]!=2)
        {
            flag=1;
            printf("NO\n");
            continue;
        }
        for(int j=1;j<=V;++j)
        {
            if(j==cycle[0]) continue;
            if(visit[j]!=1)
            {
                flag=1;
            }
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
