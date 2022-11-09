#include <stdio.h>
// worst case of it is when array is already sorted --->O{n^2}
//best case is O{nlog2^n}(log n of base 2)--> if array has pivot at center of array 
//average case time complexity is O{nlogn}.
// not a stable sa
//its recursive
//its an inplace alogorithm
int partion(int a[], int low, int high)//n-1 times parttition for n= length of array
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {

        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            // swap
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quick_sort(int *a[], int low, int high)
{
    int partionindex;

    if (low < high)
    {
        partionindex = partion(a, low, high);
        quick_sort(a, low, partionindex - 1);y
        quick_sort(a, partionindex + 1, high);
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void main()
{
    int array[1000];
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS YOU WANT TO ENTER:-\n");
    scanf("%d", &n);
    printf("ENTER YOUR ELEMENTS:-\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("THE ARRAY IS :-\n");
    print_array(array, n);
    quick_sort(&array, 0, n - 1);
    printf("\nARRAY AFTER SORTING IS:\n");
    print_array(array, n);
}