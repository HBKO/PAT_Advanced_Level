#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int a[1000];
int b[1000];
int c[1000];

//高精度获取数字
void getnumber()
{
    string str1,str2;
    cin>>str1;
    cin>>str2;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    a[0]=str1.length();
    b[0]=str2.length();
    for(int i=1;i<=a[0];++i) a[i]=str1[a[0]-i]-'0';
    for(int i=1;i<=b[0];++i) b[i]=str2[b[0]-i]-'0';
}

//高精度加法
void plusone()
{
    if(a[0]>b[0]) c[0]=a[0];
    else    c[0]=b[0];
    for(int i=1;i<=c[0];++i)
    {
        c[i+1]=(a[i]+b[i])/10;
        c[i]+=(a[i]+b[i])%10;
    }
    if(c[c[0]+1]) c[0]++;
    for(int i=c[0];i>0;--i) printf("%d",c[i]);
}


//高精度比较大小
int compare(int a[],int b[])
{
    if(a[0]>b[0]) return 1;
    if(a[0]<b[0]) return -1;
    for(int i=a[0];i>0;--i)
    {
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return -1;
    }
    return 0;
}


//高精度减法
//a大则返回1
//b大则返回0
//都存在a数组里面
void gminus()
{
    int flag=compare(a,b);
    //表示两个数字相等
    if(flag==0) c[0]=0;
    else if(flag>0)
    {
        for(int i=1;i<=a[0];++i)
        {
            if(a[i]<b[i])
            {
                a[i+1]--;
                a[i]+=10;
            }
            a[i]=a[i]-b[i];
        }
        while(a[a[0]]==0) a[0]--;
    }
    else
    {
        for(int i=1;i<=b[0];++i)
        {
            if(b[i]<a[i])
            {
                b[i+1]--;
                b[i]+=10;
            }
            a[i]=b[i]-a[i];
        }
        a[0]=b[0];
        while(a[a[0]]==0) a[0]--;
    }
    for(int i=a[0];i>0;--i)
        printf("%d",a[i]);
}


//高精度乘以低精度
//0说明最后返回的是0，key值为0
//返回值为1，说明返回值非零
int multi1(int a[],int key)
{
    int i,k;
    if(key==0)
    {
        memset(a,0,1000*sizeof(int));
        a[0]=1;
        return 0;
    }
    //先将所有数字乘一遍
    for(i=1;i<=a[0];++i)
    {
        a[i]=a[i]*key;
    }
    //进行进位判断
    for(i=1;i<=a[0];++i)
    {
        a[i+1]+=(a[i]/10);
        a[i]=a[i]%10;
    }
    //作最后一位的进位判断
    while(a[i])
    {
        a[i+1]=(a[i]/10);
        a[i]=a[i]%10;
        i++;
        a[0]++;
    }
    for(i=a[0];i>0;--i)
        printf("%d",a[i]);
    return 1;
}


//高精度除法
int division(int a[],int key)
{
    int i=0;int d=0;
    c[0]=a[0];
    //得到商和余数
    for(i=a[0];i>0;--i)
    {
        d=d*10+a[i];
        c[i]=d/key;
        d=d%key;
    }
    //得到商
    while(c[c[0]]==0 && c[0]>1) c[0]--;
    //得到余数
    printf("商:=");
    for(i=c[0];i>0;--i)
        printf("%d",c[i]);
    printf("\n");
    printf("余数:=%d\n",d);
    return 1;
}


//高精度乘以高精度
int multi2(int a[],int b[])
{
    int k=a[0]+b[0];
    int ka=a[0];int kb=b[0];
    c[0]=ka+kb+1;
    for(int i=1;i<=ka;++i)
    {
        for(int j=1;j<=kb;++j)
        {
            c[i+j]+=(a[i]*b[j]);
            c[i+j+1]+=(c[i+j]/10);
            c[i+j]=c[i+j]%10;
        }
    }
    if(!c[c[0]]) c[0]--;
    for(int i=c[0];i>1;--i) printf("%d",c[i]);
    return 0;
}



//打印数字
void printnumber()
{
    for(int i=a[0];i>0;--i) printf("%d",a[i]);
    printf("\n");
    for(int i=b[0];i>0;--i) printf("%d",b[i]);
}



int main()
{
    getnumber();
//    plusone();
//    printf("the compare result is %d\n",compare(a,b));
//    gminus();
//    multi1(a,5);
//    division(a,5);
    multi2(a,b);
    return 0;
}
