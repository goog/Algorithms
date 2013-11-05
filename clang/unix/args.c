/*
 * read.c
 * 
 * (*args )
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print(char *fmt, ...)
{
	va_list ap;
	char *p,*sval;
	int ival;
	double dval;
	
	va_start(ap,fmt);
	
	for(p = fmt;*p;p++)
	{
		if(*p != '%')
			{
				putchar(*p);
				continue;
			}
		//%d 
		p++;
		switch(*p)
		{
			case 'd':
				ival = va_arg(ap,int);
				printf("%d",ival);
				break;
				
			case 'f':
				dval = va_arg(ap,double);
				printf("%f",dval);
				break;
			
			case 's':  // 
				for(sval = va_arg(ap,char *);*sval;sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
			
		}
	}
	
	va_end(ap);
	
	
	
}

void error(char *fmt, ...)
{
	va_list args;
	va_start(args,fmt);
	fprintf(stderr,"error: ");
	vfprintf(stderr,fmt,args);
	fprintf(stderr,"\n");
	va_end(args);
	exit(1);
	
}
/*
 * stdout和stderr是不是同设备描述符。stdout是块设备，stderr则不是。
 * 对于块设备，只有当下面几种情况下才会被输入，
 * 1）遇到回车，2）缓冲区满，3）flush被调用。而stderr则不会。
 * 
 * 
 */

int main(void)
{
	print("This is my print function %d %f , %s",12,12.34,"what ");  // stream device 
	error("cp, %s","issue is here.");
	return 0;
}

