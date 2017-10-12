#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
}*root;



void insert(struct node **head,int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *current, *parent;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	current = *head;
	if(current == NULL)
	{
		*head = temp;
		//printf("here");
	}
	else
	{
	while(1)
	{
		parent = current;
		if(current->data > temp->data)
		{
			current = current->left;
			if(current == NULL)
			{
				parent->left = temp;
				//printf("here1");
				return;
			}
		}
		else
		{
			current = current->right;
			if(current == NULL)
			{
				parent->right = temp;
				//printf("here2");
				return;
			}
		}
	}
   }
}

struct node* delete(struct node **head,int item)
{
	struct node *parent,*child;
	struct node *temp;
	if(*head==NULL)
	{
		printf("empty tree");
		return;
	}
	parent=*head;
	child=*head;
	while(child!=NULL && child->data != item)
	{
		printf("Child is:%d\n",child->data);
		parent = child;
		if(child->data>item)
		{
			child = child->left;
		}
		else
		{
			child = child->right;
		}
	}
	if(child==NULL)
	{
		printf("Item not found\n");
		return;
	}
	else
	{
		if(child->left==NULL && child->right==NULL)
		{
			if(parent->left==child)
			{
				parent->left=NULL;
			}
			else
			{
				parent->right=NULL;
			}
			return NULL;

		}
		if(child->left==NULL && child->right!=NULL)
		{
			if(parent->left==child)
			{
				parent->left=child->right;
			}
			else
			{
				parent->right=child->right;
			}
			temp=child->right;
			free(child);
			return temp;
		}
		if(child->left!=NULL && child->right==NULL)
		{
			if(parent->left==child)
			{
				parent->left=child->left;
			}
			else
			{
				parent->right=child->left;
			}
			temp=child->left;
			free(child);
			return temp;
		}
		if(child->left!=NULL && child->right!=NULL)
		{
			
			
			temp=child->right;
			parent=temp;
			while(temp->left!=NULL)
			{
				parent=temp;
				temp=temp->left;
			}
			
			child->data=temp->data;
			child->right=delete(&child->right,temp->data);
		}
	}
}
void inorder(struct node *head)
{
	struct node *headref;
	headref = head;
	if(headref == NULL)
	{
		return;
	}
	else
	{
		inorder(headref->left);
		printf("%d\n",headref->data);
		inorder(headref->right);
	}
}

void preorder(struct node *head)
{
	struct node *headref;
	headref = head;
	if(headref == NULL)
	{
		return;
	}
	else
	{
		printf("%d\n",headref->data);
		preorder(headref->left);
		preorder(headref->right);
	}
}

void postorder(struct node *head)
{
	struct node *headref;
	headref = head;
	if(headref == NULL)
	{
		return;
	}
	else
	{
		postorder(headref->left);
		postorder(headref->right);
		printf("%d\n",headref->data);
	}
}

int main()
{
	root = NULL;
	insert(&root,21);
	insert(&root,10);
	insert(&root,4);
	insert(&root,5);
	insert(&root,27);
	insert(&root,32);
	insert(&root,29);
	//printf("Inoreder is\n");
	//inorder(root);
	//printf("preoreder is\n");
	//preorder(root);
	//printf("postoreder is\n");
	//postorder(root);
	//delete(&root,5);
	delete(&root,21);
	inorder(root);
	return 0;
}

