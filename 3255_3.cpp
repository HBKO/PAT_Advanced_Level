#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int > P;
struct edge
{
    int to;
    int cost;
};
const int INF=0x0fffffff;
const int MAX=5005;
vector<edge> G[MAX];
int dist[MAX];
int dist2[MAX];

int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    for(int i=0;i<=N;++i)
    {
        dist[i]=INF;
        dist2[i]=INF;
    }
    for(int i=0;i<R;++i)
    {
        struct edge e;
        int st;
        cin>>st>>e.to>>e.cost;
        G[st].push_back(e);
        swap(st,e.to);
        G[st].push_back(e);
    }
    priority_queue<P,vector<P>,greater<P> > que;
    dist[1]=0;
    que.push(P(1,0));
    while(!que.empty())
    {
        P p=que.top();que.pop();
        int c=p.second;int v=p.first;
        if(c>dist2[v]) continue;

        //更新距离
        for(int i=0;i<G[v].size();++i)
        {
            //每一个点计算距离
            edge& tmp=G[v][i];
            int newp=tmp.cost+c;
            //更新最短距离
            if(newp<dist[tmp.to])
            {
                swap(newp,dist[tmp.to]);
                que.push(P(tmp.to,dist[tmp.to]));
            }

            //更新次短距离
            if(newp<dist2[tmp.to] && newp>dist[tmp.to])
            {
                dist2[tmp.to]=newp;
                que.push(P(tmp.to,dist2[tmp.to]));
            }
        }
    }
    printf("%d\n",dist2[N]);
    return 0;
}
