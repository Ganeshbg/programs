#ifndef DOG_H
#define DOG_H
#include<iostream>
using namespace std;

class Dog
{
    public:
        Dog(string);
        ~Dog();
        void bark();
    private:
        string name;
};
#endif