//quick sort

#include<stdio.h>

void swap(int a[],int i,int j)
{
    int v=a[i];
    a[i]=a[j];
    a[j]=v;
}

int partition(int a[],int l,int h)
{
    int v=a[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        while(a[i]<=v)
            i++;
        while(a[j]>v)
            j--;
        if(i<j)
        swap(a,i,j);
    }
    swap(a,l,j);
    return j;
}

void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int j=partition(a,l,h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
    }
}

int  main()
{
    int n;
    printf("enter array size:");
    scanf("%d",&n);
    int a[n];
    printf("enter array element:");
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(int i=0;i<n;++i)
        printf("%d ",a[i]);
    printf("\n");
}