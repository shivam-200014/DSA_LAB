//insertion sort
#include<stdio.h>
#include<stdlib.h>

int  insertion_sort(int a[] ,int n)
{
    int count=0;
    for(int i=1;i<n;++i)
    {
        int v=a[i];
        
        for(int j=i-1;j>=0;j--)
        {
            count++;
            if(a[j]>v)
            {
                a[j+1]=a[j];
                a[j]=v;
            }
        }
        
    }
    return count;  
}

int main()
{
    int n;//array size
    printf("enter array size:");
    scanf("%d",&n);
    int a[n];
    printf("enter array element:");
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int count=insertion_sort(a,n);
    for(int i=0;i<n;++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("no. of comparision:%d\n",count);

}