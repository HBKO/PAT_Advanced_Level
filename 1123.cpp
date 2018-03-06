#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int isComplete=1;int after=0;


struct node
{
    int val;
    node* left;
    node* right;
    node(int a):val(a),left(NULL),right(NULL){}
};

node* leftrotate(node* tree)
{
    node* tmp=tree->right;
    tree->right=tmp->left;
    tmp->left=tree;
    return tmp;
}

node* rightrotate(node* tree)
{
    node* tmp=tree->left;
    tree->left=tmp->right;
    tmp->right=tree;
    return tmp;
}

node* leftRightrotate(node* tree)
{
    tree->left=leftrotate(tree->left);
    tree=rightrotate(tree);
    return tree;
}

node* rightLeftrotate(node* tree)
{
    tree->right=rightrotate(tree->right);
    tree=leftrotate(tree);
    return tree;
}

int getHeight(node* tree)
{
    if(tree==NULL)
        return 0;
    else
    {
        int l=getHeight(tree->left);
        int r=getHeight(tree->right);
        return l>r? l+1:r+1;
    }
}

node* insert(node* root,int val)
{
    if(root==NULL)
    {
        node* tree=new node(val);
        return tree;
    }
    else
    {
        if(val>(root->val))
        {
            root->right=insert(root->right,val);
            int l=getHeight(root->left);
            int r=getHeight(root->right);
            if(r-l>=2)
            {
                if(val<(root->right->val))
                    root=rightLeftrotate(root);
                else
                    root=leftrotate(root);
            }
        }
        else
        {
            root->left=insert(root->left,val);
            int l=getHeight(root->left);
            int r=getHeight(root->right);
            if(l-r>=2)
            {
                if(val>(root->left->val))
                    root=leftRightrotate(root);
                else
                    root=rightrotate(root);
            }
        }
    }
    return root;
}


vector<int> printtree(node* root)
{
    vector<int> res;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* tmp=q.front();
        q.pop();
        res.push_back(tmp->val);
        //满二叉树的定义是一旦一个结点的左儿子有结点，后面的所有结点必须全为叶子结点
        //所以出现左边没结点，右边有结点也不为完全树
        //故一旦从左边开始出现叶子结点，后面都必须是叶子结点
        if(tmp->left!=NULL)
        {
            if(after)
            {
                isComplete=0;
            }
            q.push(tmp->left);
        }
        else
        {
            after=1;
        }
        if(tmp->right!=NULL)
        {
            if(after)
            {
                isComplete=0;
            }
            q.push(tmp->right);
        }
        else
        {
            after=1;
        }
    }
    return res;
}



int main()
{
    int k;
    scanf("%d",&k);
    node* tree;
    for(int i=0;i<k;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        tree=insert(tree,tmp);
    }
    vector<int> res=printtree(tree);
    for(int i=0;i<res.size();++i)
    {
        if(i==0)
            printf("%d",res[i]);
        else
            printf(" %d",res[i]);
    }
    printf("\n");
    if(isComplete)
        printf("YES");
    else
        printf("NO");
    return 0;
}
