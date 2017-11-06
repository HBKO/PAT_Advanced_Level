//判断从N个数字中寻找和为sum的数字
//输入

#include<iostream>
using namespace std;

int a[1000];
int sum,k;

bool dfs(int i,int num)
{
    if(i==k) return num==sum;
    //没有选择了第i的数字
    if(dfs(i+1,num)) return true;
    //选择了第i的数字
    if(dfs(i+1,num+a[i])) return true;
    //找不到数组
    return false;
}

int main()
{
    scanf("%d %d",&k,&sum);
    for(int i=0;i<k;++i)
    {
        scanf("%d",&a[i]);
    }
    if(dfs(0,0)) printf("YES");
    else printf("NO");
    return 0;
}
