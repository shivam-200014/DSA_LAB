
#include <stdio.h>
#include <stdlib.h>
int mergesort(int arr[], int temp[], int l, int r);
int merge(int arr[], int temp[], int l, int m, int r);
int countmergesort(int n, int arr[]){
    int *temp;
    temp = (int*)malloc(n*sizeof(int));
    return mergesort(arr, temp, 0, n-1);
}
int merge(int arr[],int temp[],int l, int m, int r){
    int count=0;
    int i=l, j=m, k=l;
  
  while((i <= m - 1) && (j <= r)){
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    }
    else{
      temp[k++] = arr[j++];
            count += m-1;
      }
    }
  while(i <= m-1)
        temp[k++] = arr[i++];
    while(j <= r)
        temp[k++] = arr[j++];
    for(i = l; i <= r; i++)
        arr[i] = temp[i];
    return count;
}

int mergesort(int arr[], int temp[], int l, int r){
    int count = 0;
    if(l < r){
        int m = (l+r) / 2;
        count += mergesort(arr, temp, l, m);
        count += mergesort(arr, temp, m+1, r);
        count += merge(arr, temp, l, m+1, r);
    }
    return count;
} 
int main()
{
  int n;
  scanf("%d", &n);
    int p[n];
  for(int i = 0; i < n; i++)
    scanf("%d", &p[i]);
  printf("%d",countmergesort(n, p));
  return 0;
}