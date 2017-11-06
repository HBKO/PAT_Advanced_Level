#include<iostream>
#include<map>
#include<vector>
using namespace std;


map<int,vector<int> > res;
int leveleave[105]={0};


void dfs(int node,int level)
{
    //找到叶子结点
    if(res[node].empty())
    {
        leveleave[level]++;
        return;
    }

    //dfs
    int size=res[node].size();
    for(int i=0;i<size;++i)
    {
        dfs(res[node][i],level+1);
    }
}



int main()
{
    int m,n;
    cin>>m>>n;
    int leave=m-n;
    for(int i=0;i<n;++i)
    {
        int st,k;
        cin>>st>>k;
        for(int j=0;j<k;++j)
        {
            int node;
            cin>>node;
            res[st].push_back(node);
        }
    }

    dfs(1,0);
    int a=leveleave[0];
    cout<<a;
    int i;
    for(i=1;a<leave;++i)
    {
        cout<<" "<<leveleave[i];
        a=a+leveleave[i];
    }
    return 0;
}