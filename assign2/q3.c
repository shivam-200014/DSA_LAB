// program for memory mapping a sparse 2D array into 1D array
// using (row index, col index, values)
#include <stdio.h>
int nonzeroes = 0;
void  print_arr(int n,int arr[]);
void sparse_to_1d(int r, int c, int arr[][c]);
int main(){
    int row, col;
    printf("Enter no of row and col:");
    scanf("%d%d", &row, &col);
    int arr[row][col];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] != 0)
                nonzeroes++;
        }

    sparse_to_1d(row, col, arr);

}
// sparse matrix have significant no of elements as zero
void sparse_to_1d(int r, int c, int arr[][c]){
    int k = 0;
    int values[nonzeroes], row_index[nonzeroes], col_index[nonzeroes];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            if(arr[i][j] != 0){
                values[k] = arr[i][j];
                row_index[k] = i;
                col_index[k] = j;
                k = k + 1;
            }
        }
    printf("%7s","values:");
    print_arr(nonzeroes, values);
    printf("\n%7s", "row:");
    print_arr(nonzeroes,row_index);
    printf("\n%7s", "col:");
    print_arr(nonzeroes, col_index);

}
void print_arr(int n, int arr[]){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}