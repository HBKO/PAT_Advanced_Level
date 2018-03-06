#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;



int A[100000];
int G[100000];

int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        int s,t;
        scanf("%d %d",&s,&t);
        A[s]=t;
        A[t]=s;
    }
    scanf("%d",&k);
    vector<int> res;
    int s=-1; int t=-1;
    for(int i=0;i<k;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        res.push_back(tmp);
        G[tmp]=1;
        if(G[A[tmp]]==1)
        {
            s=tmp;t=A[tmp];
        }
        if(s!=-1 || t!=-1)
        {
            auto it=find(res.begin(),res.end(),s);
            if(it!=res.end()) res.erase(it);
            it=find(res.begin(),res.end(),t);
            if(it!=res.end()) res.erase(it);
            s=-1;t=-1;
        }
    }
    sort(res.begin(),res.end());
    printf("%d\n",res.size());
    if(!res.empty()) printf("%05d",res[0]);
    for(int i=1;i<res.size();++i)
        printf(" %05d",res[i]);
    return 0;
}
