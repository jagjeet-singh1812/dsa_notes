#include<stdio.h>
#include<stdlib.h>
//Adt is abstact data type i.e custom data type which have certain properties or certain defined things of that data type and set of operation to be followed for it.
//Adt is abstract data types (set of values + set of operation)
//Adt implementation is as follow :
typedef struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
    //pointer data is stored in heap section while other data types defined are stored in stack section
}myarray;

void createArray(myarray *a,int tsize,int usize)
{
//(*a).total_size=tsize;
//(*a).used_size=usize;
//(*a).ptr = (int *)malloc(tsize*sizeof(int));
// Also can be written as :-

    a->total_size=tsize;
    a->used_size=usize;
    a->ptr = (int *)malloc(tsize*sizeof(int));
}
void setval(myarray *a)
{ int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the %d th element of that Array: ",i+1);
        scanf("%d", &n);
        (a->ptr)[i]=n;
    }
}

// Operation on array:-
// 1)traversal-->Every Element of the Array used capacity should be accessed once i.e while printing or taking input of array
// below can be an example of traversal of it 
void show(myarray *a)
{
    printf("The entered array is :\n");
    for (int i = 0; i <a->used_size; i++)
    {
        printf("%d\t", (a->ptr)[i]);
    }
    
}
// 2)insertion-->best case of insertion take (here o tand for big O i.e omega)O(1) time while worst case take O(n)
// 3)deletion-->best case of deletion take (here o tand for big O i.e omega)O(1) time while worst case take O(n)
// 4)searching-->linear search(traversal of whole array)+ binary search(if Sorted then a low(index:0) and high(index:last) is set then (low+high)/2 i.e mid index is found out traversed from low to mid  and following process is continued till we get the desired element i.e conversion of array.)

int main()
{
    myarray marks;
    int total_size_of_array,used_size_of_array;
    printf("Enter value of total size of array\n");
    scanf("%d",&total_size_of_array);

    printf("Enter value of used size of array\n");
    scanf("%d",&used_size_of_array);

createArray(&marks ,total_size_of_array ,used_size_of_array);
setval(&marks);
show(&marks);
    return 0;
}