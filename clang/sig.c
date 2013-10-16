/*
 * sig.c
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
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int fib(int);
void cntrl_c_handler(int);

int main(void)
{
	int i;
	signal(SIGINT,cntrl_c_handler);
	for(i=0;i<100;i++)
		printf("fib(%2d) = %d\n",i,fib(i));
		sleep(1);
	return 0;
}

void cntrl_c_handler(int sig)
{
	char ANSWER[100];
	printf("\n\n%s%d\n\n%s",
	"interrupt received ! signal = ",sig,
	"do you wish to continue or quit?" );
	scanf("%s",ANSWER);
	if(*ANSWER == 'c')
		{printf("the key C has been pressed.\n");
		signal(SIGINT,cntrl_c_handler);
		}
	else
		exit(1);
		
}

int fib(int n){
	
	if(n <=1)
		return n;
	else
		return fib(n-1) + fib(n-2);
	
}
