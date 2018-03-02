#include<cstdio>
#include<set>
using namespace std;
int books[50010];

struct node{
    int value,cnt;
    node(int a,int b):value(a),cnt(b){}
    bool operator < (const node& a) const
    {
        return (cnt!=a.cnt)? cnt>a.cnt :a.value>value;
    }
};
int main()
{
    int k,m;
    scanf("%d %d",&k,&m);
    set<node> setnode;
    for(int i=0;i<k;++i)
    {
        //先进行输出
        int tmp;
        scanf("%d",&tmp);
        if(i!=0)
        {
            printf("%d:",tmp);
            int num=0;
            for(auto it=setnode.begin();it!=setnode.end() && num<m;it++)
            {
                printf(" %d",it->value);
                num++;
            }
            printf("\n");
        }
        auto it=setnode.find(node(tmp,books[tmp]));
        if(it!=setnode.end())
        {
            setnode.erase(it);
        }
        books[tmp]++;
        setnode.insert(node(tmp,books[tmp]));
    }
    return 0;
}