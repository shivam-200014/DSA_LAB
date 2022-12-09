//check for balanced parenthesis/brackets...
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lifo{
    char ch;
    struct lifo *next;
};

typedef struct lifo s_node;

void push(char c,s_node **top)
{
    s_node *newnode=(s_node*)malloc(sizeof(s_node));
    newnode->ch=c;
    newnode->next=NULL;
    //insert
    newnode->next=*top;
    *top=newnode;
}

char pop(s_node **top)
{
    if((*top)==NULL)
        return '\0';
    else{
        char top_value=(*top)->ch;
        s_node *temp=*top;
        *top=temp->next;
        free(temp);
        return top_value;
    }
}

char peek(s_node *top)
{
    if(top==NULL)
    {
        //printf("empty stack");
        return '\0';
    }
    else
        return top->ch;
}

int size(s_node *top)
{
    int count=0;
    while(top!=NULL)
    {
        count++;
        top=top->next;
    }
    return count;
}


void is_balanced(char *exp)
{
    s_node *top=NULL;
    for(int i=0;i<strlen(exp);++i)
    {
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
        {
            push(exp[i],&top);
        }
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
        {
            if(exp[i]==')'&&peek(top)=='(')
                pop(&top);
            else if (exp[i]==']'&&peek(top)=='[')
                pop(&top);
            else if(exp[i]=='}'&&peek(top)=='{')
                pop(&top);
            else
                push(exp[i],&top);
        }
    }
    if(size(top)==0)
        printf("balanced\n");
    else
        printf("not balanced\n");
}

int main()
{
    char exp[100];
    printf("enter expression:");
    scanf("%s",exp);
    is_balanced(exp);

}