/*
 * priority.c
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
 * alibaba interview
 * 
 * 
 */
#include<stdio.h>

 void heapAD(int *a, int m, int n)
 {
	 int rc = a[m];
	 int j;
	 for(j=2*m+1;j<n;j=2*j+1)
	 {
		 if(j+1 < n && a[j] < a[j+1] ) j++;
		 if(a[j] <= rc)      break;
		 a[m] = a[j];  // cpoy it to parent node
		 m = j;
	 }
	 a[m] = rc;
 }
 
 
void heapSORT(int *a,int n)
{	int i,temp;

	for(i=n/2 - 1;i>=0;i--)
		heapAD(a,i,n);
	
	for(i=n-1;i>0;i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapAD(a,0,i);}
	
	// print the sorted result
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
}

void main(void)
{
	int a[10] = {8,4,2,3,5,1,6,9,0,7}; //{23,15,34,12,11};
	heapSORT(a,10);
}
