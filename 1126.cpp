#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> G[505];
int visit[505]={0};

//欧拉回路必须判断一下图的连通性
void dfs(int node,int& cnt)
{
    cnt=cnt+1;
    visit[node]=1;
    for(int i=0;i<G[node].size();++i)
    {
        if(visit[G[node][i]]==0)
        {
            dfs(G[node][i],cnt);
        }
    }
}

int main()
{
    int V,E;
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;++i)
    {
        int st,to;
        scanf("%d %d",&st,&to);
        st--;to--;
        G[st].push_back(to);
        G[to].push_back(st);
    }
    int du[V];
    int count=0;
    printf("%d",G[0].size());
    for(int i=0;i<V;++i)
    {
        du[i]=G[i].size();
        if(i!=0)
            printf(" %d",du[i]);
        if(du[i]%2)
        {
            count++;
        }
    }
    printf("\n");
    int cnt=0;
    dfs(1,cnt);
    if(cnt!=V)
    {
        printf("Non-Eulerian");
        return 0;
    }
    if(count==0) printf("Eulerian");
    else if(count==2)
    {
        printf("Semi-Eulerian");
    }
    else
    {
        printf("Non-Eulerian");
    }
    return 0;
}