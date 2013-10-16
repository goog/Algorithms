/*
 * byte1.c
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
#include <stdlib.h>
 
#define SIZEOF(arr) (sizeof(arr)/sizeof(arr[0]))
#define PrintInt(expr) printf("%s:%d\n",#expr,(expr))
 
int main()
{
    /* The powers of 10 */
    int pot[] = {
                    0001,
                    0010,
                    0100,
                    1000
                };
 
    int i;
    for(i=0;i<SIZEOF(pot);i++)
        PrintInt(pot[i]);
         
    return 0;
}

