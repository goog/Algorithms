/*
 * pt1.c
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
    int num[] = {50, 25, 75, 100};
    int *pt;

    pt = num + 1;   //故意将第2个元素地址赋给指针变量

    //显示指针变量所指的地址以及指针的值
    printf("pt  =%p, *pt    =%d\n\n", pt,   *pt);

    //当指针变量减1或加1时，所指的地址并不减1或加1，而是加减4，因为int是4个字节
    printf("pt-1=%p, *(pt-1)=%d\n", pt-1, *(pt-1));
    printf("pt  =%p, *pt    =%d\n", pt,   *pt);
    printf("pt+1=%p, *(pt+1)=%d\n", pt+1, *(pt+1));

    //显示pt当作数组用时的值。(注意：[-1]仍然是正确的)
    printf("\npt[0]=%d, pt[-1]=%d\n", pt[0], pt[-1]);

    return 0;
}

