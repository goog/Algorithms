/*
 * high2.c
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


#include <stdio.h>

void find2max(int *a, int n)
{   // initialize two maxmum numbers
	int f1=a[0],f2=a[1];
	if(n < 3)
		printf("the array is too short.");
	if(f1 < f2)
	{
		int temp;
		temp = f1;
		f1 = f2;
		f2 = temp;
	}
	int i;
	for(i=2;i < n;i++)
	{
		if(a[i]< f2)
			continue;
		else if(a[i]> f2 && a[i] < f1)
			f2 = a[i];
		else if(a[i]> f1)
			f1 = a[i];
		}
	// output 	
	printf("the first two maximum numbers are : %d,%d",f1,f2);
}

int main(void)
{
	int a[5] = {12,0,234,123,5};
	find2max(a,5);
	return 0;
}

