#include<stdio.h>
#include<stdlib.h>
struct Animal
{
    void (*name)(struct Animal *);
    char *c;
};

struct Dog
{

    struct Animal *dog;

};

struct Cat
{

    struct Animal *cat;
};

void bow(struct Animal *dog)
{
    printf("Dog barks, bow bow:%s\n",dog->c);
}

void mew(struct Animal *cat)
{
    printf("Cat says mew mew:%s\n",cat->c);
}

void sound(struct Animal *animal)
{
    animal->name(animal);
}
int main()
{
    struct Dog dog_main;
    struct Cat cat_main;
    struct Animal ani_dog, ani_cat;
    ani_dog.c="Doggy";
    ani_cat.c="Catty";
    ani_dog.name=&bow;
    ani_cat.name=&mew;
    dog_main.dog=&ani_dog;
    cat_main.cat=&ani_cat;
    dog_main.dog->name=&bow;
    cat_main.cat->name=&mew;
    struct Dog *d = &dog_main;
    struct Cat *c = &cat_main;    
    sound(d->dog);
    sound(c->cat);
    return 0;
}







