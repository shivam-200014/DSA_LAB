//BST_Findmax
#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right; 
};

typedef struct TreeNode TreeNode;


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


int BST_Findmax(TreeNode* root)
{
    if(root==NULL)
        return -1;
    else{
        while(1)
        {
            if(root->right==NULL)
                return root->val;
            root=root->right;
        }
    }
}

int main()
{
    //root
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    root->left=root->right=NULL;
    root->val=10;
    //nodes
    BST_insert(&root,100);
    BST_insert(&root,20);
    BST_insert(&root,8);
    BST_insert(&root,34);
    BST_insert(&root,29);
    BST_insert(&root,-90);
    BST_insert(&root,380);
    BST_insert(&root,150);
    //findmin
    printf("max:%d\n",BST_Findmax(root));
}