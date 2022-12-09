//binary search
//only for sorted array
#include<stdio.h>

void binary_search(int A[],int n,int key)
{
    int start,mid,end;
    start=0;
    end=n-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(key==A[mid])
        {
            printf("1\n");
            return;
        }
        else if(key<A[mid])
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    printf("0\n");
}

int main()
{
    int n;//array size
    printf("enter array size:");
    scanf("%d",&n);
    int A[n];
    printf("enter array elements:");//must be sorted(ascending order) 
    for(int i=0;i<n;++i)
        scanf("%d",&A[i]);
    printf("enter key:");
    int key;
    scanf("%d",&key);
    binary_search(A,n,key);
}