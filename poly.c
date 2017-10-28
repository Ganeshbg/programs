

#include<stdio.h>
struct Animal
{
    void (*name)();
    char c;
};
struct Dog
{

    struct Animal *dog;

};

struct Cat
{

    struct Animal *cat;
};

void bow()
{
    printf("Dog barks, bow bow\n");
}

void mew()
{
    printf("Cat says mew mew");
}

void sound(struct Animal *animal)
{
    animal->name();
}
int main()
{
    struct Dog *d;
    struct Cat *c;
    struct Animal *animal;
    d->dog->name=&bow;
    c->cat->name=&mew;
    d->dog->c='D';
    c->cat->c='C';
    sound(d->dog);
    sound(c->cat);
    return 0;
}




