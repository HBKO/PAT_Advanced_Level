#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    int k;
    vector<int> data;
    scanf("%d",&k);
    int mingap=0;
    int maxnumber=0;
    for(int i=0;i<k;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        data.push_back(tmp);
    }
    sort(data.begin(),data.end());
    int mid=data.size()/2;
    int left,right;
    if(data.size()%2==0)
    {
        left=mid-1;right=mid;
        int leftsum=0;int rightsum=0;
        for(int i=0;i<=mid-1;++i)  leftsum+=data[i];
        for(int i=mid;i<data.size();++i) rightsum+=data[i];
        maxnumber=rightsum-leftsum;
        printf("0 %d",maxnumber);
    }
    else
    {
        left=mid-1;right=mid;
        int leftsum=0;int rightsum=0;
        for(int i=0;i<=mid-1;++i)  leftsum+=data[i];
        for(int i=mid;i<data.size();++i) rightsum+=data[i];
        maxnumber=rightsum-leftsum;
        printf("1 %d",maxnumber);        
    }
    return 0;
}
