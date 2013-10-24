/*
 * gcd.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <algorithm>


void gcd(int a,int b)
{
	
	// reverse the negative
	if(a < 0)
		a = -a;
	if(b < 0)
		b = -b;
		
	
	while(a && b)
	{
		if(a > b)
			a = a -b;
		else
			b = b-a;
		
	}
	
	if(a)
		cout << a << endl;
	else
		cout << b << endl;
	
}

int gcd_ (int a, int b) {
  int temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return(a);
}

int main()
{
	gcd(12,18);
	gcd(-4,14);
	return 0;
}

