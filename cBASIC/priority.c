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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
/*下面的程序试图使用“位操作”来完成“乘5”的操作，不过这个程序中有个BUG，你知道是什么吗？ */

#include <stdio.h>
#define PrintInt(expr) printf("%s : %d\n",#expr,(expr))
int FiveTimes(int a) 
{
    int t;
    //t = a<<2 + a;
    t = (a<<2) + a;
    return t;
}
 
int main() 
{
    int a = 1, b = 2,c = 3;
    PrintInt(FiveTimes(a));
    PrintInt(FiveTimes(b));
    PrintInt(FiveTimes(c));
    return 0;
}
