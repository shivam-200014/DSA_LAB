// attack of queens
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool check(char** arr,int row,int col,int n)
{
    int i, j;
 
    for (i = 0; i < col; i++)
        if ((int)(arr[row][i]-'0'))
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if ((int)(arr[i][j]-'0'))
            return false;
 
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if ((int)(arr[i][j]-'0'))
            return false;
 
    return true;
}

bool solve(char** arr,int col,int n)
{
  int i;
  if(col>=n)
  return true;
  
  
   for(i=0;i<n;i++)

     {
        if(check(arr,i,col,n))
        {
            arr[i][col]='Q';
          
          if(solve(arr,col+1,n))
          return true;
          
          arr[i][col]='0';
        }
     }
  return false;
}
void main()
{
    int n,i,j;
    char **arr;
    printf("Enter the number of queens:");
    scanf("%d",&n);
    
    arr=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++)
    arr[i]=(char*)malloc(n*sizeof(char));
    
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        arr[i][j]='0';
    }
    j=0;
    solve(arr,j,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
}