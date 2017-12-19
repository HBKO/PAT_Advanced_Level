#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int MAX=20001;
const int MAX_2=1001;
typedef pair<int,int> P;
map<int,map<int,bool> > conn;

vector<int> homo[MAX];
vector<P> res[MAX_2];


int str2int(const char* a)
{
    int res=0;
    if(strlen(a)==4)
    {
        res=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+(a[3]-'0');
    }
    else if(a[0]=='-')
    {
        res=10000+(a[1]-'0')*1000+(a[2]-'0')*100+(a[3]-'0')*10+(a[4]-'0');
    }
    return res;
}


bool mycomp(P p1,P p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;
    else
    {
        return p1.first<p2.first;
    }
}


int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    for(int i=0;i<R;++i)
    {
        char a[8];char b[8];
        scanf("%s %s",a,b);
        int st,to;
        st=str2int(a);to=str2int(b);
        //同性
        if((st>=10000 && to>=10000) || (st<10000 && to<10000))
        {
            homo[st].push_back(to);
            homo[to].push_back(st);
        }
        conn[st][to]=true;
        conn[to][st]=true;
    }

    int M;
    scanf("%d",&M);
    int s,t;
    for(int k=0;k<M;++k)
    {
        char a[8];char b[8];
        scanf("%s %s",a,b);
        int st,to;
        st=str2int(a);to=str2int(b);

        for(int i=0;i<homo[st].size();++i)
        {
            if(homo[st][i]==to) continue;
            s=homo[st][i];
            for(int j=0;j<homo[to].size();++j)
            {
                if(homo[to][j]==st) continue;
                t=homo[to][j];
                if(conn[s][t])
                {
                    int tmp=s;int tmp2=t;
                    if(tmp>=10000) tmp-=10000;
                    if(tmp2>=10000) tmp2-=10000;
                    res[k].push_back(make_pair(tmp,tmp2));
                }
            }
        }

        sort(res[k].begin(),res[k].end(),mycomp);
        int size=res[k].size();
        printf("%d\n",size);
        for(int i=0;i<size;++i)
        {
            printf("%04d %04d\n",res[k][i].first,res[k][i].second);
        }
    }


    return 0;

}