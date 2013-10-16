/*
 * 
 * function pointer
 */
#include<stdio.h>
#include<stdlib.h>

 

void test()

{

    printf("test called!\n");

}

 

int main()

{

   void (*f) ();
   f = test;

   f();
   printf("------------------OOOOOO\n");
   (*f)();

    //test++;             // error，标准禁止对指向函数的指针进行自增运算

    //test = test + 2;        //error，不能对函数名赋值，函数名也不能用于进行算术运算

	printf("%p\n", test);
	printf("%p\n", &test);
	printf("%p\n", *test);
	
	return 0;

}
