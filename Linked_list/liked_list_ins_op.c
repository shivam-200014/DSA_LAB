#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* ins_at_begin(int data,struct node** head)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
    
}

struct node* ins_at_end(int data,struct node** head)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    //if head==null
    if(*head==NULL)
    {
        *head=newnode;
        
    }
    //if not
    else{
        struct node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next=newnode;
        
    }
}

void  ins_at_pos(int pos,int data,struct node** head)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    //if pos==1
    if(pos==1)
    {
        newnode->next=*head;
        *head=newnode;
    }
    else{
        //reach pos-1
        struct node* temp=*head;
        pos-=2;
        while(pos--)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }


    
}

void print_list(struct node* head)
{
    struct node* temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");  
}


void del_begin(struct node**head)
{
    //empty list
    if(*head==NULL)
    {
        printf("list is already empty\n");
    }
    //list with atleast 1 node
    else{
        struct node* temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

void del_end(struct node** head)
{
    //empty list
    if(*head==NULL)
    {
        printf("list is empty already\n");
    }
    //non empty list
    else{
        struct node* pre,*curr=*head;
        pre=curr;
        while(curr->next!=NULL)
        {
            pre=curr;
            curr=curr->next;
        }
        pre->next=NULL;
        free(curr);

    }
}

void del_pos(int pos,struct node** head)
{
    //empty list
    if(*head==NULL)
    {
        printf("list is already empty\n");
    }
    //list with 1 node
    else if(pos==1)
    {
        struct node* temp=*head;
        *head=(*head)->next;
        free(temp);
        //*head=NULL;
    }
    //more than 1 node
    else{
        pos-=2;
        struct node* pre=*head;
        while(pos--)
        {
            pre=pre->next;
        }
        struct node* curr=pre->next;
        pre->next=curr->next;
        free(curr);
    }
}

int main()
{
    //insertion at begin
    struct node* head=NULL;//(struct node*)malloc(sizeof(struct node));
    //head->data=5;
    //head->next=NULL;
    ins_at_begin(0,&head);
    ins_at_end(1,&head);
    ins_at_begin(-1,&head);
    ins_at_end(2,&head);
    ins_at_pos(1,-2,&head);
    ins_at_pos(6,3,&head);
    ins_at_pos(2,-1,&head);
    ins_at_pos(4,0,&head);
    ins_at_begin(-3,&head);
    //del_begin(&head);
    //del_end(&head);
    del_pos(1,&head);
    del_pos(1,&head);
    del_pos(7,&head);
    del_pos(3,&head);
    del_pos(3,&head);
    print_list(head);

    

}