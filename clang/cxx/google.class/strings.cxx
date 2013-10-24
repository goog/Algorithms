/*
 * strings.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>


int main (void) {
	string str1 = "To be or not to be, that is the question";
	string str2 = "only ";
	string str3 = str1.substr(6, 12);  //Var.substr(pos, len)
	cout << "str3: " << str3 << endl;  // "or not to be"
	
	cout << "the length of str1: " << str1.length() << endl;
	// 
	str1.insert(32, str2);
	cout << "str1: " << str1 << endl;
	str1.replace(str1.find("to be", 0), 5, "to jump");
	str1.erase(9, 4);
	cout << str1 << endl;
	
	for (unsigned int i = 0; i < str3.length(); i++)
		cout << str3[i]; cout << endl;
}
