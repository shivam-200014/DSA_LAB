
//stack using linked list

#include<stdio.h>
#include<stdlib.h>

struct lifo{
	int data;
	struct lifo *next;
};

typedef struct lifo stacknode;

void push(int data,stacknode **top,stacknode **ptr)
{
	stacknode *newnode=(stacknode*)malloc(sizeof(stacknode));
	newnode->data=data;
	newnode->next=NULL;
	//insert
	newnode->next=*ptr;
	*ptr=newnode;
	*top=newnode;
}

int pop(stacknode **ptr,stacknode **top)
{
	stacknode *front=*ptr;
	if(front==NULL)
		return -1;
	else
	{
		int p_value=front->data;
		*ptr=front->next;
		free(front);
		*top=*ptr;
		return p_value;
	}
}

int peek(stacknode *top)

{
	if(top==NULL)
	{
		printf("empty stack\n");
		return -1;
	}
	else
	{
		return top->data;
	}

}

void display(stacknode *front)
{
	while(front!=NULL)
	{
		printf("%d ",front->data);
		front=front->next;
	}
	printf("\n");
}

int main()
{
	stacknode *stack=NULL;
	stacknode *top=stack;
	//operation
	push(1,&top,&stack);
	push(3,&top,&stack);
	push(7,&top,&stack);
	push(10,&top,&stack);
	printf("%d\n ",peek(top));
	display(stack);
	pop(&stack,&top);
	display(stack);
}

