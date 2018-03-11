#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<string>
using namespace std;

int main()
{
    int k;
    string s;
    scanf("%d",&k);
    cin>>s;
    set<char> a;
    int Str[500]={0};
    int normal[500]={0};
    char pre='#';
    s=s+'#';
    int cnt=1;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==pre)
        {
            cnt++;
        }
        else
        {
            if(cnt%k!=0)
            {
                normal[pre]=1;
            }
            cnt=1;
        }
        if(i!=s.length()-1) Str[s[i]]=(cnt%k==0);
        pre=s[i];
    }
    for(int i=0;i<s.length()-1;++i)
    {
        if(normal[s[i]]==1)
            Str[s[i]]=0;
    }
    //加入所有值
    for(int i=0;i<s.size()-1;++i)
    {
        if(Str[s[i]]==1 && a.find(s[i])==a.end())
        {
            a.insert(s[i]);
        }
    }
    for(auto it=a.begin();it!=a.end();++it)
        printf("%c",*it);
    printf("\n");
    for(int i=0;i<s.size()-1;++i)
    {
        printf("%c",s[i]);
        if(Str[s[i]]==1)
            i=i+k-1;
    }
    return 0;
}