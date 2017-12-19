#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct edge
{
    int st;
    int to;
    int cost;
};

const int MAX=1000005;
const int MAX2=10005;
const int INF=0x0fffffff;
edge ML[MAX2];
edge MD[MAX2];
int N,M1,M2;

int dist[MAX2*2];


int main()
{
    scanf("%d %d %d",&N,&M1,&M2);
    for(int i=0;i<M1;++i)
    {
        int st,to,cost;
        scanf("%d %d %d",&st,&to,&cost);
        st--;to--;
        ML[i].st=st;
        ML[i].to=to;
        ML[i].cost=cost;
    }
    for(int i=0;i<M2;++i)
    {
        int st,to,cost;
        scanf("%d %d %d",&st,&to,&cost);
        st--;to--;
        cost=-cost;
        MD[i].st=to;
        MD[i].to=st;
        MD[i].cost=cost;
    }

    for(int i=0;i<N;++i)
    {
        dist[i]=INF;
    }

    dist[0]=0;
    //进行最短路径处理,从顶点出发到所有的点，复杂度为V*E,所以应该遍历更新所有的点
    for(int k=0;k<N;++k)
    {
        //dist[i+1]>=dist[i],牛按照大小顺序排列
        for(int i=0;(i+1)<N;++i)
        {
              if(dist[i+1]<INF)  dist[i]=min(dist[i],dist[i+1]);
        }
            
        //ML的牛的最大距离
        for(int i=0;i<M1;++i)
        {
            edge& e=ML[i];
            if(dist[e.st]<INF)
            {
                dist[e.to]=min(dist[e.to],dist[e.st]+e.cost);
            }
        }

        //MD的牛的最大距离
        for(int i=0;i<M2;++i)
        {
            edge& e=MD[i];
            if(dist[e.st]<INF)
            {
                dist[e.to]=min(dist[e.to],dist[e.st]+e.cost);
            }
        }
    }
    int res=dist[N-1];
    if(dist[0]<0)
    {
        //不可行 
        res=-1;
    }
    else if(res==INF)
    {
        res=-2;
    }
    printf("%d\n",res);
    return 0;
}