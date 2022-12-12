
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define MAX 1000
struct node{
char name[30];
struct node *next; 
};

typedef struct node Qnode;

typedef struct node2{
Qnode *queue_front, *queue_rear;
} Queue;

void create(Queue *q){
    q->queue_front=q->queue_rear=NULL;
}

void enqueue (Queue *q, char x[]) {
Qnode *temp;
temp= (Qnode *)malloc(sizeof(Qnode));
if (temp==NULL){
printf("Bad Allocation \n"); 
return;
}
strcpy(temp->name,x); 
temp->next=NULL;
if(q->queue_rear==NULL) {
q->queue_rear=temp;
q->queue_front=q->queue_rear; }
else
{ q->queue_rear->next=temp; 
q->queue_rear=temp;
}
return;
}


char *dequeue(Queue *q,char x[]) {
Qnode *temp_pnt;
if(q->queue_front==NULL){
    q->queue_rear=NULL; 
    printf("Queue is empty \n"); 
    return(NULL);
}else{
strcpy(x,q->queue_front->name); 
temp_pnt=q->queue_front; 
q->queue_front=q->queue_front->next; 
free(temp_pnt);
if(q->queue_front==NULL) 
q->queue_rear=NULL; 
return(x);
}
 
}
void enqueuelikestack(Queue *q,char name[]){
    Queue *q2;
    q2=(Queue*)malloc(sizeof(Queue));
    enqueue(q2,name);
    display(q2);
    while(q->queue_front!=NULL){
        char name2[1000];
        char *name3=dequeue(q,name2);
        enqueue(q2,name3);
    }
    while(q2->queue_front!=NULL){
        char name2[1000];
        char* name3=dequeue(q2,name2);
        enqueue(q,name3);
    }
}
void display(Queue *q){
    Qnode *a=q->queue_front;
    while(a!=NULL){
      printf("%s\n",a->name);
      a=a->next;
    }
}
int main(){
    Queue q;
    create(&q);
    int choice;
    printf("\n1.To push\n2.To pop\n3.To display\n0.To exit\n");
    scanf("%d",&choice);
    while(choice){
    switch(choice){
        case 1:{
            char n[MAX];
            printf("Enter the word to insert:");
            scanf("%s",n);
            enqueuelikestack(&q,n);
            break;
        }
        case 2:{
            char name2[MAX];
            printf("The element removed is %s",dequeue(&q,name2));
            break;
        }
        case 3:{
            display(&q);
            break;
        }
        default:{
            printf("Invalid choice\n");
        }
    }
    printf("\n1.To push\n2.To pop\n3.To display\n0.To exit\n");
    scanf("%d",&choice);
    
        }
    return 0;
}