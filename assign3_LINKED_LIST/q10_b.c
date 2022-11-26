//check whether same numbers are present in both linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *gen_ins(int pos,int data,node *head)
{
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
            temp=temp->next;
        new->next=temp->next;
        temp->next=new;
    }
    return head;
}

node *selection_sort(node *head)
{
    node *i=head;
    while(i!=NULL)
    {
        node *k=i;
        int data=i->data;
        node *j=i->next;
        while(j!=NULL)
        {
            if(data>j->data)
            {
                data=j->data;
                k=j;
            }
            j=j->next;
        }
        k->data=i->data;
        i->data=data;
        i=i->next;
    }
    return head;
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


void compair(node *head1,node *head2)
{
    head1=selection_sort(head1);
    head2=selection_sort(head2);
    while (head1!=NULL&&head2!=NULL)
    {
        if(head1->data==head2->data)
        {
            head1=head1->next;
            head2=head2->next;
        }
        else
            break;
    }
    if(head1==NULL&&head2==NULL)
        printf("1\n");
    else
        printf("0\n");
}


int main()
{
    node *head1=NULL;
    node *head2=NULL;
    head1=gen_ins(1,1,head1);
    head1=gen_ins(2,4,head1);
    head1=gen_ins(3,6,head1);
    //head1=gen_ins(4,8,head1);
    head2=gen_ins(1,7,head2);
    head2=gen_ins(2,4,head2);
    head2=gen_ins(3,1,head2);
    head2=gen_ins(4,6,head2);
    print_list(head1);
    print_list(head2);
    compair(head1,head2);
}