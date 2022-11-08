#include<stdio.h>
// its worst case time complexity is O{n^2} and O{n}in best case senario
//  its stable sa
//  its adaptive
// intermediate result is not useful at all they are just random number of element sorted
void insertion_sort(int *a[], int n) // sorts in ascendind order
{
    int key, j;
    for (int i = 1; i <= n - 1; i++) // loop for passes 
    //total possible swap/passes is n(n-1)/2 and total passes are (n-1) ,here n= no.of array elements
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key)// for ascending order or for descending order a[j]<key
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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
    insertion_sort(array, n);
    printf("\nARRAY AFTER SORTING IS:\n");
    print_array(array, n);
}