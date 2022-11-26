//total ways of selection

#include <stdio.h>
int nCr(int N, int R){
        if(N == R) return 1;
        if(R == 1) return N;
        if(N < R) return 0;
        return nCr(N-1, R) + nCr(N-1, R-1);
}
int main()
{
        int n,r;
        printf("Enter total no of objects and to select respectively:");
        scanf("%d%d", &n, &r);
        printf("Possible ways: ");
        printf("%d", nCr(n,r));
        return 0;
}

