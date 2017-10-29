#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int a[10];
#define MAX 10
int top=-1;
bool isempty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isfull()
{
    if(top<MAX)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void push(int x)
{
    if(!isfull())
    {
        top++;
        a[top]=x;
    }
    else
    {
        printf("Stack full\n");
    }
}
void pop()
{
    if(isempty())
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("%d\n",a[top]);
        top--;
    }
}
void peek()
{
    printf("%d\n",a[top]);
}
int main()
{
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(28);
    push(39);
    push(20);
    push(3);
    push(7);
    push(4);
    pop();
    pop();
    peek();
    return 0;
    
}
