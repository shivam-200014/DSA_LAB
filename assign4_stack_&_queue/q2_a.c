//infix to prefix conversion:
#include<stdio.h>
#include<string.h>

void swap(char a[],int i,int j)
{
    char v=a[i];
    a[i]=a[j];
    a[j]=v;
}

void ToPrefix(char *exp)
{
    for(int i=0;i<strlen(exp);++i)
    {
        char v=exp[i];
        if(v=='*'||v=='/'||v=='%')
        {
            int j=i;
            while(j>0&&(exp[j-1]!='+'&&exp[j-1]!='-'))
            {
                swap(exp,j-1,j);
                j--;
            }
        }
    }
    for(int i=0;i<strlen(exp);++i)
    {
        char v=exp[i];
        int j=i;
        if(v=='+'||v=='-')
        {
             while(j>0)
             {
                swap(exp,j-1,j);
                j--;
             }
        }
    }

}

int main()
{
    char exp[100];
    printf("enter infix form:");
    scanf("%s",exp);
    ToPrefix(exp);
    printf("prefix form:%s",exp);
}