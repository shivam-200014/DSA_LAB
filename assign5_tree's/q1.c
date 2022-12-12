//binary tree implementation
#include<stdio.h>

struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *leftchild;
    struct BinaryTreeNode *rightchild;
};

typedef struct BinaryTreeNode BT_Node;


int height(BT_Node *ptr)
{

}

int size(BT_Node *ptr)
{
    if(ptr==NULL)
        return 0;
    else
        return 1+size(ptr->leftchild)+size(ptr->rightchild);
}

void visit(BT_Node *ptr)
{
    printf("%d",ptr->data);
}

void pre0rder(BT_Node *ptr)
{
    if(ptr!=NULL)
    {
        visit(ptr);
        pre0rder(ptr->leftchild);
        pre0rder(ptr->rightchild);
    }
}

void in0rder(BT_Node *ptr)
{
    if(ptr!=NULL)
    {
        in0rder(ptr->leftchild);
        visit(ptr);
        in0rder(ptr->rightchild);
    }
}

void post0rder(BT_Node *ptr)
{
    if(ptr!=NULL)
    {
        post0rder(ptr->leftchild);
        post0rder(ptr->rightchild);
        visit(ptr);
    }
}

void level0rder(BT_Node *ptr)
{
    hy
}