// radix sort
#include <stdio.h>
#include <stdlib.h>
int get_max(int a[], int n){
    int my_max = a[0];
    for(int i = 0; i < n; i++)
        my_max = a[i] > my_max ? a[i] : my_max;
    return my_max;
}

void count_sort(int a[], int n, int digit){
    int count[10] = {0};
    int *sorted  = (int*)malloc(n*sizeof(int));

    for(int i=0; i<n; i++)
        count[(a[i]/digit)%10]++ ;
    for(int i=1; i<10; i++)
        count[i] += count[i-1] ;
    for(int i=n-1; i>=0; i--)
        sorted[--count[(a[i]/digit)%10]] = a[i] ;
    for(int i=0; i<n; i++)
        a[i] = sorted[i] ;
}

void radixsort(int a[], int n){
    int max = get_max(a,n);
    for(int digit = 1; max/digit > 0; digit*= 10)
        count_sort(a,n,digit);
}

int main()
{
    int size;
    printf("Enter size:");
    scanf("%d", &size);

    int a[size];
    printf("Enter elements:");
    for(int i = 0; i < size; i++)
        scanf(" %d", &a[i]);

    radixsort(a,size);
    printf("Sorted elements:");
    for (int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    return 0;
}