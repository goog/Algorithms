/*
 * another-variable.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

using namespace std;

#include <iostream>

// 用引用可以修改调用的参数
void change(double &r, double s)
{
	r = 100;
	s = 200;
}

int main()
{
	double a =3.14159265357;
	
	double &b = a;// double *b = &a;
				   // b are replaced by *b
	b = 89;
	
	cout << "The value of a is:" << a << endl;
	
	double k =3, m =4;
	change(k,m);
	cout << "the k,m is : "<<k<<" "<< m <<endl;
	
	return 0;
}

