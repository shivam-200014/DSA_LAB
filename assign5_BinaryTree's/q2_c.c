#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

//stack node

struct Node{
	int  mark;
	TreeNode* root;
	struct Node* next;
};

typedef struct Node Node;

//push

void push(TreeNode* root,Node** ptr)
{
	//new node
	Node* new=(Node*)malloc(sizeof(Node));
	new->root=root;
	new->next=NULL;
	//insert
	
	TreeNode* front=(*ptr)->root;
	if(front==NULL)
	{
		*ptr=new;
	}
	else
	{
		new->next=*ptr;
		*ptr=new;
	}
}

//pop

void pop(Node** ptr)
{
	Node* front=*ptr;
	if(front==NULL)
		return;
	else
	{
		*ptr=(*ptr)->next;
		free(front);
	}
}






void BST_in0rder(TreeNode* root,Node *front)

{
	int size=0;
	Node* temp=front;
	while(temp!=NULL)
	{
		size++;
		temp=temp->next;
	}
	while(1)
	{
		if(front->mark==1)
		{
			printf("%d ",(front->root)->val);
			pop(&front);
		}
		else
		{
			
			TreeNode* root=front->root;
			if(root->left!=NULL&&root->right!=NULL)
			{
				pop(&front);
				push(root->right,&front);
				push(root,&front);
				front->mark=1;
				push(root->left,&front);
			}
			else if(root->left!=NULL)
			{
				push(root->left,&front);
			}
			else if((root->right!=NULL))
			{
				pop(&front);
				push(root->right,&front);
				push(root,&front);
				front->mark=1;
			}
			else
			{
				front->mark=1;
			}

		}
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
	TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
	printf("enter root val:");
	scanf("%d",&(root->val));
	root->left=root->right=NULL;

	//create stack
	Node *front=(Node*)malloc(sizeof(Node));
	front->root=root;
	front->next=NULL;
	
	//fiil nodes of bst
	BST_insert(&root,12);
	BST_insert(&root,8);
	BST_insert(&root,18);
	BST_insert(&root,17);
	BST_insert(&root,50);

	//preorder
	BST_in0rder(root,front);
    printf("\n");
    in0rder(root);
	
	
}
