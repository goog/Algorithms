/*
 * 
 * function pointer
 */
#include<stdio.h>
#include<string.h>
 

int main()
{

	char string2[20]="red dwarf";
	char string1[20]="";
	printf("the return of strcpy: %p\n",strcpy(string1, string2));
	printf("the address of string1: %p\n",string1);
	return 0;
}
