#include <stdio.h>
// insertion operation in arrray:- time complexity of O(n)
void insertion(int *arr[1000], int n, int size, int index, int element)
{
    if (size <= n)
    {
        printf("insertion can't take place. try again by increasing the size of the array\n");
    }
    else
    {

        for (int i = n - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index] = element;
    }
}


void deletion(int *arr[1000],int deletion_element_index,int n,int size)
{
    if(n>size)
    {
        printf("THE DELETION CAN OCCUR PLS CHECK ARRAY MAX SIZE");
    }
    else{
    for (int i = deletion_element_index; i<n; i++)
    {
        arr[i]=arr[i+1];
    }
    }
    
}

void input(int *arr[1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element of array:-\n", i + 1);
        scanf("%d", &(arr[i]));
    }
}

void show(int *arr[1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void main()
{
    int array[1000], n;
    int max_size = 1000, insertion_element, index, option,deletion_element;
    printf("Enter the number of elements you want:- \n");
    scanf("%d", &n);
    input(&(array), n);
    show(&(array), n);
    printf("SELECTION 1 FOR INSERTION\n");
    printf("SELECTION 2 FOR DELETION\n");
    printf("SELECT YOUR DESIRED OPTION:- \n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
    {
        printf("Enter the element you want to insert :- \n");
        scanf("%d", &insertion_element);
        printf("Enter the index of element you want to insert in :- \n");
        scanf("%d", &index);
        insertion(&(array), n, max_size, index, insertion_element);
        n += 1;
        printf("Array after insertion is:-\n");
        show(&(array), n);
    }
    case 2:
    {
          printf("enter the index of the deletion element:-");
          scanf("%d",&deletion_element);
          deletion(&(array),deletion_element,n,max_size);
          printf("Array after deleion is :-");
          n-=1;
        show(&(array), n);
    }
    }
}