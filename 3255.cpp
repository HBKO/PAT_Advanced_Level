#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
typedef pair<int, int> P;   //first是最短距离,second是顶点的编号
typedef unsigned long long int ll;
#define INF 0xfffffff
struct edge
{
    int to,cost;
};
const int MAX_N=100001;

int N,R;
vector<edge> G[5005];

int dist[5005];
int dist2[5005];

bool mycomp(struct edge e1,struct edge e2)
{
    return e1.cost>e2.cost;
}


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
        struct edge tmp;
        int st;
        scanf("%d %d %d",&st,&tmp.to,&tmp.cost);
        G[st].push_back(tmp);
        swap(st,tmp.to);
        G[st].push_back(tmp);
    }
    priority_queue<P,vector<P>,greater<P> > que;
    dist[1]=0;
    que.push(P(0,1));

    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second,d=p.first;
        if(dist2[v]<d) continue;
        //更新邻近结点
        for(int i=0;i<G[v].size();++i)
        {
            edge &e=G[v][i];
            int d2=d+e.cost;
            if(dist[e.to]>d2)
            {
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
            }
            //更新次短距离
            if(dist2[e.to]>d2 && dist[e.to]<d2)
            {
                dist2[e.to]=d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
    printf("%d\n",dist2[N]);
    return 0;
}