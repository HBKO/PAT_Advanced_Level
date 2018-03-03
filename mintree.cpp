int cost[MAX_N][MAX_N];         //代表距离,达不到的距离设定为INF
int mincost[MAX_N];             //存储最近距离
int used[MAX_N];                //存储点是否被访问过的信息
int par[MAX_N];                 //父亲
int rank[MAX_N];                //树高
int V;                          //代表结点的数量
int E;                          //存储边的数量

//存储边的信息，开始，结束，以及花费
struct edge
{
    int st;
    int to;
    int cost;
};

edge e[MAX_N];                  //存储相关边的信息

bool comp(const edge& e1,const edge& e2)
{
    return e1.cost<e2.cost;
}


int prim()
{
    fill(mincost,mincost+MAX_N,INF);
    fill(used,used+MAX_N,false);
    mincost[0]=0;
    res=0;
    while(true)
    {
        int v=-1;
        //找出当前最小的边
        for(int i=0;i<V;++i)
        {
            if(!used[i] && (v==-1 || mincost[i]<mincost[v])) v=i;
        }
        //说明已经遍历完了
        if(v==-1)   break;
        used[v]=true;
        //存储结点信息
        res+=mincost[v];
        //更新距离
        for(int i=0;i<V;++i)
        {
            //这里可以存储边的信息
            mincost[i]=min(mincost[i],cost[v][i]);
        }
    }
    return res;
}

void init_union_find(int n)
{
    for(int i=0;i<n;++i)
    {
        par[i]=i;
        rank[i]=0;
    }
}

int find(int x)
{
    //一直递归向上找，直到找到根为止(即两个值相等)
    if(par[x]==x)
    {
        return x;
    }
    else
    {
        return par[x]=find(par[x]);
    }
}

int same(x,y)
{
    return find(x)==find(y);
}

void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    
    if(rank[x]>rank[y])
    {
        par[y]=x;
    }
    else
    {
        par[x]=y;
        if(rank[x]==rank[y]) rank[x]++;
    }
}

//kruskal算法
void kruskal()
{
    res=0;
    sort(edge,edge+E,comp);
    init_union_find(V);     //并查基的初始化
    for(int i=0;i<E;++i)
    {
        edge ed=e[i];
        if(!same(ed.st,ed.to))
        {
            //添加边的时候可以构造新的图信息
            res+=ed.cost;
            unite(ed.st,ed.to);
        }
    }
    return res;
}


