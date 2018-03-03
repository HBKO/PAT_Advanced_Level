#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int> > v(10000);
int line[10000][10000],visit[10000];
vector<int> temppath;
vector<int> path;

int cntTransfer(vector<int> a)
{
    int cnt=-1;
    int preLine=0;
    for(int i=1;i<a.size();++i)
    {
        if(line[a[i-1]][a[i]]!=preLine) cnt++;
        preLine=line[a[i-1]][a[i]];
    }
    return cnt;
}

//维护两个变量mincnt：最少车站数，minTransfer：最少换乘数
void dfs(int start,int end,int cnt,int& mincnt,int& minTransfer)
{
    if(start==end && cnt<=mincnt)
    {
        int Transfer=cntTransfer(temppath);
        if(cnt<mincnt || (cnt==mincnt && Transfer<minTransfer) )
        {
            mincnt=cnt;
            minTransfer=Transfer;
            path=temppath;
        }
    }
    if(start==end) return;
    //dfs搜索
    for(int i=0;i<v[start].size();++i)
    {
        //确认是有没有访问过
        if(visit[v[start][i]]==0)
        {
            visit[v[start][i]]=1;
            temppath.push_back(v[start][i]);
            dfs(v[start][i],end,cnt+1,mincnt,minTransfer);
            visit[v[start][i]]=0;
            temppath.pop_back();
        }
    }
}

int main()
{
    int k,m,n;
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        scanf("%d",&m);
        int temp,now;
        scanf("%d",&temp);
        for(int j=1;j<m;++j)
        {
            scanf("%d",&now);
            v[temp].push_back(now);
            v[now].push_back(temp);
            line[temp][now]=line[now][temp]=i+1;
            temp=now;
        }
    }
    
    //输入问题
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int mincnt=99999;
        int minTransfer=99999;
        path.clear();
        temppath.clear();
        int start,to;
        scanf("%d %d",&start,&to);
        temppath.push_back(start);
        visit[start]=1;
        dfs(start,to,0,mincnt,minTransfer);
        visit[start]=0;
        printf("%d\n",mincnt);
        int preLine=0,preTranfer=start;
        for(int j=1;j<path.size();++j)
        {
            if(line[path[j-1]][path[j]]!=preLine)
            {
                if(preLine!=0)
                {
                    printf("Take Line#%d from %04d to %04d.\n",preLine,preTranfer,path[j-1]);
                }
                preLine=line[path[j-1]][path[j]];
                preTranfer=path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",preLine,preTranfer,to);
    }
    return 0;
}
