// binary tree implementation                               
#include<stdio.h>
#include<stdlib.h>                               
/*
           A
        /     \
       B        C          :CBT
     /  \      /  \
    D     E   F    G
   /
  H
    
*/

struct TreeNode{   

    char val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

//queue
struct Node{
    TreeNode* root;
    struct Node* next;
};

typedef struct Node Node;

void push(TreeNode *root,Node **ptr)
{
    Node *new=(Node*)malloc(sizeof(Node));
    new->root=root;
    new->next=NULL;
    if(*ptr==NULL)
    {
        *ptr=new;
    }
    else{
        (*ptr)->next=new;
        *ptr=new;
    }

}



void pop(Node **ptr)
{
    if(*ptr==NULL)
        return;
    else{
        Node *temp=*ptr;
        *ptr=(*ptr)->next;
        free(temp);
    }
}

int level0rder(Node *front,Node *back)
{
    static int i=0;
    if(front==NULL)
        return i;
    else{
        
        //size of queue
        int count=1;
        Node *temp=front;
        while(temp!=back)
        {
            count++;
            temp=temp->next;
        }
        //

        int j=count;
        while (j--)
        {
            TreeNode *frnt=front->root;
            if(frnt!=NULL)
            {
                printf("%c",frnt->val);
                if(frnt->left!=NULL)
                    push(frnt->left,&back);
                if(frnt->right!=NULL)
                    push(frnt->right,&back);

                pop(&front);
            }
            else
                pop(&front);
        }
        ++i;
        return level0rder(front,back);
    }
}

int size(TreeNode *root)
{
    if(root==NULL)
        return 0;
    else
        return 1+size(root->left)+size(root->right);
}

void visit(TreeNode *root)
{
    printf("%c",root->val);
}

void pre0rder(TreeNode *root)
{
    if(root!=NULL)
    {
        visit(root);
        pre0rder(root->left);
        pre0rder(root->right);
    }
}

void in0rder(TreeNode *root)
{
    if(root!=NULL)
    {
        in0rder(root->left);
        visit(root);
        in0rder(root->right);
    }
}

void post0rder(TreeNode *root)
{
    if(root!=NULL)
    {
        post0rder(root->left);
        post0rder(root->right);
        visit(root);
    }
}

void insert(Node **front,Node **back,char val)
{
    Node *frnt=*front;
    Node *rear=*back;
    //new tree node
    TreeNode *new=(TreeNode*)malloc(sizeof(TreeNode));
    new->val=val;
    new->left=new->right=NULL;
    //insert in queue
    push(new,&rear);
    *back=rear;
    //insert in CBT
    static int i=0;
    TreeNode *root=frnt->root;
    if(i==0)
    {
        root->left=new;
        ++i;
    }
    else{
        root->right=new;
        i=0;
        pop(&frnt);
        *front=frnt;
    }
}

int main()
{
    //tree

    TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
    root->val='A';
    root->left=root->right=NULL;
    Node *front1,*back1;
    front1=(Node*)malloc(sizeof(Node));
    front1->root=root;
    front1->next=NULL;
    back1=front1;
    insert(&front1,&back1,'B');   
    insert(&front1,&back1,'C');
    insert(&front1,&back1,'D');
    insert(&front1,&back1,'E');
    insert(&front1,&back1,'F');
    insert(&front1,&back1,'G');
    insert(&front1,&back1,'H');

    //tree formed

    //queue for level-order
    Node *front,*back;
    front=(Node*)malloc(sizeof(Node));
    front->root=root;
    front->next=NULL;
    back=front;

    printf("pre-order:");
    pre0rder(root);
    printf("\nin-order:");
    in0rder(root);
    printf("\npost-order:");
    post0rder(root);
    printf("\nlevel-order:");
    int height=level0rder(front,back);
    printf("\nDepth of tree:%d",height);
    printf("\nsize of tree:%d",size(root));
    
    


}