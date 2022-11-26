//circular DLL and implementation of operation
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *pre;
    struct node *next;
};

typedef struct node node;

node *front_ins(int data,node *head)
{
    //create node
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->pre=NULL;
    new->next=NULL;
    //insert
    if(head==NULL)
    {
        new->next=new;
        new->pre=new;
        head=new;
    }
    else{
        node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=new;
        new->pre=temp;
        new->next=head;
        head->pre=new;
        head=new;
    }
    return head;
}

node* ins_end(int data,node *head)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->pre=NULL;
    //insert it
    if(head==NULL)
    {
        new->next=new;
        new->pre=new;
        head=new;
    }
    else{
        node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=new;
        new->pre=temp;
        new->next=head;
        head->pre=new;
    }
    return head;
}

node* gen_ins(int pos,int data,node *head)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->pre=NULL;
    //insert it
    if(pos==1)
    {
        if(head==NULL)
        {
            new->next=new;
            new->pre=new;
            head=new;
        }
        else{
            node *temp=head;
            while(temp->next!=head)
                temp=temp->next;
            temp->next=new;
            new->pre=temp;
            new->next=head;
            head->pre=new;
            head=new;
        }
    }
    else{
        pos-=2;
        node *temp=head;
        while(pos--)
            temp=temp->next;
        node *curr=temp->next;
        new->next=curr;
        curr->pre=new;
        temp->next=new;
        new->pre=temp;
    }
    return head;
}

node * del_front(node *head)
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
        node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=head->next;
        node *temp1=head->next;
        temp1->pre=temp;
        free(head);
        head=temp1;
    }
}

node* del_end(node *head)
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
        node *temp=head;
        node *pre=head;
        while(temp->next!=head)
        {
            pre=temp;
            temp=temp->next;
        }
        pre->next=head;
        head->pre=pre;
        free(temp);
    }
    return head;
}



node* del_gen(int pos,node *head)
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
        else{
            node *temp=head;
            while(temp->next!=head)
                temp=temp->next;
            node *newhead=head->next;
            temp->next=newhead;
            newhead->pre=temp;
            free(head);
            head=newhead;
        }
    }
    else{
        pos-=2;
        node *temp=head;
        while(pos--)
            temp=temp->next;
        node *curr=temp->next;
        node *forw=curr->next;
        forw->pre=temp;
        temp->next=forw;
        free(curr);

    }
    return head;
}

void print_list(node *head)
{
    node *temp=head;
    if(temp==NULL)
    {
        printf("nothing to print\n");
    }
    else{
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
}

int main()
{
    node *head=NULL;
    head=front_ins(0,head);
    head=front_ins(5,head);
    head=front_ins(10,head);
    head=ins_end(-5,head);
    head=ins_end(-10,head);
    head=gen_ins(1,15,head);
    head=gen_ins(7,-15,head);
    head=gen_ins(2,12,head);
    //head=del_end(head);
    //head=del_end(head);
    //head=del_end(head);
    //head=del_front(head);
    //head=del_gen(2,head);
    print_list(head);
}
