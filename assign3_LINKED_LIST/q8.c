//con_cat 2 linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;

node* ins_gen(int pos,int data,node *head)
{
	//create node
	node *new=(node*)malloc(sizeof(node));
	new->data=data;
	new->next=NULL;
	if(pos==1)
	{
		new->next=head;
		head=new;
	}
	else
	{
		node *temp=head;
		pos-=2;
		while(pos--)
			temp=temp->next;
		new->next=temp->next;
		temp->next=new;
	}
	return head;
	
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


//con_cat

node* con_cat(node *h1,node *h2)
{
	if(h1==NULL)
		h1=h2;
	else
	{
		node *temp=h1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=h2;
	}
	return h1;
}


int main()
{
	node *h1,*h2;
	h1=h2=NULL;
	h1=ins_gen(1,1,h1);
	h1=ins_gen(2,4,h1);
	h1=ins_gen(3,8,h1);
	h1=ins_gen(4,10,h1);
	//h2=ins_gen(1,5,h2);
	//h2=ins_gen(2,10,h2);
	//h2=ins_gen(3,15,h2);
	print_list(h1);
	print_list(h2);
	h1=con_cat(h1,h2);
	print_list(h1);
}

