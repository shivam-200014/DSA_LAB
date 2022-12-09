//insertion sort
#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int **ptr,int n)
{
    int *A=*ptr;
    
}

int main()
{
    int n;//array size
    printf("enter array size:");
    scanf("%d",&n);
    int *ptr=(int*)malloc(n*sizeof(int));
    printf("enter array elements:");
    for(int i=0;i<n;++i)
        scanf("%d",&ptr[i]);
    insertion_sort(&ptr,n);
    for(int i=0;i<n;++i)
        printf("%d ",ptr[i]);
}