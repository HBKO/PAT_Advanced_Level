#include<iostream>
#include<cstdio>
using namespace std;
#define N 1100



int main()
{
    int k;
    scanf("%d",&k);
    int map[N][N];
    while(k--)
    {
        int n;
        int num[N];
        int flag=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&num[i]);
            num[i]=num[i]-1;
            for(int j=0;j<n;++j)
            {
                map[i][j]=0;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(map[i][num[i]]!=0) 
            {
                printf("NO\n");
                flag=1;
                break;
            }
            for(int j=0;j<n;++j)
            {
                map[j][num[i]]=1;               
            }
            int rr=i+1;
            int rl=i-1;
            int cr=num[i]+1;
            int cl=num[i]-1;
            while(rr<n && cr<n)
            {
                map[rr][cr]=1;
                rr++;
                cr++;
            }
            while(rl>=0 && cl>=0)
            {
                map[rl][cl]=1;
                rl--;
                cl--;
            }
            rr=i+1; rl=i-1;cr=num[i]+1;cl=num[i]-1;
            while(rr<n && cl>=0)
            {
                map[rr][cl]=1;rr++;cl--;
            }
            while(rl>=0 && cr<n)
            {
                map[cr][rl]=1;rl--;cr++;
            }
        }
        if(flag==0)
        {
            printf("YES\n");
        }
    }
    return 0;
}