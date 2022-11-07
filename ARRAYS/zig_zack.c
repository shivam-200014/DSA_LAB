//  zig-zag fashion array
    // INPUT: N = 4, A[] = {1,4,3,2}
    // OUTPUT: 1 4 2 3
    // CONSTRAINTS: T = On, S = O1
#include <stdio.h>
#include <stdlib.h>
void swap(int*, int*);
void* zigzag(int, int a[]);
int main()
{
    int n, *p;
    printf("Enter size of array:");
    scanf("%d", &n);
    p = (int*)malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", (p+i));
        
    zigzag(n, p);

    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);
    return 0;
}

void* zigzag(int size, int a[]){
    for(int i = 0; i < size-1; i++){
        if (i%2==0 && a[i]>a[i+1])
            swap(&a[i], &a[i+1]);
        
        else if(i%2!=0 && a[i]<a[i+1])
            swap(&a[i], &a[i+1]);
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b =temp;
}