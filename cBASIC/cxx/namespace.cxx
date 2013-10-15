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
#include <cmath>

namespace first
{
	int a;
	int b;
}

namespace second
{
	double a;
	double b;
}



int main()
{
	first::a = 2;
	first::b = 5;
	
	second::a = 6.453;
	second::b = 4.1e4;
	
	cout << first::a + second::a << endl;
	cout << first::b + second::b << endl;
	
	return 0;
}

