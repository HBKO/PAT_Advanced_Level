//利用并查集来实现判断鸟是否在同一棵树上
//利用exist[MAX_N]来存储家鸟是否存在
//利用cnt[MAX_N]来进行计数的操作
#include<cstdio>
using namespace std;
#define MAX_N 10010
int par[MAX_N]={0};
int exist[MAX_N]={0};
int cnt[MAX_N]={0};

int findfather(int x)
{
    int a=x;
    //进行查找
    while(x!=par[x])
        x=par[x];
    //路径压缩
    while(a!=par[a])
    {
        int z=a;
        a=par[a];
        par[z]=x;
    }
    return x;
}

void myunion(int A,int B)
{
    int faA=findfather(A);
    int faB=findfather(B);
    if(faA!=faB)
    {
        par[faA]=faB;
    }
}

int main()
{
    int k;
    scanf("%d",&k);
    //初始化并查集
    for(int i=0;i<MAX_N;++i)
        par[i]=i;
    for(int i=0;i<k;++i)
    {
        int m,id;
        scanf("%d %d",&m,&id);
        exist[id]=1;
        for(int j=0;j<m-1;++j)
        {
            int tmp;
            scanf("%d",&tmp);
            myunion(id,tmp);
            exist[tmp]=1;
        }
    }
    for(int i=0;i<MAX_N;++i)
    {
        if(exist[i])
        {
            int root=findfather(i);
            cnt[root]++;
        }
    }
    int tree=0;int bird=0;
    for(int i=0;i<MAX_N;++i)
    {
        if(exist[i] && cnt[i]>0)
        {
            tree++;
            bird+=cnt[i];
        }
    }
    printf("%d %d\n",tree,bird);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int st,to;
        scanf("%d %d",&st,&to);
        if(findfather(st)==findfather(to))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}