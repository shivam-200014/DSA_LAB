//linked list imp. of Queue
#include<stdio.h>
#include<stdlib.h>
struct Q_Node{
    int data;
    struct Q_Node *next;
};

typedef struct Q_Node Q_Node;

void Enqueue(int data,Q_Node *front,Q_Node **rear)
{
    if((*rear)->next==front)
        printf("queue is full\n");
    else
    {
        Q_Node *rear1=(*rear)->next;
        rear1->data=data;
        *rear=rear1;
    }
}

void Dequeue(Q_Node **front,Q_Node *rear)
{
    if(*front==rear)
        printf("queue is empty\n");
    else
    {
        *front=(*front)->next;
    }
}

void Display(Q_Node *front,Q_Node *rear)
{
    while(rear!=front)
    {
        front=front->next;
        printf("%d ",front->data);
    }
    printf("\n");
}

void insert(Q_Node **ptr,int size)
{
    
    Q_Node *head=(Q_Node*)malloc(sizeof(Q_Node));
    Q_Node *temp=head;
    for(int i=0;i<size-1;++i)
    {
        Q_Node *new=(Q_Node*)malloc(sizeof(Q_Node));
        temp->next=new;
        temp=new;
    }
    temp->next=head;
    *ptr=head;
}

int main()
{
    Q_Node *front,*rear;
    front=rear=NULL;
    int n;
    printf("enter size of queue:");
    scanf("%d",&n);
    insert(&front,n+1);
    rear=front;
    Enqueue(1,front,&rear);
    Enqueue(5,front,&rear);
    Enqueue(10,front,&rear);
    Enqueue(15,front,&rear);
    Enqueue(20,front,&rear);
    Display(front,rear);
    Dequeue(&front,rear);
    Dequeue(&front,rear);
    Display(front,rear);

}