#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    vector<int> num;
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        num.push_back(tmp);
    }
    sort(num.begin(),num.end());
    double res=(num[0]+num[1])/2.0;
    for(int i=2;i<k;++i)
    {
        res+=num[i];
        res=res/2;
    }
    int fin=floor(res);
    printf("%d\n",fin);
    return 0;
}