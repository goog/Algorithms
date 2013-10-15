/*
 * cin.cxx
 * 
 * Copyright 2013 drill <drill@cheng>
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
	int a;
	char s[100];
	cout <<"this is a sample program ."<< endl;
	cout<<endl;
	cout<<"Type your age : ";
	cin >> a;
	
	cout<<"Type your name : ";
	cin >> s;
	
	cout <<endl;
	cout <<"hello " << s <<". you're " << a <<" old " <<endl;
	cout << endl<<endl << "Bye!! " << endl;
	
	
	return 0;
}

