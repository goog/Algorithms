/*
 * typeCONVERT.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>

int main()
{
	int a=10, b = 20;
	long int c;
	c = a * (long int) b;
	cout << "The converted b is : " << (long int) b << endl;
	cout << c << endl;
	return 0;
}

