#include<stdio.h>
#include<stdlib.h>

struct Node
{
    void *data;
    struct Node *next;
};

void push(struct Node **start, void *item, int size)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=malloc(size);
    new_node->next=*start;
    for(int i=0;i<size;i++)
    {
        *(char *)(new_node->data + i)=*(char *)(item + i);
    }
    
    *start=new_node;
    
}
void print(struct Node *start, void (*fpn)(void *))
{
    struct Node *temp;
    temp=start;
    while(temp!=NULL)
    {
        (*fpn)(temp->data);
        temp=temp->next;
    }
}
void printint(void *item)
{
    printf("%d\n",*(int *)item);
}
int main()
{
    struct Node *start=NULL;
    //start->next=NULL;
    int arr[5]={1,2,3,4,5};
    unsigned size=sizeof(int);
    for(int i=0;i<5;i++)
    {
        push(&start, &arr[i],size);
    }
    print(start,printint);
    return 0;
}
