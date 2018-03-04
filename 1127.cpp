#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;


struct node
{
    int val;
    node* left;
    node* right;
    node(int a):val(a),left(NULL),right(NULL){}
};

node* root;
stack<node*> sk;
queue<node*> qu;

void zigprint(node* rot)
{
    qu.push(rot);
    vector<vector<int> > res;
    int j=0;
    while(!qu.empty())
    {
        int size=qu.size();
        vector<int> tmp_1;
        res.push_back(tmp_1);
        for(int i=0;i<size;++i)
        {
            node* tmp=qu.front();
            res[j].push_back(tmp->val);
            if(tmp->left) qu.push(tmp->left);
            if(tmp->right) qu.push(tmp->right);
            qu.pop();
        }
        j++;
    }
    for(j=0;j<res.size();++j)
    {
        if(j%2==0)
        {
            reverse(res[j].begin(),res[j].end());
        }
        for(int i=0;i<res[j].size();++i)
        {
            if(j==0 && i==0)
            {
                printf("%d",res[j][i]);
            }
            else
            {
                printf(" %d",res[j][i]);
            }
        }
    }
}

int main()
{
    int k,tmp;
    vector<int> inorder;
    vector<int> postorder;
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        scanf("%d",&tmp);
        inorder.push_back(tmp);
    }
    for(int i=0;i<k;++i)
    {
        scanf("%d",&tmp);
        postorder.push_back(tmp);
    }
    reverse(inorder.begin(),inorder.end());
    reverse(postorder.begin(),postorder.end());
    root=new node(postorder[0]);
    node* nownode=root;
    sk.push(nownode);
    int flag=0; //代表是否转向
    int i=1;int j=0;
    node* temp=root;
    while(i<k)
    {
        //如果栈空也说明要转向了
        if(!sk.empty() && (sk.top()->val)==inorder[j])
        {
            temp=sk.top();
            flag=1;
            sk.pop();
            j++;
        }
        else
        {
            if(flag==0)
            {
                temp->right=new node(postorder[i]);
                i++;
                temp=temp->right;
                sk.push(temp);
            }
            else
            {
                flag=0;
                temp->left=new node(postorder[i]);
                ++i;
                temp=temp->left;
                sk.push(temp);
            }
        }
    }
    zigprint(root);
    return 0;
}

