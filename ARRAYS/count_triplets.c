#include<stdio.h>
void selection_sort(int a[],int n);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
    int count=0;
    for(int i=0;i<n;++i)
    {
        int in=0;
        int sum=0;
        int k=i+1;
        for(int j=i+1;j<n;++j)
        {
            if(in==0)
            {
                sum=a[i]+a[j];
                in++;
            }
            else if(sum==a[j])
            {
                count++;
                j=k++;
                in=0;
                sum=0;
            }
            else if(j==n-1)
            {
                j=k++;
                in =0;
                sum=0;
            }
        }
    }
    printf("%d",count);
    

}

void selection_sort(int a[],int n)
{
    for(int i=0;i<n;++i)
    {
        int l=a[i];
        int k=i;
        for(int j=i+1;j<n;++j)
        {
            if(l>a[j])
            {
                l=a[j];
                k=j;
            }
        }
        a[k]=a[i];
        a[i]=l;
    }
}