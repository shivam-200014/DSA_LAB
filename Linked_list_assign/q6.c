//count number of nodes
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;

int count_node(node *head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}

void ins_gen(int pos,int data,node **ptr)
{
	//create node
	node *new=(node*)malloc(sizeof(node));
	new->data=data;
	new->next=NULL;
	node *head=*ptr;
	if(pos==1)
	{
		new->next=head;
		*ptr=new;
	}
	else
	{
		pos-=2;
		while(pos--)
			head=head->next;
		new->next=head->next;
		head->next=new;
	}
	
}

void print_list(node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

int main()
{
	node *head=NULL;
	ins_gen(1,0,&head);
	ins_gen(2,10,&head);
	ins_gen(3,20,&head);
	ins_gen(4,25,&head);
	ins_gen(2,5,&head);
	
	print_list(head);
	printf("%d\n",count_node(head));
}

