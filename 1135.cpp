#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

#define true 1
#define false 0

struct Node{
    int data;
    Node *lchild,*rchild;
};

struct Node *root=NULL;  
int flag=1;



//构建平衡二叉树
void insert(Node* &node,int data)
{
    if(node==NULL)
    {
        node=(struct Node*)malloc(sizeof(struct Node));
        node->data=data;
        node->lchild=node->rchild=NULL;
        return;
    }
    else
    {
        if(abs(data)>=abs(node->data))
            insert(node->rchild,data);
        else
            insert(node->lchild,data);
    }
}

void tell1(Node* node)
{
    if(flag==false)
        return;
    if(node!=NULL)
    {
        if(node->lchild!=NULL)
        {
            if(node->data<0 && node->lchild->data<0)
            {
                flag=false;
                return;
            }
            else
            {
                tell1(node->lchild);
            }
        }
        if(node->rchild!=NULL)
        {
            if(node->data<0 && node->rchild->data<0)
            {
                flag=false;
                return;
            }
            else
            {
                tell1(node->rchild);
            }
        }
    }
}



int tell2(Node* node)
{
    if(flag==false)
        return -1;
    if(node==NULL)
        return 1;
    int l1,l2;
    l1=tell2(node->rchild);
    l2=tell2(node->lchild);
    if(l1!=l2)
    {
        flag=false;
        return -1;
    }
    else
    {
        l1=l1+(node->data>0);
    }
    return l1;
}



int main()
{
    int M;
    cin>>M;
    while(M--)
    {
        flag=true;
        root=NULL;
        int N;
        cin>>N;
        while(N--)
        {
            int tmp;
            cin>>tmp;
            insert(root,tmp);
        }
        if(root==NULL && root->data<0)
        {
            cout<<"No"<<endl;
            continue;
        }
        tell1(root);
        if(flag==false)
        {
            cout<<"No"<<endl;
            continue;
        }
        tell2(root);
        if(flag==false)
        {
            cout<<"No"<<endl;
            continue;
        }
        else
        {
            cout<<"Yes"<<endl;
            continue;
        }
    }
    return 0;
}