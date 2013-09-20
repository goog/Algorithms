/*
 * pointer_a1.c
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

int main(void)
{
	int a[10] ={1};
	printf("%p\n",&a[0]+1);
	printf("%p\n",(int*)&a+1);
	printf("%p\n",(int*)((char*)&a+sizeof(int)));
	// 首先将a的首地址当成一个char*类型的，这时候+1表示偏移一个char，也就是一个字节，实习应该偏移4个字节
	
	long long e = 1, b = 2, c = 3;
    printf("%d %d %d\n", e, b, c);
	return 0;
}

