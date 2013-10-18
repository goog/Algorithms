/*
 * sizeofSTRUCT.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>

struct DataA
{	
int index;
char tag;		
};

void fun(int number[100])
{
	cout << sizeof(number) << endl;
}

int main(int argc, char **argv)
{
	cout << sizeof(DataA) <<endl;
	int a[] = {1,2,3,4};
	fun(a);
	int *p;
	cout <<"the size of pointer is : " << sizeof(p) <<endl;
	return 0;
}

