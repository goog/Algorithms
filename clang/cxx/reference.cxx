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
	cout << "inner x: " << x+1 <<endl;
    return ++x;  // "return x++;" would have been wrong
 
}

int main()
{
	int y;
	preinc(y) = 5;
	cout << y <<endl;
	return 0;
}

