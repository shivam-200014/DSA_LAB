// tower of hanoi

#include <stdio.h>
void towerOfHanoi(int n, char from, char to, char temp)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from, to);
        return;
    }
    towerOfHanoi(n-1, from, temp, to);
    printf("\n Move disk %d from rod %c to rod %c", n, from, to);
    towerOfHanoi(n-1, temp, to, from);
}
 
int main()
{
    int n;
    printf("Enter no of disk: ");
    scanf("%d", &n);
    char from = 'A';
    char to = 'C';
    char temp = 'B';
    towerOfHanoi(n,from , to, temp);
    return 0;
}