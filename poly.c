

#include<stdio.h>
struct Animal
{
    void (*name)(struct Animal *);
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

void bow(struct Animal *doggy)
{
    printf("Dog barks, bow bow: %c",doggy->c);
}

void mew(struct Animal *catty)
{
    printf("Cat says mew mew: %c", catty->c);
}

void sound(struct Animal *animal)
{
    animal->name(animal);
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


