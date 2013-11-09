// hello.cpp: Maggie Johnson
// Description: a program that prints the immortal saying "hello world"

#include <iostream>
#include <iomanip>
using namespace std;


void func1()
{

// set up cout to left-align
//cout <<  setiosflags(ios::left);

for(int i=0;i < 6;i++)
	{
	for(int j =0 ; j <4 ; j++)
		cout <<std::left<<setw(17)<<"Hello World!";
	cout <<endl;
	}
	
}

int main() {
 cout << "Hello World!" << endl;
 cout << "function " << endl;
 func1();
 return 0;
}
