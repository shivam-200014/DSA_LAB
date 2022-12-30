//Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

struct Node{
    TreeNode* root;
    struct Node* next;
};

typedef struct Node Node;

void BST_insert(TreeNode** Root,int val)
{
    TreeNode* root=*Root;
    if(root==NULL)
    {
            TreeNode *new=(TreeNode*)malloc(sizeof(TreeNode));
            new->val=val;
            new->left=new->right=NULL;
            *Root=new;
            return;
    }
    
    while(1)
    {

        if(root->val==val)
            return ;
        else if(val<root->val)
        {
            
            if(root->left==NULL)
            {
                TreeNode *new=(TreeNode*)malloc(sizeof(TreeNode));
                new->val=val;
                new->left=new->right=NULL;
                root->left=new;
                return;
            }
            root=root->left;
        }
        else if(val>root->val)
        {
            if(root->right==NULL)
            {
                TreeNode *new=(TreeNode*)malloc(sizeof(TreeNode));
                new->val=val;
                new->left=new->right=NULL;
                root->right=new;
                return;
            }            
            root=root->right;
        }
    }
}




TreeNode* BST_search(TreeNode* root,int val)
{
    while (1)
    {
        if(root==NULL)
            return NULL;
        else if(root->val==val)
            return root;
        else if(val<root->val)
            root=root->left;
        else if(val>root->val)
            root=root->right;
    }
    
}
void push(TreeNode* root,Node **ptr)
{
    //new
    Node* new=(Node*)malloc(sizeof(Node));
    new->root=root;
    new->next=NULL;
    //push
    if(*ptr==NULL)
    {
        *ptr=new;
    }
    else{
        (*ptr)->next=new;
        *ptr=new;
    }
}

void pop(Node** ptr)
{
    if(*ptr!=NULL)
    {
        Node* temp=*ptr;
        (*ptr)=(*ptr)->next;
        free(temp);
    }
}
void level0rder(Node *front,Node *back)
{
    int size=0;
    if(front!=NULL)
    {
        Node* temp=front;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }

        while(size)
        {
            TreeNode* root=front->root;
            printf("%d ",root->val);
            if(root->left!=NULL)
            {
                push(root->left,&back);
                size++;
            }
            if(root->right!=NULL)
            {
                push(root->right,&back);
                size++;
            }
            pop(&front);
            size--;
        }
    }
}
void in0rder(TreeNode* root)
{
    if(root!=NULL)
    {
        in0rder(root->left);
        printf("%d ",root->val);
        in0rder(root->right);
    }
}


int main()
{
    //root
    TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
    root->left=root->right=NULL;
    printf("enter root val:");
    scanf("%d",&(root->val));
    //queue
    Node *front,*back;
    front=(Node*)malloc(sizeof(Node));
    front->root=root;
    front->next=NULL;
    back=front;;
    //insert
    BST_insert(&root,3);
    BST_insert(&root,4);
    BST_insert(&root,5);
    BST_insert(&root,10);
    BST_insert(&root,8);
    BST_insert(&root,3);

    level0rder(front,back);

    //in0rder(root);

}