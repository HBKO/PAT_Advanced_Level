#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
int L[105];
int N;

int main()
{
    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>L[i];
    }

    int start=0;
    int sum=0;
    for(int i=0;i<N;++i)
    {
        int temp=L[i]-start;
        if(temp<0)
        {
            sum+=(4*abs(temp));
        }
        else
            sum+=(6*temp);
        sum+=5;
        start=L[i];
    }
    cout<<sum<<endl;
    return 0;
}