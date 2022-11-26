//merge 2 sorted linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *ins_gen(int pos,int data,node *head)
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
    else{
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

node *merge_sort(node *head1,node *head2)
{
    //head decide
    node *temp=head1;
    if(head1->data>head2->data)
    {
        head1=head2;
        head2=temp;
    }
    node *pre,*curr,*ins;
    pre=head1;
    curr=pre->next;
    ins=head2;
    while(curr!=NULL&&ins!=NULL)
    {
        if(ins->data>=pre->data&&ins->data<curr->data)
        {
            node *tail=ins->next;
            ins->next=curr;
            pre->next=ins;
            pre=ins;
            ins=tail;
        }
        else{
            pre=curr;
            curr=curr->next;
        }
    }
    if(curr==NULL)
    {
        pre->next=ins;
    }
    return head1;
}

void print_list(node *head)
{
    if(head==NULL)
    {
        printf("\n");
        return;
    }
    else{
        printf("%d ",head->data);
        head=head->next;
        print_list(head);
    }
}

int main()
{
    node *head1=NULL;
    node *head2=NULL;
    node *head=NULL;
    head1=ins_gen(1,1,head1);
    head2=ins_gen(1,2,head2);
    head1=ins_gen(2,4,head1);
    //head2=ins_gen(2,5,head2);
    head1=ins_gen(3,6,head1);
    //head2=ins_gen(3,50,head2);
    print_list(head1);
    print_list(head2);
    head=merge_sort(head1,head2);
    print_list(head);
}