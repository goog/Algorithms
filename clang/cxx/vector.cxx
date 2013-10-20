/*
 * vector.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


#include<stdio.h>
#include<vector>
#include <iostream>

using namespace std;

int main()

{
	int i = 0;
    vector<int> v;

    for( i = 0; i < 10; i++ )
    {
		v.push_back( i );//把元素一个一个存入到vector中
    }

	for( i = 0; i < v.size(); i++ )//v.size() 表示vector存入元素的个
	{	
		cout << v[i] << "  "; //把每个元素显示出来
	}
	
	cout << endl;

} 
