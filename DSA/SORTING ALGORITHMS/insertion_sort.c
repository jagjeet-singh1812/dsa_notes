#include<stdio.h>
#include<stdlib.h>
//divide and conquer rule is used 
void merge(int a[], int low,int mid,int high) // sorts in ascendind order
{
    //int n= sizeof(a)/sizeof(a[0]);
    int i,j,k,b[100],
    //int* b=(int *)malloc(n*sizeof(int));
   i=low;
   j= mid+1;
k=low;

while(i<=mid && j<=high){
if(a[i]<a[j]){
    b[k]=a[i];
    i++;
    k++;
}
if(a[i]>a[j]){
    b[k]=a[j];
    j++;
    k++;
}

while (i<=mid)// for copying remaining element in the array
{
    b[k]=a[i];
    i++;
    k++;
}

while(j<=high)// for copying remaining element in the array
{
    b[k]=a[j];
    j++;
    k++;
}

for(int i=low;i<=high;i++)// for copying the elements of array b in a 
{
a[i]=b[i];
}
}
}
void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void merge_sort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid= (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
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
    merge_sort(array, 0,n-1);
    printf("\nARRAY AFTER SORTING IS:\n");
    print_array(array, n);
}