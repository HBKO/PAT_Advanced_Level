#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N,M,R;
struct edge
{
    int st;
    int to;
    int cost;
};

const int MAX=50005;
const int MAX_1=50005;
struct edge G[MAX];
int par[MAX_1];
int Rank[MAX_1];

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
        return x;
    else
    {
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    else
    {
        if(Rank[x]>Rank[y])
        {
            par[y]=x;
        }
        else
        {
            par[x]=y;
            if(Rank[x]==Rank[y]) Rank[y]++;
        }
    }
}

int same(int x,int y)
{
    return find(x)==find(y);
}

bool mycomp(const edge& e1,const edge& e2)
{
    return e1.cost<e2.cost;
}

int kruskal(int e)
{
    int res=0;
    sort(G,G+e,mycomp);
    init(N+M);
    for(int i=0;i<e;++i)
    {
        //分别依照最小边构成最小生成树，并判断有没圈
        edge ed=G[i];
        if(!same(ed.st,ed.to))
        {
            unite(ed.st,ed.to);
            res+=ed.cost;
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
        
        scanf("%d %d %d",&N,&M,&R);
        for(int i=0;i<R;++i)
        {
            scanf("%d %d %d",&G[i].st,&G[i].to,&G[i].cost);
            G[i].cost=-G[i].cost;
            G[i].to=G[i].to+N;
        }
        printf("%d\n",10000*(N+M)+kruskal(R));
    }
    return 0;
}
