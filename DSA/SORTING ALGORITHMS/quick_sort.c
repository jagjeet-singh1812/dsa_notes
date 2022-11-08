 #include <stdio.h>
//  its worst case time complexity is O{n^2} and O{n}in best case senario
// its not stable sa(sorting algorithm).
//  its not an adaptive algorithm.
// its just swap in minimum number of swaps --->advantage
void quick_sort(int *a[], int n)
{    
                
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
    quick_sort(array, n);
    printf("\nARRAY AFTER SORTING IS:\n");
    print_array(array, n);
}