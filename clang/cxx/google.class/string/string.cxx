using namespace std;
#include <iostream>
#include <fstream>
#include "String.h"
#include <cstring>

//  constructor that initializes from an array of char
String::String(const char *init)
{
	if(init == NULL)
		{
			theChars = new char[1];
			*theChars = '\0';
		}
		
	else
		{
			int length = strlen(init);
			theChars = new char[length+1];
			strcpy(theChars,init);
		}
}

// copy contructor 
String::String(const String& other)
{
	int length = strlen(other.theChars);
	theChars = new char[length+1];
	strcpy(theChars,other.theChars);
}

//  destructor
String::~String()
{
    delete [] theChars;
}

// friend function
ostream& operator << (ostream& out,String right)
{
	out << right.theChars;
	return out;
}



int main(void)
{
	String a("feiyin.com");
	cout << a << endl;
}
