/*
 * 
 * 
 * 
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	char c1,c2,c3;
	int i;
	float x;
	double y;
	printf("\n%s\n%s","Input three characters",
			"an int,a float,and a double:   ");
	scanf("%c%c%c%d%f%lf",&c1,&c2,&c3,&i,&x,&y);
	printf("you typed are here:\n");
	printf("%3c%3c%3c%5d%17e%17e\n\n",c1,c2,c3,i,x,y);
	
}


## input ABC 3 55 77.7
