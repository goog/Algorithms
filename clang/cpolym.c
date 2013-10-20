/*
 * cpolym.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>

typedef struct
{
     void (*move)();
} Animal;

void Animal_move()
{
     printf("Animal move.\n");
}

typedef struct
{
	void (*move)();
} Rabbit;

void Rabbit_move()
{
     printf("Rabbit move.\n");
}



int main()
{
	Animal *panimal;
    Rabbit rabbit;
    
    rabbit.move=Rabbit_move;
	panimal = (Animal*)&rabbit;
	panimal->move();
     
    return 0;
}

