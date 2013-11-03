/*
 * insertSORT.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * // from xunfei
 * 
 * 
 */


using namespace std;
#include <iostream>



void insertsort(int *a, int n)
{
    int i,j,temp;
    
    if(n==1) 
		return;
    
    for(i=1; i<n; i++)
    {
        temp=a[i];
        for(j=i-1; j>=0 && temp<a[j]; j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp; // insert it afterwards
    }
}


// the recursion implementation
void Rinsertsort(int *a, int n)
{
	if(n>1) // a condition
	{
		Rinsertsort(a,n-1);
    
		int j,temp=a[n-1];
		for(j=n-2; j>=0 && temp<a[j]; j--)
			a[j+1]=a[j];
		a[j+1]=temp;
		
	}

}




int main(void)
{
	int myints[] = {16,2,77,29};
	Rinsertsort(myints,4);
	
	for(int i=0;i< 4;i++)
		cout << myints[i] << endl;
	return 0;
}

