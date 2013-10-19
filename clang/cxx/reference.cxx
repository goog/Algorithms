/*
 * reference.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>


//Returning a reference allows function calls to be assigned to
int& preinc(int& x)
{ 
	cout << "inner x: " << x <<endl;
    return ++x;  // "return x++;" would have been wrong
 
}


void swap(int& a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	
	int x;
	int& foo = x;

	// foo is now a reference to x so this sets x to 56
	foo = 56;
	cout << x <<endl;
	
	
	int a = 12,b = 1234;
	cout <<"before swap: " << a <<" "<< b << endl;
	swap(a,b);
	cout <<"after  swap: " << a <<" "<< b << endl;

	int y;
	preinc(y) = 5;
	cout << y <<endl;
	
	
	int *p = 0;
    int& y1 = *p;    // Segmentation fault
    cout << y1 << endl;
	return 0;
}

