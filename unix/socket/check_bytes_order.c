#include <stdio.h>

int main()
{
	union
	{
	short num;
	char s[sizeof(short)];	
	}un;
	
	un.num = 0x0102;
	if(sizeof(short) != 2)
		printf("the size of short is %ld\n", sizeof(short));	
	else if(un.s[0] == 1 && un.s[1] == 2)
		printf(" big endian.");
	else if(un.s[0] == 2 && un.s[1] == 1)
		printf("little endian.");
	else
		printf("i dont know.");
	return 0;
}
