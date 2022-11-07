#include<stdio.h>

void print_arr(int arr[])
{
	for(int i=0;i<6;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int a[3][3];
	//lower triangular matrix
	int row_major[6];
	int col_major[6];
	int count1=0;
	int count2=0;
	int k=0;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			scanf("%d",&a[i][j]);
			if(j>=i)
			{
				row_major[k++]=a[i][j];
				int in=j*(j+1)/2+i;
				col_major[in]=a[i][j];
			}
			if(j>i&&a[i][j]==0)
				count1++;
			if(j<i&&a[i][j]==0)
				count2++;

		}
	}
	if(count1!=3&&count2!=3)
	{
		printf("sorry ! only triangular matrix allowed\n");
		return 0;
	}
	if(count1==3)
	{
	   k=0;
	   for(int i=0;i<3;++i)
           {
                 for(int j=0;j<3;++j)
                 {
                         if(j<=i) 
                         {
                                 row_major[k++]=a[i][j];
                                 int in=(5*j+2*i-j*j)/2;
                                 col_major[in]=a[i][j];
                         }
             	 }  
          }
	}
	
	print_arr(row_major);
	print_arr(col_major);
}
