/*
 * bisearch.c
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
#include <stdbool.h>

bool biSEARCH(int *a, int low , int high, int x)
{
	int mid;
	while(low <= high)
	{
		mid = (low + high) /2;
		if(a[mid] == x) 
			{printf("the position is %d\n",mid);
			 return true;
			}
		else if (x < a[mid])
			high = mid -1;
			else
				low = mid +1;
	}
	return false;
}

int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d",biSEARCH(a,0,9,9));
	return 0;
}

