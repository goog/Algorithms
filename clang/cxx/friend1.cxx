/*
 * friend1.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * this is an error case.
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <string.h>


class Internet   
{   
public:   
    Internet(char *name,char *address)   
    {   
        strcpy(Internet::name,name);   
        strcpy(Internet::address,address);    
    } 

friend void ShowN(Internet &obj);//友元函数的声明
private:   
    char name[20]; 
    char address[20]; 
}; 
 
 
void ShowN(Internet &obj) //友元函数的定义,不能写成,void Internet::ShowN(Internet &obj) 
{ 
    cout<<obj.name<<endl; 
} 

int main()   
{ 	
	char name[] = "中国软件开发实验室";
	char add[]  = "www.cndev-lab.com";
    
    Internet a(name,add);
    ShowN(a); 
    //cin.get();
    return 0;
} 

