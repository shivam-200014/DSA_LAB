#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr=(int*)malloc(sizeof(int));
    *ptr=6;
    printf("%d \n",*ptr);
    int *v=ptr;
    free(v);
    printf("%d \n",*ptr);
}
