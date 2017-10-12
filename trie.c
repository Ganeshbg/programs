#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct trienode
{
	struct trienode *child[26];
	bool wordend;
};

struct trienode* getnode(void)
{
	struct trienode *newnode = (struct trienode *)malloc(sizeof(struct trienode));
	newnode->wordend=false;
	for(int i=0;i<26;i++)
	{
		newnode->child[i]=NULL;
	}
	return newnode;
}


void search(struct trienode *root, char *str)
{
	struct trienode *temp=root;
	for(int i=0;i<strlen(str);i++)
	{
		int index=str[i]-'a';
		if(temp->child[index]==NULL)
		{
			printf("NOT FOUND");
			return;
		}
		temp=temp->child[index];
	}
	if(temp!=NULL && temp->wordend==true)
	{
		printf("Yeah Found\n");
	}
	else
	{
		printf("NOT Found\n");
	}
	return;

}
void insert(struct trienode *root, char *str)
{
	struct trienode *temp=root;
	for(int j=0;j<strlen(str);j++)
	{
		int index=str[j]-'a';
		if(temp->child[index]==NULL)
		{
			temp->child[index]=getnode();
		}
		temp=temp->child[index];
	}
	temp->wordend=true;
}

int main()
{
	struct trienode *first = getnode();
	insert(first,"hel");
	insert(first,"hello");
	search(first,"hello");
	search(first,"he");
	return 0;
}
