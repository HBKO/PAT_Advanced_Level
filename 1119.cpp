#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> pre,post,in;

int uni=1;
void getIn(int preLeft,int preRight,int postLeft,int postRight)
{
    if(preLeft==preRight)
    {
        in.push_back(pre[preLeft]);
        return;
    }
    //出现前序和后序相等的时候，说明可以进行递归划分
    if(pre[preLeft]==post[postRight])
    {
        int i=preLeft+1;
        //寻找下一个分割点
        while(i<=preRight && pre[i]!=post[postRight-1]) i++;
        //判断是否出现无法判断的情况，如果出现没法判断的情况，即可能是出现只有两个结点的情况:根-左子树，根-右子树
        if(i-preLeft>1) getIn(preLeft+1,i-1,postLeft,postLeft+(i-preLeft-1)-1);    //处理出现的左子树
        else
            uni=0;
        in.push_back(post[postRight]);
        //处理剩下的两遍部分，说明是右子树
        getIn(i,preRight,postLeft+(i-preLeft-1),postRight-1);
    }
}


int main()
{
    int k;
    scanf("%d",&k);
    int tmp;
    for(int i=0;i<k;++i)
    {
        scanf("%d",&tmp);
        pre.push_back(tmp);
    }
    for(int i=0;i<k;++i)
    {
        scanf("%d",&tmp);
        post.push_back(tmp);
    }
    getIn(0,k-1,0,k-1);
    if(uni) printf("Yes\n");
    else    printf("No\n");
    printf("%d",in[0]);
    for(int i=1;i<k;++i)
        printf(" %d",in[i]);
    printf("\n");
    return 0;
}
