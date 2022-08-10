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

void deletion(int *arr[1000], int deletion_element_index, int n, int size)
{
    if (n > size)
    {
        printf("THE DELETION CAN OCCUR PLS CHECK ARRAY MAX SIZE");
    }
    else
    {
        for (int i = deletion_element_index; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
}

int linearsearch(int arr[1000], int n, int search_element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search_element)
        {
            return i;
        }
    }

    return -1;
}
// This is bubble sort
void sort(int *arr[1000],int n)
{ int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int binarysearch(int arr[1000],int n,int search_element)
{
    int mid,high,low;
    low=0;
    high= n-1;
    while(low<=high)
    {
    mid=high+low/2;
        if(arr[mid]==search_element)
        {
            return mid;
        }

        if(arr[mid]<search_element)
        {
            low=mid+1;
        }
    
        /* A comment. */
        // it can also be done like this
        // if(arr[mid]>search_element)
        // {
        //     high=mid-1;
        // }
        // else
        // {
        // low=mid+1;
        // }
        else
        {
            high=mid-1;
        }
    }
    return -1;

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
    int max_size = 1000, insertion_element, index, option, deletion_element;
    printf("Enter the number of elements you want:- \n");
    scanf("%d", &n);
    // n can be founf out by n= sizeof(arr)/sizeof(int) for an given array
    input(&(array), n);
    show(&(array), n);
    printf("SELECTION 1 FOR INSERTION\n");
    printf("SELECTION 2 FOR DELETION\n");
    printf("SELECTION 3 FOR SEARCHING\n");
    //time complexity of liner is O(n) and for binary is O(log n)
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
        break;
    }
    case 2:
    {
        printf("enter the index of the deletion element:-");
        scanf("%d", &deletion_element);
        deletion(&(array), deletion_element, n, max_size);
        printf("Array after deleion is :-");
        n -= 1;
        show(&(array), n);
        break;
    }
    case 3:
    {
        int option1;
        printf("select 1 for linear search\n");
        printf("select 2 for binary search\n");
        // binary search time complexity is big O of log n(O(log n))
        printf("select your choice :-\n");
        scanf("%d", &option1);
        switch (option1)
        {
            int search_element, req_index;
        case 1:
        {
            printf("Enter the element you want to search");
            scanf("%d", &search_element);
            req_index = linearsearch(&(array), n, search_element);
            if ((req_index) != -1)
            {
                printf("The Element %d was found at %d index of array\n", search_element, req_index);
            }
            else
            {
                printf("The Element %d is not found in array \n", search_element);
            }
            break;
        }
        case 2:
        {
            printf("first we need to sort\n");
           sort(&(array),n);
           printf("So array after sorting is:\n");
           show(&(array),n);
           printf("so now array is sorted \n");
            printf("Enter the element you want to search:");
            scanf("%d", &search_element);
            req_index=binarysearch(array,n,search_element);
            if ((req_index) != -1)
            {
                printf("The Element %d was found at %d index of array\n", search_element, req_index);
            }
            else
            {
                printf("The Element %d is not found in array \n", search_element);
            }
            break;
        }
        }
    }
    }
}