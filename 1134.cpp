#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> >a;

int main()
{
    int v,e;
    a.reserve(10001);
    cin>>v>>e;
    for(int i=0;i<e;++i)
    {
        int start,end;
        cin>>start>>end;
        a[start].push_back(i);
        a[end].push_back(i);
    }

    int count_2;
    cin>>count_2;
    while(count_2--)
    {
        vector<int> hash(e,0);
        int number;
        cin>>number;
        for(int i=0;i<number;++i)
        {
            int k;
            cin>>k;
            vector<int> tmp=a[k];
            for(int j=0;j<tmp.size();++j)
            {
                hash[tmp[j]]=1;
            }
        }
    

        int flag=0;
        for(int i=0;i<e;++i)
        {
            if(hash[i]==0)
            {
                flag=1;
                cout<<"No"<<endl;
                break;
            }
        }
        if(flag==0)
            cout<<"Yes"<<endl;
     }
    return 0;   
}