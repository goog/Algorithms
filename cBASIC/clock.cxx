/*
 * clock.cxx
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


#include <iostream>

// 例如，在抽象的基础上，我们可以将时钟的数据和功能封装起来，构成一个时钟类。
class Clock
{
public : //共有成员，外部借口
void SetTime ( int NewH , int NewM , int NewS ) ;
void ShowTime () ;
private : //私有成员，外部无法访问
int Hour , Minute , Second ;
};


int main(int argc, char **argv)
{
	
	return 0;
}

