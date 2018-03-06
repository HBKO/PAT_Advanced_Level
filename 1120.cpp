#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int k;
    scanf("%d",&k);
    vector<int> res;
    for(int i=0;i<k;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        int count=0;
        while(tmp)
        {
            count+=(tmp%10);
            tmp=tmp/10;
        }
        auto it=find(res.begin(),res.end(),count);
        if(it==res.end())
        {
            res.push_back(count);
        }
    }
    sort(res.begin(),res.end());
    printf("%d\n",res.size());
    if(!res.empty()) printf("%d",res[0]);
    for(int i=1;i<res.size();++i)
    {
        printf(" %d",res[i]);
    }
    return 0;
}