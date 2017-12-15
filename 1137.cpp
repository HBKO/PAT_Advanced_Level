#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

map<string,vector<int> > list;
map<string,vector<int> > res;
map<string,vector<int> >::iterator it2;
struct node
{
    int grade;
    string name;
};

vector<struct node> res2;


bool mycompare(struct node n1,struct node n2)
{
    if(n1.grade==n2.grade)  return n1.name< n2.name;
    else
    {
        return n1.grade>n2.grade;
    }
}


int main()
{
    int k,m,n;
    cin>>k>>m>>n;
    string tmp;
    int a;
    while(k--)
    {
        cin>>tmp>>a;
        list[tmp].push_back(a);
    }

    while(m--)
    {
        cin>>tmp>>a;
        it2=list.find(tmp);
        if(it2==list.end()) continue;
        else
        {
            (it2->second).push_back(a);
        }
    }

    while(n--)
    {
        cin>>tmp>>a;
        it2=list.find(tmp);
        if(it2==list.end()) continue;
        else
        {
            vector<int> b=(it2->second);
            if(b.size()==1)
            { 
                (it2->second).push_back(-1);
            }
           (it2->second).push_back(a);
        }
    }

    res2.reserve(list.size());


    map<string,vector<int> >::iterator it;


    for(it=list.begin();it!=list.end();++it)
    {
        vector<int> b=it->second;
        if(b.size()==2 || b[0]<200) continue;
        else
        {
            int fingrade;
            if(b[2]>b[1])
            {
                fingrade=b[2];
            }
            else
            {
                fingrade=int(b[1]*0.4+b[2]*0.6+0.5);
//                if(fingrade>100) fingrade=100; 
            }
            (it->second).push_back(fingrade);
            if(fingrade>=60)
            {
                res[it->first]=it->second;
                struct node c;
                c.name=it->first;c.grade=fingrade;
                res2.push_back(c);
            }
        }
    }

    sort(res2.begin(),res2.end(),mycompare);

    for(int i=0;i<res2.size();++i)
    {
        string name1=res2[i].name;
        cout<<name1;
        vector<int> b=res[name1];
        int sizeb=b.size();
        for(int j=0;j<sizeb;++j)
        {
            cout<<" "<<b[j];
        } 
        cout<<endl;
    }

    return 0;

}