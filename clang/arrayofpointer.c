/*
 * arrayofpointer.c
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include <stdio.h>

#include <stdio.h>


int main() {
  int *array[3];
  int x = 10, y = 20, z = 30;
  int i;
  array[0] = &x;
  array[1] = &y;
  array[2] = &z;
  
  for (i=0; i< 3; i++) 
  {
	printf("The value of %d= %d ,address is %p \n", i, *(array[i]),array[i]);
  }
  return 0;
}


