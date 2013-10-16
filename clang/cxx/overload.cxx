/*
 * the overload example
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <cmath>

struct vector
{
	double x;
	double y;
	
};

ostream& operator << (ostream& o, vector a)
{
	o << "(" << a.x << "," << a.y <<")";
	return o;
}



int main()
{
	vector a;
	a.x = 35;
	a.y = 23;
	
	cout << a << endl;
	return 0;
}

