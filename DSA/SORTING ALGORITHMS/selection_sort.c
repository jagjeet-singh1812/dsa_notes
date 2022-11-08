#include <stdio.h>
// just find min element of array and keep it arranging for ascending order
//  its worst case time complexity is O{n^2} and O{n}in best case senario
// its not stable sa(sorting algorithm).
//  its not an adaptive algorithm.
// its just swap in minimum number of swaps --->advantage
void selection_sort(int *a[], int n)
{    int temp;
    for (int i = 0; i < n; i++)// for ascending order 
    {  int indexofmin=i;
        for (int j = i + 1; j < n; j++) // no of passes and maximum no of swaps is n-1 for n= length of the array
        // total possible comparision are n(n-1)/2
        {
            if(a[j]<a[indexofmin]){
                indexofmin=j;// storing least value of array index 
            }
        }
        // for swaping 
                temp= a[i];
                a[i]=a[indexofmin];
                a[indexofmin]=temp;
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
    selection_sort(array, n);
    printf("\nARRAY AFTER SORTING IS:\n");
    print_array(array, n);
}