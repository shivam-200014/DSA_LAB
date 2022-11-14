//reverse linked list via recursive approach
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *ins_gen(int pos,int data,node *head)
{
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
        pos-=2;
        node *temp=head;
        while(pos--)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    return head;
}

node *rev_list(node *curr)
{
    static node *pre=NULL,*forw=NULL;
    if(curr==NULL)
    {
        return pre;
    }
    else{
        forw=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forw;
        return rev_list(curr);
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
    head=ins_gen(1,0,head);
    head=ins_gen(2,5,head);
    head=ins_gen(3,15,head);
    head=ins_gen(4,20,head);
    head=ins_gen(3,10,head);
    head=ins_gen(1,-5,head);
    head=ins_gen(7,25,head);
    print_list(head);
    head=rev_list(head);
    print_list(head);
}