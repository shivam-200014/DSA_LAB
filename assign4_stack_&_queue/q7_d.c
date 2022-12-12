//bucket sort
//used for sorting floting point numbers ranging from [0.0 to 1.0)
#include<stdio.h>

int max(int x,int y)
{
    if(x>=y)
        return x;
    else
        return y;
}

void insertion_sort(float a[],int n)
{
    for(int i=0;i<n;++i)
    {
        float v=a[i];
        for(int j=i-1;j>=0;--j)
        {
            if(a[j]>v)
            {
                a[j+1]=a[j];
                a[j]=v;
            }
        }
    }
}

void bucket_sort(float a[],int n)
{
    int b_size=0;
    for(int i=0;i<n;++i)
    {
        int d=a[i]*10;
        b_size=max(b_size,d);
    }
    float b[b_size+1][n];
    int i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
    i0=i1=i2=i3=i4=i5=i6=i7=i8=i9=0;
    for(int i=0;i<n;++i)
    {
        int d=a[i]*10;
        switch(d)
        {
            case 0:{
                b[0][i0++]=a[i];
                break;
            }
            case 1:{
                b[1][i1++]=a[i];
                break;
            }
            case 2:{
                b[2][i2++]=a[i];
                break;
            }
            case 3:{
                b[3][i3++]=a[i];
                break;
            }
            case 4:{
                b[4][i4++]=a[i];
                break;
            }
            case 5:{
                b[5][i5++]=a[i];
                break;
            }
            case 6:{
                b[6][i6++]=a[i];
                break;
            }
            case 7:{
                b[7][i7++]=a[i];
                break;
            }
            case 8:{
                b[8][i8++]=a[i];
                break;
            }
            case 9:{
                b[9][i9++]=a[i];
                break;
            }
        }
    }
    for(int i=0;i<10;++i)
    {
        switch(i)
        {
            case 0:{
                insertion_sort(b[i],i0);
                break;
            }
            case 1:{
                insertion_sort(b[i],i1);
                break;
            }
            case 2:{
                insertion_sort(b[i],i2);
                break;
            }
            case 3:{
                insertion_sort(b[i],i3);
                break;
            }
            case 4:{
                insertion_sort(b[i],i4);
                break;
            }
            case 5:{
                insertion_sort(b[i],i5);
                break;
            }
            case 6:{
                insertion_sort(b[i],i6);
                break;
            }
            case 7:{
                insertion_sort(b[i],i7);
                break;
            }
            case 8:{
                insertion_sort(b[i],i8);
                break;
            }
            case 9:{
                insertion_sort(b[i],i9);
                break;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        if(i<i0)
            a[i]=b[0][i];
        else if(i>=i0&&i<i0+i1)
        {
            static int j=0;
            a[i]=b[1][j++];
        }
        else if(i>=i0+i1&&i<i0+i1+i2)
        {
            static int j2=0;
            a[i]=b[2][j2++];
        }
        else if(i>=i0+i1+i2&&i<i0+i1+i2+i3)
        {
            static int j3=0;
            a[i]=b[3][j3++];
        }
        else if(i>=i0+i1+i2+i3&&i<i0+i1+i2+i3+i4)
        {
            static int j4=0;
            a[i]=b[4][j4++];
        }
        else if (i>=i0+i1+i2+i3+i4&&i<i0+i1+i2+i3+i4+i5)
        {
            static int j5=0;
            a[i]=b[5][j5++];
        }
        else if(i>=i0+i1+i2+i3+i4+i5&&i<i0+i1+i2+i3+i4+i5+i6)
        {
            static int j6=0;
            a[i]=b[6][j6++];
        }
        else if(i>=i0+i1+i2+i3+i4+i5+i6&&i<i0+i1+i2+i3+i4+i5+i6+i7)
        {
            static int j7=0;
            a[i]=b[7][j7++];
        }
        else if(i>=i0+i1+i2+i3+i4+i5+i6+i7&&i<i0+i1+i2+i3+i4+i5+i6+i7+i8)
        {
            static int j8=0;
            a[i]=b[8][j8++];
        }
        else if(i>=i0+i1+i2+i3+i4+i5+i6+i7+i8)
        {
            static int j9=0;
            a[i]=b[9][j9++];
        }

        
    }

}

int main()
{
    int n;
    printf("enter array size:");
    scanf("%d",&n);
    float a[n];
    printf("enter array elements:");
    for(int i=0;i<n;++i)
    {
        scanf("%f",&a[i]);
    }
    bucket_sort(a,n);
    for(int i=0;i<n;++i)
    {
        printf("%f ",a[i]);
    }
    printf("\n");

}