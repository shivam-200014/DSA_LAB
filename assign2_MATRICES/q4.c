
#include<stdio.h>

void print_arr(int *ptr)
{
	for(int i=0;i<6;++i)
		printf("%d ",ptr[i]);
	printf("\n");
}

int main()
{
	int count=0;
	int row_major1[6];//utm
	int col_major1[6];//utm
	int row_major2[6];//ltm
	int col_major2[6];//ltm
	int k1=0,k2=0;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			int d;
			scanf("%d",&d);
			if(j>=i)//upper triangle
			{
				row_major1[k1++]=d;
				int in =j*(j+1)/2+i;
				col_major1[in]=d;
			}
			if(j<=i)//lower triangle
			{
				row_major2[k2++]=d;
				int in=(5*j+2*i-j*j)/2;
				col_major2[in]=d;
			}
			
		}
	}
	for(int i=0;i<6;++i)
	{
		if(row_major1[i]==col_major2[i])
			count++;
	}
        if(count!=6)
        {

                printf("error:input matrix must be a symmetric\n");
                return 0;

        }

	else
	{
		printf("row major:\n");
		print_arr(row_major1);
		print_arr(row_major2);
		printf("col major:\n");
		print_arr(col_major1);
		print_arr(col_major2);
		
	}/*
        for(int i=0;i<6;++i)
        {
                printf("%d ",row_major1[i]);
        }
        printf("\n");*/

		
}	

