#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> G[1001];

int color[1001];



bool dfs(int v,int c)
{
    color[v]=1;
    int size=G[v].size();
    for(int i=0;i<size;++i)
    {
        if(color[G[v][i]]==color[v]) return false;
        if(color[G[v][i]]==0 && !dfs(G[v][i],-1)) return false;
    }
    return true;
}



int main()
{
    int V,E;
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;++i)
    {
        int s,t;
        scanf("%d %d",&s,&t);
        G[s].push_back(t);
        G[t].push_back(s);
        color[t]=0;
        color[s]=0;
    }

    for(int i=0;i<V;++i)
    {
        if(color[i]==0)
        {
            if(!dfs(i,1))
            {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;

}