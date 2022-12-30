//BST_search
#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right; 
};

typedef struct TreeNode TreeNode;

int BST_search(TreeNode* root,int val)
{
    while (1)
    {
        if(root==NULL)
            return 0;
        else if(root->val==val)
            return 1;
        else if(val<root->val)
            root=root->left;
        else if(val>root->val)
            root=root->right;
    }
    
}

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

int main()
{
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    root->left=root->right=NULL;
    root->val=10;
    BST_insert(&root,100);
    BST_insert(&root,20);
    BST_insert(&root,8);
    BST_insert(&root,34);
    BST_insert(&root,29);
    BST_insert(&root,42);
    BST_insert(&root,38);
    BST_insert(&root,150);
    printf("%d\n",BST_search(root,140));
}