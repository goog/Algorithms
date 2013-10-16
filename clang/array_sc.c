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
int main() 
{
    int a=3, b = 5;
    
    printf(&a["Ya!Hello! how is this?\n"]);
    printf("%c   %c\n","hello"[2],2["hello"]);
 
    printf(&a["Ya!Hello! how is this? %s\n"], &b["junk/super"]);
     
    printf(&a["WHAT%c%c%c  %c%c  %c !\n"], 1["this"],
        2["beauty"],0["tool"],0["is"],3["sensitive"],4["CCCCCC"]);
         
    return 0; 
}
