//postfix expression evaluation

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lifo{
	int data;
	struct lifo *next;
};

typedef struct lifo s_node;

void push(int data,s_node **top)
{
	s_node *newnode=(s_node*)malloc(sizeof(s_node));
	newnode->data=data;
	newnode->next=NULL;
	//insert
	newnode->next=*top;
	*top=newnode;
}

int pop(s_node **top)
{
    if((*top)==NULL)
        return -1;
    else{
        int top_value=(*top)->data;
        s_node *temp=*top;
        *top=temp->next;
        free(temp);
        return top_value;
    }
}

int peek(s_node *top)
{
    if(top==NULL)
        return -1;
    else
        return top->data;
}

void evaluate(char *exp)
{
	s_node *top=NULL;
	for(int i=0;i<strlen(exp);++i)
	{
		if(exp[i]>=48&&exp[i]<=57)
			push(exp[i]-'0',&top);
		else{
			int y=top->data;
			int x=(top->next)->data;
			pop(&top);
			pop(&top);
			switch(exp[i])
			{
				case '*':{
					push(x*y,&top);
					break;
				}
				case '/':{
					push(x/y,&top);
					break;
				}
				case '%':{
					push(x%y,&top);
					break;
				}
				case '+':{
					push(x+y,&top);
					break;
				}
				case '-':{
					push(x-y,&top);
					break;
				}
			}
		}
	}
	printf("result:%d\n",top->data);
}

int main()
{

	char exp[100];
	scanf("%s",exp);
	evaluate(exp);
}

