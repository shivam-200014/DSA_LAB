//merge sort

#include<stdio.h>

void merge(int a[],int l,int mid,int r)
{
    int h=l;
    int i=l;
    int j=mid+1;
    int k;
    int b[r+1];
    while (h<=mid&&j<=r)
    {
        if(a[h]<=a[j])
            b[i++]=a[h++];
        else
            b[i++]=a[j++];
        
    }
    if(h>mid)
        for(k=j;k<=r;++k)
            b[i++]=a[k];
    else
        for(k=h;k<=mid;++k)
            b[i++]=a[k];
    for(k=l;k<=r;++k)
        a[k]=b[k];
}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main()
{
    int n;
    printf("enter array size:");
    scanf("%d",&n);
    int a[n];
    printf("enter array element:");
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(int i=0;i<n;++i)
        printf("%d ",a[i]);
    printf("\n");
}