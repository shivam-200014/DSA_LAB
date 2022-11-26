//assign1--prob1
#include<stdio.h>
#include<stdlib.h>

int* SumArray(int A[],int n,int s)
{
    int sum=0,f=-1,l=-1;
    static int j=-1;
    int i=0;
    for(i;i<n;++i)
    {
        if(sum==0)
            f=i;
        sum+=A[i];
        if(sum<s)
            continue;
        else if(sum>s)
        {
            j++;
            i=j;
            sum=0;
        }
        else{
            l=i;
            break;
        }
    }
    if(l==-1)
    {
       static int a[]={-1};
       return a;
    }
    else{
        int *a=(int*)malloc(2*sizeof(int));
        a[0]=f+1;
        a[1]=l+1;
        return a;
    }
}

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int i=0;
    int A[n];
    for(i;i<n;++i)
    {
        scanf("%d",&A[i]);
    }
    int *ptr=SumArray(A,n,s);
    if(ptr[0]==-1)
        printf("-1\n");
    else{
        printf("%d\t%d",ptr[0],ptr[1]);
    }
}