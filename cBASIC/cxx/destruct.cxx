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
#include <cstring>

class person
{
public:
	char *name;
	int age;
	
	//constructor 
	person(char *n ="no name", int a = 0)
	{
		name = new char[100];
		strcpy(name,n);
		age = a;
		cout << "Instance initialized,100 bytes allocated." << endl;
	
	}
	
	~person()
	{
		delete name;
		cout << "Instance going to be deleted, 100 bytes freed" << endl;
	}
	
	
};

int main()
{
	person a;
	cout << a.name << ", age " << a.age << endl <<endl;
	
	person b("John");
	cout << b.name << ", age " << b.age << endl <<endl;
	
	return 0;
}

