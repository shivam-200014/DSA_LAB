#include<stdio.h>
int missing(int A[],int N);
int main()
{
    int N;
    scanf("%d",&N);
    int A[N-1];
    int i=0;
    for(;i<N-1;++i)
    {
        scanf("%d",&A[i]);
    }
    printf("missing no:%d\n",missing(A,N));
}

int missing(int A[],int N)
{
    int sum=0;
    int i=0;
    for(;i<N-1;++i)
    {
        sum+=A[i];
    }
    int t_sum=(N)*(N+1)/2;
    return t_sum-sum;
}