//stack using array
#include<stdio.h>
#include<stdlib.h>
#define max 100


struct lifo{
    int A[max];
};

typedef struct lifo LIFO;

void push(int data,LIFO *ptr,int *ptr_top)
{

    int top=*ptr_top;
    top++;
    ptr->A[top]=data;
    (*ptr_top)++;
}

int pop(LIFO *ptr,int *ptr_top)
{
    if(*ptr_top==-1)
        return -1;
    else{
        int value=ptr->A[*ptr_top];
        (*ptr_top)--;
        return value;
    }
}

void display(LIFO *ptr,int top)
{
    if(top==-1)
        printf("stack is empty\n");
    else{
        for(int i=0;i<=top;++i)
        {
            printf("%d ",ptr->A[i]);
        }
        printf("\n");
    }

}

int main()
{
    LIFO *stack;
    int top=-1;
    push(0,stack,&top);
    push(5,stack,&top);
    push(10,stack,&top);
    push(15,stack,&top);
    display(stack,top);
    pop(stack,&top);
    pop(stack,&top);
    display(stack,top);
    
}