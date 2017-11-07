#include<iostream>
#include<algorithm>

using namespace std;

int X[1005];

int main()
{
    int n,R;
    while(1)
    {
    cin>>R>>n;
    if(R==-1 && n==-1) break;
    for(int i=0;i<n;++i)
    {
        cin>>X[i];
    }
    sort(X,X+n);
    int i=0;
    int ans=0;
    while(i<n)
    {
        //取右边缘没有取到的点
        int number=X[i++];
        while(i<n && X[i]<=number+R) i++;

        //做标记
        int p=X[i-1];
        //接着寻找下面的点
        while(i<n && X[i]<=p+R) i++;
        ans++;
    }
    cout<<ans<<endl;
}

    return 0;
}