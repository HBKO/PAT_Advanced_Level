#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

map<int,double> L1;
map<int,double> L2;
map<int,double> ALL;


int main()
{
    int N;
    cin>>N;
    int a;
    double b;

    for(int i=0;i<N;++i)
    {
        cin>>a>>b;
        L1[a]=b;
    }

    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>a>>b;
        L2[a]=b;
    }

    map<int,double>::iterator it_1=L1.begin();
    map<int,double>::iterator it_2=L2.begin();

    if(L1.empty() || L2.empty())
    {
        cout<<0<<endl;
        return 0;
    }


    for(;it_1!=L1.end();it_1++)
    {
        for(;it_2!=L2.end();it_2++)
        {
            a=(*it_1).first+(*it_2).first;
            b=(*it_1).second*(*it_2).second;
            map<int,double>::iterator it_3;
            it_3=ALL.find(a);
            if(it_3==ALL.end())
            {
                ALL[a]=b;
            }
            else
            {
                ALL[a]+=b;
            }
        }
        it_2=L2.begin();
    }

    int count=0;


    map<int,double>::reverse_iterator it_3=ALL.rbegin();
    for(;it_3!=ALL.rend();++it_3)
    {
        if(fabs((*it_3).second)>1e-6)
            count++;
    }
    
    cout<<count;
    it_3=ALL.rbegin();
    for(;it_3!=ALL.rend();++it_3)
    {
        if(fabs((*it_3).second)>1e-6)
        printf(" %d %.1lf",(*it_3).first, (*it_3).second);
    }
    cout<<endl;
    return 0;
}