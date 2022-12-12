//infix to postfix conversion:
#include<stdio.h>
#include<string.h>

void swap(char a[],int i,int j)
{
    char v=a[i];
    a[i]=a[i+1];
    a[i+1]=v;
}

void ToPostfix(char *exp)
{
    char ans[100];
    for(int i=0;i<strlen(exp);++i)
    {
        if(exp[i]=='*'||exp[i]=='/'||exp[i]=='%')
        {
            char v=exp[i];
            exp[i]=exp[i+1];
            exp[i+1]=v;
            i++;
        }
    }
    for(int i=0;i<strlen(exp)-1;++i)
    {
        if(exp[i]=='+'||exp[i]=='-')
        {
            if(exp[i+1]!='+'&&exp[i+1]!='-')
            {
                swap(exp,i,i+1);
            }
        }
    }
}

int main()
{
    char exp[100];
    printf("enter infix form:");
    scanf("%s",exp);
    ToPostfix(exp);
    printf("postfix form :%s\n",exp);
}
