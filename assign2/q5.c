#include<stdio.h>

void print_arr(int *arr,int x)
{
	for(int i=0;i<x;++i)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int n;
	printf("enter order of sqr matrix:");
	scanf("%d",&n);
	int row_major[3*n-2];
	int col_major[3*n-2];
	int diag_wise[3*n-2];
	int k=0;
	int count=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int d;
			scanf("%d",&d);
			if(i-j==0||i-j==-1||i-j==1)
			{
				//row_major
				row_major[k++]=d;
				//col_major
				if(j==0)
					col_major[i]=d;
				else{
					//static int p=0;
					int in=2+3*(j-1)+(i<j?0:(j<i?2:1));
					col_major[in]=d;
				}
				//daig_wise
				if(i-j>0)
					diag_wise[j]=d;
				else if(i==j)
				{
					diag_wise[n-1+i]=d;
				}
				else
				{
					diag_wise[n-1+n+i]=d;
				}
			}
			else if(d==0)
				count++;
		}
	}
	if(count!=n*n-3*n+2)
	{
		printf("error:input matix must be tridiagonal\n");
		return 0;
	}
	else{
		printf("row major-order:");
		print_arr(row_major,3*n-2);
		printf("col major-order:");
		print_arr(col_major,3*n-2);
		printf("diag wise-order:");
		print_arr(diag_wise,3*n-2);
	}
}
