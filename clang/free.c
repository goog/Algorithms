#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *pint;
	pint = malloc(sizeof(int));
	*pint = 12345;
	// declare the second pointer
	int *p = pint;
	
	free(pint);
	printf("%d\n",*pint);  // gcc return 0; content clear;
	printf("%d\n",*p);
	return 0;
}

