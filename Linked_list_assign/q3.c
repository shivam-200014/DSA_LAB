//circular linked list and operation implementation
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

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

node * ins_end(int data,node *head)
{
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
	}
	return head;
}

node *ins_gen(int pos,int data,node *head)
{
	node *new=(node*)malloc(sizeof(node));
	new->data=data;
	new->next=NULL;
	if (pos==1)
	{
		if(head==NULL)
		{
			new->next=new;
			head=new;
		}
		else{
			node *temp=head;
			while (temp->next!=head)
				temp=temp->next;
			temp->next=new;
			new->next=head;
			head=new;
		}
	}
	else{
		pos-=2;
		node *temp=head;
		while(pos--)
			temp=temp->next;
		new->next=temp->next;
		temp->next=new;
	}
	return head;
}


void print_list(node *head)
{
	if(head==NULL)
	{
		printf("list empty\n");
	}
	else{
		node *temp=head;
		do{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=head);
		printf("\n");
	}
}

node* del_front(node *head)
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else if(head->next==head)//single node
	{
		free(head);
		head=NULL;
	}
	else{
		node *temp=head;
		while (temp->next!=head)
			temp=temp->next;
		temp->next=head->next;
		temp=head;
		head=head->next;
		free(temp);
	}
	return head;
}

node *del_end(node *head)
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else if(head->next==head)
	{
		free(head);
		head=NULL;
	}
	else{
		node *pre =head;
		node *temp=head;
		while (temp->next!=head)
		{
			pre=temp;
			temp=temp->next;
		}
		pre->next=head;
		free(temp);
	}
	return head;
}

node *del_gen(int pos,node *head)
{
	if(pos==1)
	{
		if(head==NULL)
		{
			printf("list is empty\n");
		}
		else if(head->next==head)
		{
			free(head);
			head=NULL;
		}
		else
		{
			node *temp=head;
			while(temp->next!=head)
				temp=temp->next;
			temp->next=head->next;
			temp=head;
			head=head->next;
			free(temp);
		}
	}
	else{
		pos-=2;
		node *temp=head;
		while(pos--)
			temp=temp->next;
		node *curr=temp->next;
		temp->next=curr->next;
		free(curr);
	}
	return head;
}

int main()
{
	node *head=NULL;
	//head=ins_front(0,head);
	//head=ins_front(5,head);
	head=ins_end(0,head);
	head=ins_end(5,head);
	head=ins_gen(3,10,head);
	head=ins_gen(1,-5,head);
	head=ins_gen(2,-3,head);
	head=del_gen(2,head);
	print_list(head);
}
