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

const int MAX=1000000;
const int INF=0x0fffffff;

struct edge G1[MAX];
struct edge G2[MAX];
int dist[MAX];
int N,ML,MD;


int main()
{
    scanf("%d %d %d",&N,&ML,&MD);
    //读取图数据
    for(int i=0;i<ML;++i)
    {
        int st,to,cost;
        scanf("%d %d %d",&st,&to,&cost);
        st--;to--;
        G1[i].st=st;G1[i].to=to;G1[i].cost=cost;
    }
    for(int i=0;i<MD;++i)
    {
        int st,to,cost;
        scanf("%d %d %d",&st,&to,&cost);
        st--;to--;
        G2[i].st=to;G2[i].to=st;G2[i].cost=-cost;
    }

    for(int i=0;i<N;++i) dist[i]=INF;
    dist[0]=0;
    for(int k=0;k<N;++k)
    {
        //从i+1到i的距离为0
        for(int i=0;i+1<N;++i)
        {
            if(dist[i+1]!=INF)  dist[i]=min(dist[i],dist[i+1]);
        }

        //得到所有数据并进行处理
        for(int i=0;i<ML;++i)
        {
            edge &e=G1[i];
            if(dist[e.st]!=INF) dist[e.to]=min(dist[e.to],dist[e.st]+e.cost);
        }
        for(int i=0;i<MD;++i)
        {
            edge &e=G2[i];
            if(dist[e.st]!=INF) dist[e.to]=min(dist[e.to],dist[e.st]+e.cost);
        }

    }   

    int res=dist[N-1];
    if(dist[0]<0)
    {
        res=-1;
    }   
    //没有到点N的最短距离（即没有到N的路径），所以可以随便摆 
    else if(dist[N-1]==INF)
    {
        res=-2;
    }
    printf("%d\n",res);
    return 0;
}