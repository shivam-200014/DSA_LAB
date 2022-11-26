#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    int i=0,l=0,td=0;
    for(;i<N;++i)
    {
        scanf("%d",&A[i]);
        int digits;
        if(A[i]==0)
            digits=1;
        else{
            digits=(int)(log10(A[i]))+1;
        }
        if(l<digits)
            l=digits;
        td+=digits;
    }
    char lar[td+1];
    lar[0]='\0';
    i=0;
    for(;i<N;++i)                     //still not nlogn
    {
        char n1[l+1];
        n1[0]='\0';
        itoa(A[i],n1,10);
        int k=i;
        int j;
        for(j=i+1;j<N;++j)
        {
            char n2[l+1];
            n2[0]='\0';
            itoa(A[j],n2,10);
            if(strcmp(n2,n1)>=1)
            {
                strcpy(n1,n2);
                k=j;
            }
        }
        int temp=A[i];
        A[i]=A[k];
        A[k]=temp;
        strcat(lar,n1);
    }

    printf("\n%s",lar);

}