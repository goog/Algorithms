/*
 * new-del.cxx
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
	double *d;
	d = new double; // points to a memory zone;
	*d = 5266;
	cout <<"Type a number: ";
	
	cin >> *d;
	*d = *d +5;
	cout <<"The result : " << *d <<endl;
	delete d;
	
	return 0;
}

