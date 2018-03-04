#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
vector<string> a;

int main()
{
    int m,n,s;
    scanf("%d %d %d",&m,&n,&s);
    for(int i=0;i<m;++i)
    {
        string tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    vector<string> res;
    
    int i=s-1;
    while(i<m)
    {
        int tmp=n;
        auto it=find(res.begin(),res.end(),a[i]);
        if(it==res.end())
        {
            cout<<a[i]<<endl;
             res.push_back(a[i]);
        }
        while(i<m)
        {
            auto it=find(res.begin(),res.end(),a[i]);
            if(it==res.end())
            {
                tmp--;
                if(tmp==0) break;
            } 
            i++;
        }
    }

    if(res.empty())
        cout<<"Keep going..."<<endl;
    return 0;
}