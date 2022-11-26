#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
	int exp;
};

typedef struct node node;

node *gen_ins(int pos,int data,int exp,node *head)
{
		node* new=(node*)malloc(sizeof(node));
		new->data=data;
		new->exp=exp;
		new->next=NULL;
		
		if(pos==1)
		{
			if(head==NULL)
				head=new;
			else{
				new->next=head;
				head=new;
			}
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

node* add_poly(node *head1,node *head2)
{
	if(head1->exp<head2->exp)
	{
		node *temp=head1;
		head1=head2;
		head2=temp;
	}
	node *head=head1;
	node *pre=head;
    int count=0;
	while(head1!=NULL&&head2!=NULL)
	{
        
		if(head1->exp==head2->exp)
		{
			if(head1->data+head2->data==0)
			{
                if(count==0)
                {
                    node *t1=head1;
                    node *t2=head2;
                    head1=head1->next;
                    pre=head1;
                    head=pre;
                    head2=head2->next;
                    free(t1);
                    free(t2);
                }
                else{
                    count++;
                    pre->next=head1->next;
                    free(head1);
                    head1=pre->next;
                    head2=head2->next;
                    if(head1==NULL)
                    {
                        pre->next=head2;
                        break;
                    }
                    
                }
			}
			else
			{
                count++;
				head1->data=head1->data+head2->data;
                if(head1->next==NULL)
                {
                    head1->next=head2->next;
                    break;
                }
                else{
                    pre=head1;
                    head1=head1->next;
				    head2=head2->next;
                }
				
			}
		}
		else
		{
            count++;
			if(head1->next!=NULL)
			{
				if(head2->exp>(head1->next)->exp)
				{
					node *tail=head2->next;
					head2->next=head1->next;
					head1->next=head2;
                    pre=head2;
					head1=head2->next;
                    head2=tail;
				}
				else if(head2->exp<(head1->next)->exp)
                {
                    pre=head1;
					head1=head1->next;

                }
                else{
                    pre=head1;
                    head1=head1->next;
                    if(head1->data+head2->data==0)
                    {
                        
                        pre->next=head1->next;
                        free(head1);
                        head1=pre->next;
                        head2=head2->next;
                    }
                    else
                    {
                        head1->data=head1->data+head2->data;
                        if(head1->next==NULL)
                        {
                            head1->next=head2->next;
                            head1=NULL;
                        }
                        else{
                            pre=head1;
                            head1=head1->next;
                            head2=head2->next;
                        }
                        
                    }
                }
			}
            else{
                if(head1->exp>head2->exp)
                    head1->next=head2;
                break;
            }
        }
	}
    if(head==NULL)
        pre->next=head2;
    return head;
}
void print_poly(node *head)
{
    if(head==NULL)
    {
        printf("no terms left\n");
    }
    else{
        while(head->next!=NULL)
        {
            char ch;
            if((head->next)->data>=0)
                ch='+';
            else
                ch=' ';
            printf("%dx^(%d)%c",head->data,head->exp,ch);
            head=head->next;
        }
        printf("%dx^(%d)\n",head->data,head->exp);
    }
}

int main()
{
    node *h1=NULL;
    node *h2=NULL;
    h1=gen_ins(1,2,3,h1);
    //h1=gen_ins(2,5,2,h1);
    ////h1=gen_ins(3,-2,1,h1);
    h1=gen_ins(2,8,0,h1);
    h2=gen_ins(1,2,3,h2);
    h2=gen_ins(2,3,2,h2);
    h2=gen_ins(3,2,1,h2);
    h2=gen_ins(4,5,0,h2);
    print_poly(h1);
    print_poly(h2);
    node *head=add_poly(h1,h2);
    print_poly(head);
}