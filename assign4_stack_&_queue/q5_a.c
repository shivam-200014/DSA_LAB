//array implementation of queue
#include<stdio.h>

void Enqueue(int a[],int data,int *rear,int front,int max_size)
{
    int rear1=(*rear+1)%max_size;
    if(rear1==front)
        printf("queue is full\n");
    else
    {
        *rear=rear1;
        a[rear1]=data;
    }
}

void Dequeue(int a[],int *front,int rear,int max_size)
{
    if(rear==*front)
        printf("queue is empty\n");
    else
        (*front)=(*front+1)%max_size;
}

void Display(int a[],int front,int rear,int max_size)
{
    while(rear!=front)
    {
        front=(front+1)%max_size; 
        printf("%d ",a[front]); 
    }
    printf("\n");
}

int main()
{
    int n;
    printf("enter size of queue:");
    scanf("%d",&n);
    int queue[n+1];
    int front,rear;
    front=rear=0;
    Enqueue(queue,1,&rear,front,n+1);
    Enqueue(queue,5,&rear,front,n+1);
    Enqueue(queue,10,&rear,front,n+1);
    Enqueue(queue,15,&rear,front,n+1);
    Enqueue(queue,20,&rear,front,n+1);
    Enqueue(queue,25,&rear,front,n+1);
    Display(queue,front,rear,n+1);
    Dequeue(queue,&front,rear,n+1);
    Dequeue(queue,&front,rear,n+1);
    Dequeue(queue,&front,rear,n+1);
    Display(queue,front,rear,n+1);

}