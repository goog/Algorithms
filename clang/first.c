#include"stdio.h"

void main(){
	// 声明一个int指针
int *ptr;
// // 声明一个int值
int val = 1;
// // 为指针分配一个int值的引用
ptr = &val;
// // 对指针进行取值，打印存储在指针地址中的内容
int deref = *ptr;
printf("%d\n", deref);
printf("%s\n", "new testing:");
int *dev_c;
dev_c = &val;
printf("%p\n",dev_c);  // val address
printf("%p\n",&dev_c); // get the address of dev_c
printf("%p\n",(void **)&dev_c);
printf("%p\n",(void *) dev_c);

}
