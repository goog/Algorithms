/*
 * template.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>

template <class ttype>
ttype minimum(ttype a, ttype b)
{
	if(a <= b)
		return a;
	else
		return b;
}



int main()
{
	int i1,i2,i3;
	i1 =34;
	i2 =6;
	i3 = minimum(i1,i2);
	cout << "Most little : " << i3 <<endl;
	 
	return 0;
}

