#include <stdio.h>

void heapjust(int *a, int m, int n) // adjust a[m] element
{
	int j,rc;
	rc = a[m];
	for(j=2*m+1;j <=n;j*=2)
	{
		if(j < n && a[j] < a[j+1])  // j < n then j+1 is ok
			j++;
		if(a[j] <= rc)   // a[j] don't need move
			break;
		a[m] = a[j];
		m = j; // m saves the exchanged point, an empty position
	}
	a[m] = rc;
	
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heapsort(int *a, int n)
{
	int i;
	for(i=n/2;i>=0; i--)
		heapjust(a,i,n-1);
	
	for(i=0; i <n-1;i++)
	{
		swap(&a[0],&a[n-1-i]);
		heapjust(a,0,n-2-i);
	}
}


int main()
{
	int a[5] = {1,23,2,56,34};
	heapsort(a,5);
	int i;
	for(i=0; i < sizeof a / sizeof(int) ; i++)
		printf("%d ", a[i]);
	return 0;
}
