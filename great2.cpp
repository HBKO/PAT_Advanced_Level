#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int a[1000];
int b[1000];
int c[1000];


void getnumber()
{
    string tmp1,tmp2;
    cin>>tmp1>>tmp2;
    a[0]=tmp1.length();
    b[0]=tmp2.length();
    for(int i=1;i<=a[0];i++) a[i]=tmp1[a[0]-i]-'0';
    for(int i=1;i<=b[0];i++) b[i]=tmp2[b[0]-i]-'0';
}


void printnumber(int *num)
{
    for(int i=0;i<num[0];++i)
    {
        printf("%d",num[num[0]-i]);
    }
    printf("\n");
}


//多项式加法
void greatplus()
{
    if(a[0]>b[0]) c[0]=a[0];
    else c[0]=b[0];
    //进行加法
    for(int i=1;i<=c[0];++i)
    {
        c[i+1]=(a[i]+b[i]+c[i])/10;
        c[i]=(c[i]+a[i]+b[i])%10;
    }
    if(c[c[0]+1]) c[0]++;
}


//高精度比较大小
//1是大于，0是等于，-1是小于
int comparenum(int* num1,int* num2)
{
    if(num1[0]>num2[0]) return 1;
    if(num1[0]<num2[0]) return -1;
    for(int i=1;i<num1[0];++i)
    {
        if(num1[i]>num2[i]) return 1;
        if(num2[i]>num1[i]) return -1;
    }
    return 0;
}


//高精度减法
void greatsub()
{
    
    if(comparenum(a,b)==1)
    {
        c[0]=a[0];
        for(int i=1;i<=c[0];++i)
            c[i]=a[i];
        for(int i=1;i<=c[0];++i)
        {
            if(c[i]<b[i])
            {
                c[i+1]--;
                c[i]=c[i]+10;
            }
            c[i]=c[i]-b[i];
        }
    }
    if(comparenum(a,b)==-1)
    {
        c[0]=b[0];
        for(int i=1;i<=c[0];++i)
            c[i]=b[i];
        for(int i=1;i<=c[0];++i)
        {
            if(c[i]<a[i])
            {
                c[i+1]--;
                c[i]+=10;
            }
            c[i]=c[i]-a[i];
        }
    }
    if(!c[c[0]]) c[0]--;
}


//高精度乘法：高精度乘以低精度
//每一项都乘以低精度，最后再整合
void greatmulti(int* num,int number)
{
    c[0]=num[0];
    for(int i=1;i<=c[0];++i)
    {
        c[i]=num[i]*number;
    }
    //最后进行整合
    int i=1;
    for(i=1;i<=c[0];++i)
    {
        c[i+1]+=(c[i]/10);
        c[i]=c[i]%10;
    }
    while(c[i])
    {
        c[i+1]+=(c[i]/10);
        c[i]=c[i]%10;
        i++;
        c[0]++;
    }
}

//高精度除法：高精度除以低精度
void greatdiv(int* num,int number)
{
    int i=0;
    int d=0;
    c[0]=num[0];
    for(i=num[0];i>0;--i)
    {
        d=d*10+num[i];
        c[i]=d/number;
        d=d%number;
    }
    while(c[c[0]]==0 && c[0]>1) c[0]--;
    //输出结果
    for(i=0;i<c[0];++i)
    {
        printf("%d",c[c[0]-i]);
    }
    printf("\n");
    printf("余数为:%d\n",d);
}


//高精度乘以高精度
//各位相乘得到结果
void greatmul2(int* num1,int* num2)
{
    int ka=num1[0]; int kb=num2[0];
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
    for(int i=2;i<=c[0];++i)
    {
        c[i-1]=c[i];
    }
    c[c[0]]=0;
    c[0]--;
}


//高精度除以高精度



int main()
{
    getnumber();
    printnumber(a);
    printnumber(b);
//    greatplus();
//    greatsub();
//    greatmulti(a,13);
//    printnumber(c);
//    greatdiv(a,13);
    greatmul2(a,b);
    printnumber(c);
    return 0;
}