#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int number[10001]={0};

int main()
{
    int k;
    cin>>k;
    int flag=0;
    for(int i=0;i<k;++i)
    {
        cin>>number[i];
        if(number[i]>=0) flag=1;
    }
    if(!flag)
    {
        cout<<0<<" "<<number[0]<<" "<<number[k-1];
    }
    else
    {
    int start=0;
    int end=0;
    int max_so_far=0;
    int max_end=0;

    for(int i=0;i<k;++i)
    {
        max_so_far+=number[i];
        if(max_so_far>max_end)
        {
            max_end=max_so_far;
            end=i;
        }
        else if(max_so_far<0)
        {
            max_so_far=0;
        }
    }


    int temp_sum=0;
    int temp_max=-1;
    for(int i=end;i>=0;i--)
    {
        temp_sum=temp_sum+number[i];
        if(temp_sum>temp_max)
        {
            temp_max=temp_sum;
            start=i;
        }
    }
    cout<<max_end<<" "<<number[start]<<" "<<number[end];
}
    return 0;
}