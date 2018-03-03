#include<iostream>
#include<cstdio>
using namespace std;


int a[10]={3,5,2,6,9,4,10,8,7,6};
int temp[10]={0};

void insort()
{
    int key;
    for(int j=1;j<10;++j)
    {
        key=a[j];
        int i=j-1;
        while(i>=0 && a[i]>key)
        {
            a[i+1]=a[i];
            i--;
            //            key=a[i];
        }
        a[i+1]=key;
    }
}


void mergesort(int l,int r)
{
    if(l==r) return;
    int middle=(l+r)/2;
    mergesort(l,middle);
    mergesort(middle+1,r);
    int i1=l;int i2=middle+1;
    //放进另外数组进行存储
    for(int i=l;i<=r;++i)
        temp[i]=a[i];
    for(int curr=l;curr<=r;++curr)
    {
        //数组一到底
        if(i1==middle+1)
            a[curr]=temp[i2++];
        else if(i2>r)
            a[curr]=temp[i1++];
        else if(temp[i1]<temp[i2])
            a[curr]=temp[i1++];
        else
            a[curr]=temp[i2++];
    }
}


int main()
{
    //    insort();
    mergesort(0,9);
    for(int i=0;i<10;++i)
        printf("%d ",a[i]);
    return 0;
}
