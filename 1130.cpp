#include<vector>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int root=1;
struct node
{
    string data;
    int left;
    int right;
};
vector<node> v;


string dfs(int index)
{
    if(index==-1) return "";
    //由于是一个语法树，不可能出现左有，右空的情况，所以只要判断右边是否为空就可以了
    if(v[index].right!=-1)
    {
        v[index].data=dfs(v[index].left)+v[index].data+dfs(v[index].right);
        //只要不为树根，每递归完一层就加一个括号
        if(index!=root) v[index].data='('+v[index].data+')';
    }
    return v[index].data;
}

int main()
{
    int k;
    scanf("%d",&k);
    vector<int> visit(k+1,0);
    v.resize(k+1);
    //遍历所有数据，没有出现的编号即为根结点
    for(int i=1;i<=k;++i)
    {
        cin>>v[i].data>>v[i].left>>v[i].right;
        if(v[i].left!=-1) visit[v[i].left]=1;
        if(v[i].right!=-1) visit[v[i].right]=1;
    }
    while(visit[root]!=0) root++;
    cout<<dfs(root)<<endl;
}