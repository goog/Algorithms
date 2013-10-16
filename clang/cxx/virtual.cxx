/*
 * virtual.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <cstdio>

class A
{
public:
	A()
	{printf("AA ");
	}
	
	virtual ~A()
	{
	printf("~AA ");	
	}
	
	virtual void fun()
	{
	printf("FA ");	
		
	}
	
};

class B : public A
{
public:
	B()
	{
	printf("BB ");	
	}
	
	~B()
	{
	printf("~BB ");	
		
	}
	
	virtual void fun()
	{
		printf("FB ");
	}
	
	
	
};


int main(int argc, char **argv)
{
	B b;
	A *a = &b;
	a->fun();
	return 0;
}

