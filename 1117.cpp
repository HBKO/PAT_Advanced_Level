#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(int a,int b)
{
    return a>b;
}

int a[100001];

int main()
{
    int k;
    scanf("%d",&k);
    for(int i=1;i<k+1;++i)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+k+1,comp);
    int ans=0;int p=1;
    while(ans<=k && a[p]>p)
    {
        ans++;
        p++;
    }
    printf("%d",ans);
    return 0;
}