#include <iostream>
#include <cstdio>
using namespace std;

int N,R;
const int MAX_N=50002*3;
const int MAX_K=100005;

int par[MAX_N];
int Rank[MAX_N];

int T[MAX_K];
int X[MAX_K];
int Y[MAX_K];

//初始化n个元素
void init(int n)
{
    for(int i=0;i<n;++i)
    {
        par[i]=i;
    }
}

//查找对应的元素
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

//合并
void unite(int x, int y)
{
    x=find(x);
    y=find(y);

    if(x==y) return;
    
    if(Rank[x]<Rank[y])
    {
        par[x]=y;
    }
    else
    {
        par[y]=x;
        if(Rank[x]==Rank[y]) Rank[x]++;
    }

//    if(x!=y) par[x]=y;
}

//判断是否为同一个结点
int same(int x,int y)
{
    return find(x)==find(y);
}



int main()
{
//    cin>>N>>R;
    scanf("%d %d",&N,&R);
    //输入
    init(N*3);
    int ans=0;
    for(int i=0;i<R;++i)
    {
        int t,x,y;
        scanf("%d %d %d",&t,&x,&y);
 //       cin>>t>>x>>y;
        x=x-1;y=y-1;
        //查看输入是否符合条件
        if(x<0 || y<0 || x>=N || y>=N)
        {
            ans++;
            continue;
        }


        //判断是否是同一类
        if(t==1)
        {
            if(same(x,y+N) || same(x,y+2*N) )
            {
                ans++;
            }
            else
            {
                unite(x,y);
                unite(x+N,y+N);
                unite(x+2*N,y+2*N);
            }
        }

        //判断类间是否是捕食关系
        else
        {
            if(same(x,y) || same(x,y+2*N))
            {
                ans++;
            }
            else
            {
                unite(x,y+N);
                unite(x+N,y+2*N);
                unite(x+2*N,y);
            }
        }
    }

    printf("%d\n",ans);
    return 0;
}