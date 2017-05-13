#include <stdio.h>

void heap_adjust(int *p, int b, int e)
{
    int temp = p[b];  //keep the element which need to be adjusted
    int j;

    for(j = 2*b + 1; j <= e; j = 2*j + 1)
    {
        
        if(j < e && p[j] < p[j+1])
            j++;
        

        //printf("the fact j is %d.\n", j);

        if(temp >= p[j])
            break;

        p[b] = p[j];
        b = j;
    }


    p[b] = temp;
}


void show_arr(int *p, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d\t", p[i]);

    printf("\n");
}



void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heap_sort(int *p, int n)
{
    int i;
    for(i = n/2 - 1; i>= 0; i--)
    {
        heap_adjust(p, i, n-1);
        //show_arr(p, n);
    }


    printf("first big heap is ready.\n");
    for(i = n - 1; i > 0; i--)
    {
        //show_arr(p, n);
        swap(&p[0], &p[i]);
        
        show_arr(p, n);
        heap_adjust(p, 0, i-1);
        //maxheap_down(p, 0, i-1);
    }
}


int main()
{

    int arr_test[10] = {8,4,2,3,5,1,6,9,0,7};

    heap_sort(arr_test, 10);

    show_arr(arr_test, 10);
}
