/*
 * variable-local.cxx
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

int main()
{
	//int i;
	//i =487;
	
	for(int i =0; i < 4 ;i++) // local declaration of i ;
		cout << i << endl;
	
	
	cout << i << endl;
	i += 5;
	cout << i << endl;
	
	return 0;
}

