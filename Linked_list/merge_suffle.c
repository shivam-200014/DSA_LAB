#include<stdio.h>
#include<stdlib.h>
//node
typedef struct node{
            int data;
            struct node *next;
}node;
//insertion

void ins_at_pos(int pos,int data,node **ptr )
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(pos==1)
    {
        newnode->next=*ptr;
        *ptr=newnode;
    }
    else{
        pos-=2;
        node* pre=*ptr;
        while(pos--)
            pre=pre->next;
        newnode->next=pre->next;
        pre->next=newnode; 
    }
}

void del_pos(int pos,node **ptr)
{
    //empty list
    if(*ptr==NULL)
        printf("list is empty\n");
    //1st pos
    else if(pos==1)
    {
        node* curr=*ptr;
        *ptr=(*ptr)->next;
        free(curr);
    }
    //reach pos-1
    else{
        pos-=2;
        node *curr,*pre=*ptr;
        while(pos--)
            pre=pre->next;
        curr=pre->next;//to be deleted
        pre->next=curr->next;
        free(curr);
    }

}

void merge_suffle(node **ptr1,node **ptr2)
{
    node *h1=*ptr1,*h2=*ptr2;
    //h1==null
    if(h1==NULL)
    {
        *ptr1=*ptr2;
    }
    else{

        while(h1!=NULL&&h2!=NULL)
        {
            node *t1=h1->next;
            node *t2=h2->next;
            if(t1==NULL)
            {
                h1->next=h2;
                break;
            }
            else{
                h2->next=h1->next;
                h1->next=h2;
                h1=t1;
                h2=t2;
            }
        }
    }
}

void print_list(node *head)
{
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
    
}

int main()
{
    node *head1=NULL,*head2=NULL;
    ins_at_pos(1,5,&head1);
    ins_at_pos(1,20,&head2);
    ins_at_pos(2,10,&head1);
    ins_at_pos(2,40,&head2);
    ins_at_pos(1,0,&head1);
    //head1=NULL;
    //head1.len<head2.len
    ins_at_pos(4,60,&head1);
    ins_at_pos(5,80,&head1);
    
    print_list(head1);
    print_list(head2);
    merge_suffle(&head1,&head2);
    
    del_pos(7,&head1);
    print_list(head1);
    //print_list(head2);

}