/*
 * const-pointer.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>

class SimpleCat
{

public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();
	
	int GetAge() const {return itsAge;}
	void SetAge(int age) {itsAge = age;}
	
private:
	int itsAge;
	
};


SimpleCat::SimpleCat()
{
	cout << "simple cat constructor .. " << endl;
	itsAge =1;
}


SimpleCat::SimpleCat(SimpleCat& thecat)
{
	itsAge = thecat.GetAge();
}


SimpleCat::~SimpleCat()
{
	cout << "simple cat deconstructor .. \n";
}


const SimpleCat & FunctionTwo(const SimpleCat & theCat);


int main()
{
	cout << "making a  cat "<< endl;
	SimpleCat Frisky;
	
	cout << "Frisky is " << Frisky.GetAge() << "years old ." << endl;
	int age = 5;
	Frisky.SetAge(age);
	cout << "calling function two .... " << endl;
	FunctionTwo(Frisky);
	cout << "Frisky is " << Frisky.GetAge() << "years old ." << endl;
	return 0;
}


// function two, passes a ref to a  const object 
const SimpleCat & FunctionTwo(const SimpleCat & theCat)
{
	
	cout << "function two ing.." << endl;
	cout << "Frisky is now " << theCat.GetAge() << "years old" << endl;
	//theCat.SetAge(10);
	return theCat;
	
}



