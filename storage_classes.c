#include<stdio.h>
#include"external.cpp"
static int x=10;

void fun1()
{
    extern int y;
    printf("%d\n",x);
    printf("%d\n",y);
    return;
}
int main()
{
    printf("%d\n",x);
    x=12;
    fun1();
    return 0;
}
