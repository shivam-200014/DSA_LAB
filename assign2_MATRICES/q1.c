                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
#include<stdio.h>

void print_arr(int arr[])
{
	for(int i=0;i<9;++i)
	{
			printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int a[3][3];
	int row_major[9];
	int col_major[9];
	int k=0;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			int in=3*(j)+i;
			scanf("%d",&a[i][j]);
			row_major[k++]=a[i][j];
			col_major[in]=a[i][j];
		}
	}
	print_arr(row_major);
	print_arr(col_major);

}

