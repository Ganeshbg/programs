#include<iostream>
#include"Dog.h"
using namespace std;
Dog::Dog(string dogname)
{
    name=dogname;
}
Dog::~Dog()
{}
void Dog::bark()
{
cout<<"My dog name is not "<<name<<endl;
}
int main()
{
    Dog mydog("Gimmy");
    mydog.bark();
    return 0;
}