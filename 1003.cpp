#include <cstdio>
#include <cstdlib>
#include <climits>

const int MAX=501;
int wei[MAX],visit[MAX],map[MAX][MAX];

int mind,maxt,cnt,n;


void init(int n)
{
    for(int i=0;i<n;++i)
    {
        visit[i]=0;
        for(int j=0;j<n;++j)
        {
            map[i][j]=INT_MAX;
        }
    }
    mind=INT_MAX;
    cnt=0;
}



void dfs(int st,int end,int distan,int numwei)
{
    //终点
    if(st==end)
    {
        if(distan<mind)
        {
            cnt=1;
            mind=distan;
            maxt=numwei;
        }
        else if(distan==mind)
        {
            cnt++;
            if(numwei>maxt)
            {
                maxt=numwei;
            }
        }

        return; //回溯
    }

    if(distan>mind) return;  //进行剪枝

    //深搜
    for(int i=0;i<n;++i)
    {
        if(map[st][i]!=INT_MAX && visit[i]==0)
        {
            visit[i]=1;
            dfs(i,end,distan+map[st][i],numwei+wei[i]);
            visit[i]=0;
        }
    }
}





int main()
{
    int m,st,end;
    scanf("%d %d %d %d",&n,&m,&st,&end);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&wei[i]);
    }
    int i,j,d;

    init(n);

    while(m--)
    {
        scanf("%d %d %d",&i,&j,&d);
        if(map[i][j]>d)
        {
            map[i][j]=map[j][i]=d;
        }
    }


    dfs(st,end,0,wei[st]);
    printf("%d %d\n",cnt,maxt);
    return 0;
}