#include<stdio.h>
#include<stdlib.h>

int k=0;

int * leaders(int A[],int n)
{
    int *B=(int*)malloc(n*sizeof(int));
    static int j=-1;
    int lead=A[++j];
    int i=j+1;
    for(;i<n;++i)
    {
        if(lead<A[i])
        {
            lead=A[++j];
            i=j;
            continue;
        }
        if(i==n-1)
        {
            B[k]=lead;
            k++;
            lead=A[++j];
            i=j;
        }
    }
    B[k]=A[n-1];
    k++;
    return B;
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    int i=0;
    for(;i<n;++i)
        scanf("%d",&A[i]);
    int* p=leaders(A,n);
    i=0;
    for(;i<k;++i)
    {
        printf("%d ",p[i]);
    }

}