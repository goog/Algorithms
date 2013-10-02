/*
 * fork-base.c
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
#include <time.h>


int fib(int);
int fork(void);
void sleep(unsigned);

int main(void)
{
	int begin = time(NULL),i;
	if(fork() == 0 )
		for (i=0;i<30;i++)
			printf("fib(%2d) = %d\n",i,fib(i));
	else
		for (i=0;i<30;i++){
			sleep(2);
			printf("elapased time : %d\n",time(NULL)-begin);
		}
	return 0;
}

int fib(int n){
	
	if(n <=1)
		return n;
	else
		return fib(n-1) + fib(n-2);
	
}
