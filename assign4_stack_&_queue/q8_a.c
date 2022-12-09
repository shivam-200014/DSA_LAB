//linear search
#include<stdio.h>

void linear_search(int A[],int n,int key)
{
    for(int i=0;i<n;++i)
    {
        if(key==A[i])
        {
            printf("1\n");
            return;
        }
    }
    printf("0\n");
    return;
}

int main()
{
    int n;//array size
    printf("enter array size:");
    scanf("%d",&n);
    int A[n];
    printf("enter array elements\n");
    for(int i=0;i<n;++i)//read array 
        scanf("%d",&A[i]);
    int key;
    printf("enter key:");
    scanf("%d",&key);//key to searched
    linear_search(A,n,key);
    
}