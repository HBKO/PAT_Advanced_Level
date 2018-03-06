#include<iostream>
#include<cstdio>
using namespace std;
//进行堆排序的宏定义
#define leftchild(index) (2*index+1)
#define rightchild(index) (2*index+2)
#define parent(index) ((index-1)/2)



int a[10]={3,5,2,6,9,4,10,8,7,6};
int heapsize=9;
int temp[10]={0};



void exchange(int r,int l)
{
    int tmp=a[r];
    a[r]=a[l];
    a[l]=tmp;
}

//维护堆的情况
void mainheap(int i)
{
    int largest=i;
    int left=leftchild(i);
    int right=rightchild(i);
    if(left<=heapsize && a[left]>a[largest])
        largest=left;
    if(right<=heapsize && a[right]>a[largest])
        largest=right;
    //如果发生改变了
    if(i!=largest)
    {
        int tmp=a[largest];
        a[largest]=a[i];
        a[i]=tmp;
        mainheap(largest);
    }
}


//建立堆
//把堆中的除了底层的结点全部通过维护堆来进行维护一遍
void buildheap()
{
    heapsize=9;
    for(int i=(heapsize-1)/2;i>=0;--i)
        mainheap(i);
}


//堆排序
void heapsort()
{
    buildheap();
    for(int i=9;i>=1;--i)
    {
        int tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        heapsize--;
        mainheap(0);
    }
}


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


void quicksort(int p,int r)
{
    int Partition(int p,int r);
    if(p<r)
    {
        int q=Partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}

int Partition(int p,int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p;j<r;++j)
    {
        if (a[j]<=x)
        {
            i++;
            exchange(a[i],a[j]);
        }
    }
    exchange(a[r],a[i+1]);
    return i+1;
}


int main()
{
    //    insort();
    //mergesort(0,9);
//    buildheap();
//    heapsort();
    quicksort(0,9);
    for(int i=0;i<10;++i)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}

