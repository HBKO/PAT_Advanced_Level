#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct node
{
    int val;
    node* left;
    node* right;
    node(int a):val(a),left(NULL),right(NULL){};
};
//应该用dfs
int num[1000];
int maxdepth=-1;
node* insert(int val,node* root)
{
    if(root==NULL)
    {
        root=new node(val);
        return root;
    }
    else
    {
        if(val>root->val)
            root->right=insert(val,root->right);
        else
            root->left=insert(val,root->left);
    }
    return root;
}


void dfs(node* root,int depth)
{
    if(root==NULL)
    {
        maxdepth=max(depth,maxdepth);
        return;
    }
    num[depth]++;
    dfs(root->left,depth+1);
    dfs(root->right,depth+1);
}

int main()
{
    int k;
    scanf("%d",&k);
    node* root=NULL;
    int tmp;
    for(int i=0;i<k;++i)
    {
        scanf("%d",&tmp);
        root=insert(tmp,root);
    }
    dfs(root,0);
    printf("%d + %d = %d",num[maxdepth-1],num[maxdepth-2],num[maxdepth-1]+num[maxdepth-2]);
    return 0;
}
