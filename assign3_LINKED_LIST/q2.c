//doubly linked list and implementation of all operation
#include<stdio.h>
#include<stdlib.h>

 typedef struct node{
    int data;
    struct node *pre;
    struct node *next;
}node;

void front_ins(int data,node **ptr)
{
    node *head=*ptr;
    //node creation
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->pre=NULL;
    new->next=NULL;
    //insertion
    new->next=head;
    if(head!=NULL)
        head->pre=new;
    *ptr=new;
}

void end_ins(int data,node **ptr)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->pre=NULL;
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
        new->pre=head;
    }
}

void gen_ins(int pos,int data,node **ptr)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->pre=NULL;
    new->next=NULL;
    node *head=*ptr;
    if(pos==1)
    {
        new->next=head;
        head->pre=new;
        *ptr=new;
    }
    else{
        pos-=2;
        while(pos--)
        {
            head=head->next;
        }
        node *curr=head->next;
        if(curr!=NULL){
            curr->pre=new;
        }
        new->next=curr;
        new->pre=head;
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
        (*ptr)->pre=NULL;
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
        node *pre=head;
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
        (*ptr)->pre=NULL;
        free(head);
    }
    else{
        pos-=2;
        while(pos--)
            head=head->next;
        node *curr=head->next;
        if(curr->next!=NULL)
        {   
            node *forw=curr->next;
            forw->pre=head;
        }
        head->next=curr->next;
        free(curr);
    }
}

void print_list(node *head)
{
    node *temp=NULL;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        temp=head;
        head=head->next;
    }
    printf("\n");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->pre;
    }
    printf("\n");
}

int main()
{
    node *head=NULL;
    front_ins(1,&head);
    end_ins(2,&head);
    front_ins(0,&head);
    gen_ins(1,-1,&head);
    gen_ins(5,3,&head);
    gen_ins(4,4,&head);
    gen_del(1,&head);
    gen_del(5,&head);
    gen_del(2,&head);
    //front_del(&head);
    //end_del(&head);
    print_list(head);

}