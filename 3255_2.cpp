#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct edge
{
    int to;
    int cost;
};

typedef pair<int,int> P;        //first是cost，second是坐标点

#define INF 1e9
const int MAX=5005;

int dist[MAX];
int dist2[MAX];

int N,R;

vector<edge> G[MAX];

int main()
{
    scanf("%d %d",&N,&R);
    for(int i=0;i<=N;++i)
    {
        dist[i]=INF;
        dist2[i]=INF;
    }
    for(int i=0;i<R;++i)
    {
        int st;
        struct edge e;
        scanf("%d %d %d",&st,&e.to,&e.cost);
        G[st].push_back(e);
        swap(st,e.to);
        G[st].push_back(e);
    }
    //设置优先队列来执行dijstra
    priority_queue<P,vector<P>,greater<P> > que;
    dist[1]=0;
    que.push(P(0,1));
    while(!que.empty())
    {
        P p=que.top();que.pop();
        int c=p.first;int v=p.second;
        if(dist2[v]<c) continue;
        //更新所有的周围结点
        for(int i=0;i<G[v].size();++i)
        {
            edge &e=G[v][i];
            int nc=c+e.cost;
            //更新
            if(nc<dist[e.to])
            {
                swap(dist[e.to],nc);
                que.push(P(dist[e.to],e.to));
            }

            //更新次短距离
            if(dist2[e.to]>nc && dist[e.to]<nc)
            {
                dist2[e.to]=nc;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
    printf("%d\n",dist2[N]);
    return 0;
}