#include <stdio.h>
#include<stdlib.h>

void print_array(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    // int n= sizeof(a)/sizeof(a[0]);
    // int* B= (int *)malloc(n*sizeof(int));
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void merge_sort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        merge_sort(A, low, mid);
        merge_sort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
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
    merge_sort(array, 0, n - 1);
    printf("\nARRAY AFTER SORTING IS:\n");
    print_array(array, n);
}