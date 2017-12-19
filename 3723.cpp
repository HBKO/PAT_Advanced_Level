#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//最短距离只需要存储相关边的信息
const int MAX=50005;

struct edge
{
    int st;
    int to;
    int cost;
};

struct edge G[MAX];
int par[MAX];
int Rank[MAX];


void init(int n)
{
    for(int i=0;i<n;++i)
    {
        par[i]=i;
        Rank[i]=0;
    }
}


int find(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    else
    {
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(Rank[x]<Rank[y])
    {
        par[x]=y;
    }
    else
    {
        par[y]=x;
        if(Rank[x]==Rank[y]) Rank[x]++;
    }
}


int same(int x,int y)
{
    return find(x)==find(y);
}

bool mycomp(edge e1,edge e2)
{
    return e1.cost<e2.cost;
}


int kruskal(int e,int v)
{
    int res=0;
    init(v);
    sort(G,G+e,mycomp);
    //处理每条边，添加到最小生成树中
    for(int i=0;i<e;++i)
    {
        edge& e=G[i];
        if(!same(e.st,e.to))
        {
            unite(e.st,e.to);
            res+=e.cost;
        }
    }
    return res;
}



int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int N,M,R;
        scanf("%d %d %d",&N,&M,&R);
        for(int i=0;i<R;++i)
        {
            int st,to,cost;
            scanf("%d %d %d",&st,&to,&cost);
            to+=N;
            cost=-cost;
            G[i].st=st;G[i].to=to;G[i].cost=cost;
        }
        printf("%d\n",10000*(N+M)+kruskal(R,(M+N)));
    }
    return 0;
}