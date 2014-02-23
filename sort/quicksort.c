#include <stdio.h>

int quicksub(int *a,int b,int e)  // b begin e:end
{
	int pivot = a[b];
	int i = b,j = e;
	while(i < j)
	{
		while(a[j] >= pivot && i < j)
			j--;
		a[i] = a[j];
		while(a[i] <= pivot && i < j)
			i++;
	}
	a[i] = pivot;  // move pivot to proper position
	return i;

}

void quicksort(int *a, int low, int high)
{
	int m;
	if(low < high)
	{
		m= quicksub(a,low,high);
		quicksort(a,low,m-1);
		quicksort(a,m+1,high);
	}

}

int main()
{
	int a[5] = {1,23,2,56,34};
	quicksort(a,0,4);
	int i;
	for(i=0; i < sizeof a / sizeof(int) ; i++)
		printf("%d ", a[i]);
	return 0;
}

