//reverse linked list via iterative approach
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
        while (pos--)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;   
    }
    return head;
}

node *rev_list(node *head)
{
    node *pre,*curr,*forw;
    pre=NULL;
    curr=head;
    while(curr!=NULL)
    {
        forw=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forw;
    }
    return pre;
}

void print_list(node *head)
{
    if(head==NULL)
    {
        printf("\n");
        return ;
    }
    else{
        printf("%d ",head->data);
        head=head->next;
        print_list(head);
    }
}

int main()
{
    node *head=NULL;
    head=ins_gen(1,0,head);
    head=ins_gen(2,5,head);
    /*head=ins_gen(3,15,head);
    head=ins_gen(4,20,head);
    head=ins_gen(3,10,head);
    head=ins_gen(1,-5,head);
    head=ins_gen(7,25,head);*/
    print_list(head);
    head=rev_list(head);
    print_list(head);
}
