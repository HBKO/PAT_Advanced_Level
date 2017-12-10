#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

typedef unsigned long long  int ll;

int num[1010];
int renum[1010];
int tmp[1010];
void printnum(int* a);

void re()
{
    memset(renum,0,sizeof(int)*1000);
    renum[0]=num[0];
    int size=renum[0];
    for(int i=1;i<=size;++i)
    {
        renum[size+1-i]=num[i];
    }
}

int ispa(int* a)
{
    int size=a[0];
    int l=1,r=size;
    while(l<r)
    {
        if(a[l]!=a[r]) return 0;
        l++;
        r--;
    }
    return 1;
}


void add(int* a,int* b)
{
    int k=a[0]>b[0]? a[0]:b[0];
    for(int i=1;i<=k;++i)
    {
        a[i+1]+=(a[i]+b[i])/10;
        a[i]=(a[i]+b[i])%10;
    }
    if(a[k+1]>0) a[0]=k+1;
    else    a[0]=k;
}





void printnum(int* a)
{
    int size=a[0];
    for(int i=size;i>=1;i--)
    {
        printf("%d",a[i]);
    }
}

void copy(int*a,int*b)
{
    int size=b[0];
    for(int i=0;i<=size;++i)
    {
        a[i]=b[i];
    }
}

int main()
{
    string number;
    cin>>number;
    memset(num,0,sizeof(num));
    memset(renum,0,sizeof(renum));
    memset(tmp,0,sizeof(tmp));
    num[0]=number.size();
    for(int i=1;i<=num[0];++i)
    {
        num[i]=number[num[0]-i]-'0';
    }

        

    int count=10;
    if(ispa(num))
    {
        printnum(num);
        printf(" is a palindromic number.\n");
        return 0;
    }

    while(count)
    {
        copy(tmp,num);
        re();
        add(num,renum);
        printnum(tmp); printf(" + "); printnum(renum); printf(" = ");printnum(num);
        printf("\n");
        if(ispa(num))
        {
            printnum(num);
            printf(" is a palindromic number.\n");
            return 0;           
        }
        count--;
    }

    printf("Not found in 10 iterations.\n");
    

    return 0;
}