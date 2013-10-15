/*
 * destruct.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <cstdlib>

class array
{
public:
	int size;
	double *data;
	
	array(int s)
	{
		size = s;
		data = new double[s];
	}
	
	~array()
	{
		delete [] data;
		
	}
	
	
	double &operator [](int i)  // & for a[0] = 45 assignment
	{
		if(i<0 || i >= size)
		{
			cerr<< endl<< "out of bounds" << endl;
			exit(EXIT_FAILURE);
		}
		else 
			{
				cout << "reference : " << data[i] << endl;
				return data[i];
			}
	}
	
	
};

int main()
{
	array t(5);
	t[0] = 45;
	t[4] = t[0] + 6;
	cout << t[4] << endl;
	
	t[10] = 7;
	
	return 0;
}

