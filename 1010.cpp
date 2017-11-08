#include<iostream>
#include<string>
using namespace std;

typedef long long int ll;


ll Cal(char a)
{
    if(a>='0' && a<='9')
        return (a-'0');
    else
    {
        return (a-'a'+10);
    }
}

//计算基数值
ll getRadixValue(string a,ll radix)
{
    int size=a.size();
    ll result=0;
    for(int i=0;i<size;++i)
    {
        result*=radix;
        result+=Cal(a[i]);
        if(result<0)
        {
            return -1;
        }
    }

    return result;
}



int main()
{
    string a;
    string b;
    int tag;
    ll radixA;
    ll radixB;
    ll valueA,valueB;
    cin>>a>>b>>tag>>radixA;
    if(tag==2)
    {
        string temp=b;
        b=a;
        a=temp;
    }


    ll minradix=0;
    ll maxradix;
    for(int i=0;i<b.size();++i)
    {
        if(Cal(b[i])>minradix)
        {
            minradix=Cal(b[i])+1;
        }
    }
    valueA=getRadixValue(a,radixA);
    maxradix=valueA+1;

    //二分搜索
    while(minradix<=maxradix)
    {
        //二分搜索要使用else if 来进行搜索
        radixB=(minradix+maxradix)/2;
        valueB=getRadixValue(b,radixB);
        if(valueB==-1 || valueB>valueA)
        {
            maxradix=radixB-1;
        }
        else if(valueB<valueA)
        {
            minradix=radixB+1;
        }
        else if(valueB==valueA)
        {
            cout<<radixB<<endl;
            return 0;
        }
    }

    cout<<"Impossible"<<endl;

    return 0;
}