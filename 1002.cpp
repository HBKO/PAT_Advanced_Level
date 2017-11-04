#include<iostream>
#include<map>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
    vector<float> res(1001,0.0);
    int k,exp;
    float frac;
    scanf("%d ",&k);
    for(int i=0;i<k;++i)
    {
        scanf("%d %f",&exp,&frac);
        res[exp]+=frac;
    }
    scanf("%d ",&k);
    for(int i=0;i<k;++i)
    {
        scanf("%d %f",&exp,&frac);
        res[exp]+=frac;
    }
    map<int,float> trueres;
    for(int i=1000;i>=0;--i)
    {
        if(res[i]!=0.0)
        {
            trueres.insert(pair<int,float>(i,res[i]));
        }
    }
    int size=trueres.size();
    printf("%d",size);

    //遍历
    map<int,float>::reverse_iterator it=trueres.rbegin();
    for(;it!=trueres.rend();it++)
    {
        printf(" %d %.1lf",(*it).first,(*it).second);
    }
    return 0;
}