#include<cstdio>
#include<string>
#include<stack>
#include<iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):value(x),left(NULL),right(NULL) {}
};


int a[50001];
int b[50001];
int flag3=0;

void postorder(TreeNode* a);

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }    
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    if(n==1)
    {
        cout<<a[0];
    }
    int flag=0;
    int i=1;
    int j=0;
    stack<TreeNode *>st;
    TreeNode* root=new TreeNode(a[0]);
    TreeNode* node=root;
    
    st.push(root);
    while(i<n)
    {
        //转向
        if(!st.empty() && (st.top())->value==b[j])
        {
            node=st.top();
            st.pop();
            flag=1;
            j++;
        }
        else
        {
            TreeNode* tmp=new TreeNode(a[i]);
            i++;
            if(flag==0)
            {
                node->left=tmp;
                node=node->left;
                st.push(node);
            }
            else
            {
                node->right=tmp;
                node=node->right;
                st.push(node);
                flag=0;
            }
        }
    }

    postorder(root);

    
}


void postorder(TreeNode* a)
{
    if(flag3==1 || a==NULL)
    {
        return;
    }
    else
    {
        postorder(a->left);
        postorder(a->right);
        if(flag3==0)
        {
            cout<<(a->value);
            flag3=1;
        }
    }
}