/*
 * test_composer.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * 
 * 
 */


#include <iostream>
#include "composer.h"
#include <string>
using namespace std;

int main ()
{
 cout << "Testing the Composer class." << endl;

 Composer composer;
 composer.set_name("Ludwig van");
 composer.set_yob(1770);
 composer.set_rank();
	cout << composer.getRank() << endl;
	composer.Promote(2);
	composer.Demote(1);
	composer.Display();
}
