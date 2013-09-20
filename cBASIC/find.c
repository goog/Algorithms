/*
 * find.c
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

// 找出数组中出现次数超过一半的元素
int Find(int* a, int n)
{
	int key,times=0;
	int i;
	for(i=0;i < n;i++)
		{
			if(times == 0)
				key = a[i],times =1;
			else if (key == a[i])
				times++;
			else
				times--;
		}
	return key;
	
}

int main(void)
{
	int s[7] = {1,1,3,3,3,3,4};
	printf("%d \n",Find(s,7));
	
	return 0;
}

