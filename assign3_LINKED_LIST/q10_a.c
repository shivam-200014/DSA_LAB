//check if elements and arrangement are same or not
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
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void compair(node *head1,node *head2)
{
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
    head1=ins_gen(1,1,head1);
    head2=ins_gen(1,1,head2);
    head1=ins_gen(2,2,head1);
    head2=ins_gen(2,2,head2);
    head1=ins_gen(3,3,head1);
    head2=ins_gen(3,3,head2);
    head1=ins_gen(4,4,head1);
    //head2=ins_gen(4,1,head2);
    print_list(head1);
    print_list(head2);
    compair(head1,head2);
}