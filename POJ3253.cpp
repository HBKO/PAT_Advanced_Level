//这个割木板的题目相当于构造一棵huffman树，
//cost=求和(叶子结点乘以深度)


#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int N;
int L[200005];

int main()
{
    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>L[i];
    }

    ll ans=0;


    //直到计算到木板为一块为止
    while(N>1)
    {
        int mii1=0,mii2=1;
        if(L[mii1]>L[mii2]) swap(mii1,mii2);

        //寻找最小两块
        for(int i=2;i<N;i++)
        {
            if(L[i]<L[mii1])
            {
                mii2=mii1;
                mii1=i;
            }
            else if(L[i]<L[mii2])
            {
                mii2=i;
            }
        }
        
        //进行两块木板的合并
        int t=L[mii1]+L[mii2];
        //结果
        ans+=t;

        if(mii1==N-1) swap(mii1,mii2);
        L[mii1]=t;
        L[mii2]=L[N-1];
        N--;

    }
    cout<<ans<<endl;
    return 0;
}