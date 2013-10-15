/*
 * strlength.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <cstring>

int main()
{	char *name;

	const char * newName = "google";
	
	cout << "the size of content :" << sizeof(*newName)<< endl;
	
	if (newName) {
		int len = strlen(newName);
		cout << len << endl;  // 6
		name = new char[len+1]; //7
		strcpy(name, newName);
		cout << "The content size of name :" << sizeof(*name)<< endl;
		cout << name << " : " << strlen(name) << endl;
	}
	return 0;
}

