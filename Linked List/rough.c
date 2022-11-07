#include<stdio.h>
#include<string.h>

void foo(char *s)
{
    //printf("%d\n",strlen(s));
    while(*s!='\0')
    {
        printf("%c ",*s);
        s++;
    }
    char st[]="temp";
    strcpy(s,st);
}

int main()
{
    char s1[100]={'\0'};//="ravan";
    //strrev(s1);
    //printf("%s\n",s1);
    foo(s1);
    printf("%s\n",s1);


}