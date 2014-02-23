/*
 * qsort.c
 * 
 * ruijie testing
 */


#include <stdio.h>
int a[100] = { 1, 2, 8, 7, 9, 5, 6, 4, 3, 66, 77, 33, 22, 11 };

void prt(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a; 
    *a = *b; 
    *b = tmp;
}
 
void quick_sort(int a[], int left, int right)
{
    int i,last;
    if (left >= right) return;
    
    swap(&a[left],&a[(left+right)/2]); 
    last = left;
 
    for(i = left +1;i<= right ; i++)
    {
		if(a[i] < a[left])
			swap(&a[++last],&a[i]);
	}
	
	swap(&a[left],&a[last]); // set povit to the right position
    quick_sort(a, left, last-1);
    quick_sort(a, last+1, right);
}
 
int main(void) {
    quick_sort(a, 0, 13);
    prt(14);
    return 0;
}
