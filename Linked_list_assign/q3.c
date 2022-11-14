//circular linked list and operation implementation
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;



node* ins_front(int data,node *head)
{
	//create node
	node *new=(node*)malloc(sizeof(node));
	new->data=data;
	new->next=NULL;
	if(head==NULL)
	{
		new->next=new;
		head=new;
	}
	else{
		
		node *temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=new;
		new->next=head;
		head=new;
	}
	return head;

}


void print_list(node *head)
{
	node *temp=head;
	do{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=head);
}

int main()
{
	node *head=NULL;
	head=ins_front(1,head);
	head=ins_front(5,head);
	print_list(head);
}
