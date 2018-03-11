#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct in{
    int id;
    int fid;
    int mid;
    int child[10];
    int estate;
    int area;
    in():id(0),fid(0),mid(0),estate(0),area(0){};
};
struct res{
    int id;
    int people;
    double estate;
    double area;
    bool flag;
    res():id(0),people(0),estate(0),area(0),flag(false){};
};
in data[1000];
res ans[10000];
int par[10000]; bool visit[10000];


bool mycompare(res& a,res& b)
{
    if(a.area!=b.area)
        return a.area>b.area;
    else
        return a.id<b.id;
}

int findfa(int x)
{
    int a=x;
    while(x!=par[x])
        x=par[x];
    while(a!=par[a])
    {
        int z=a;
        a=par[a];
        par[z]=x;
    }
    return x;
}
void myunion(int x,int y)
{
    int fax=findfa(x);
    int fay=findfa(y);
    if(fax<fay)
        par[fay]=fax;
    if(fax>fay)
        par[fax]=fay;
}

int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<10000;++i)
        par[i]=i;
    for(int i=0;i<k;++i)
    {
        int num;
        scanf("%d %d %d %d",&data[i].id,&data[i].fid,&data[i].mid,&num);
        visit[data[i].id]=true;
        if(data[i].fid!=-1)
        {
            visit[data[i].fid]=true;
            myunion(data[i].id,data[i].fid);
        }
        if(data[i].mid!=-1)
        {
            visit[data[i].mid]=true;
            myunion(data[i].id,data[i].mid);
        }
        for(int j=0;j<num;++j)
        {
            scanf("%d",&data[i].child[j]);
            visit[data[i].child[j]]=true;
            myunion(data[i].id,data[i].child[j]);
        }
        scanf("%d %d",&data[i].estate,&data[i].area);
    }
    int cnt=0;
    for(int i=0;i<k;++i)
    {
        int id=findfa(data[i].id);
        ans[id].id=id;
        ans[id].estate+=data[i].estate;
        ans[id].area+=data[i].area;
        ans[id].flag=true;
    }
    for(int i=0;i<10000;++i)
    {
        if(visit[i])
        {
            int id=findfa(i);
            ans[id].people++;
        }
        if(ans[i].flag)
            cnt++;
    }
    for(int i=0;i<10000;++i)
    {
        if(ans[i].flag!=0)
        {
            ans[i].estate=(ans[i].estate/ans[i].people);
            ans[i].area=(ans[i].area/ans[i].people);
        }
    }
    sort(ans,ans+10000,mycompare);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;++i)
        printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].estate,ans[i].area);
    return 0;
}
