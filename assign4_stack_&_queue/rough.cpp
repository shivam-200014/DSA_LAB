#include<iostream>
using namespace std;

void merge(int a[],int l,int mid,int r)
{
    int h=l;
    int i=l;
    int j=mid+1;
    int k;
    int b[r+1];
    while(h<=mid&&j<=r)
    {
        if(a[h]<=a[j])
            b[i++]=a[h++];
        else
            b[i++]=a[j++];

    }
    if(h>mid)
        for(k=j;k<=r;k++)
            b[i++]=a[k];
    else
        for(k=h;k<=mid;k++)
            b[i++]=a[k];
    for(k=l;k<=r;k++)
        a[k]=b[k];
    /*
    int n1=mid-l+1;
    int n2=h-mid;
    int A[n1];
    int B[n2];
    int i=0;
    int j=0;
    //copying
    while(i<=h)
    {
        if(i>=0&&i<=mid)
            A[i]=a[l+i++];
        else
            B[j++]=a[mid+1+i++];
    }
    //
    i=0;
    j=0;
    int k=l;
    while(i<n1&&j<n2)
    {
        if(A[i]<B[j])
            A[k++]=a[i++];
        else
        {
            B[k++]=a[j++];
        }
    }
    while(i<n1)
    {
        A[k++]=a[i++];
    }
    while(j<n2)
    {
        B[k++]=a[j++];
    }
    */

}


void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}



int main()
{
    int n;
    cout<<"enter array size:";
    cin>>n;
    int A[n];
    cout<<"enter array element:";
    for(int i=0;i<n;++i)
        cin>>A[i];
    mergesort(A,0,n-1);
    for(int i=0;i<n;++i)
        cout<<A[i]<<" ";
    cout<<endl;
}