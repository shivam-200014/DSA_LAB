//singly linked list and implementation of all operation
#include<stdio.h>
#include<stdlib.h>

 typedef struct node{
    int data;
    struct node *next;
}node;

void front_ins(int data,node **ptr)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->next=*ptr;
    *ptr=new;
}

void end_ins(int data,node **ptr)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    node *head=*ptr;
    if(head==NULL)
    {
        *ptr=new;
    }
    else{
        while(head->next!=NULL)
            head=head->next;
        head->next=new;
    }
}

void gen_ins(int pos,int data,node **ptr)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    node *head=*ptr;
    if(pos==1)
    {
        new->next=head;
        *ptr=new;
    }
    else{
        pos-=2;
        while(pos--)
        {
            head=head->next;
        }
        new->next=head->next;
        head->next=new;
    }
}

void front_del(node **ptr)
{
    node *head=*ptr;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else{
        *ptr=head->next;
        free(head);
    }
}

void end_del(node **ptr)
{
    node *head=*ptr;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else{
        node *pre=NULL;
        while(head->next!=NULL)
        {
            pre=head;
            head=head->next;
        }
        pre->next=NULL;
        free(head);
    }
}

void gen_del(int pos,node **ptr)
{
    node *head=*ptr;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else if(pos==1){
        *ptr=head->next;
        free(head);
    }
    else{
        pos-=2;
        while(pos--)
            head=head->next;
        node *curr=head->next;
        head->next=curr->next;
        free(curr);
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
    front_ins(1,&head);
    gen_ins(2,1,&head);
    gen_ins(3,3,&head);
    end_ins(2,&head);
    front_ins(0,&head);
    gen_ins(5,5,&head);
    gen_ins(7,7,&head);
    gen_ins(2,2,&head);
    front_del(&head);
    end_del(&head);
    gen_del(4,&head);
    gen_del(1,&head);
    gen_del(4,&head);
    print_list(head);
}