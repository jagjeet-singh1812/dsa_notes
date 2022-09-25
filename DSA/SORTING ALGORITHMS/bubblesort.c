//criteria for sorting algorithms are 1)time complexity and 2)space complexity
// inplace sorting algorithm is constant space is required doesnt depend upon size of structure 
//3)stability of structure
//ex- 1 5 4(a) 4(b)    sorted- 5 4(a) 4(b) 1 so its stable, 5 4(b) 4(a) 1  its not stable
//4a)internal SA-all data is loaded in to memory
//4b)internal SA-all data is not loaded in to memory
// 5)adaptive--already sorted takes less time than usaual SA(sorting algorithm)
// 6)its recursive or not


#include<stdio.h>
// bubble sort time complexity is O(n^2)
// total no.of comparison is n(n-1)/2
// no of passes is n-1(n is size of structure)
// its stabilzed SA 
// not a recursive
// not adaptive but can be made adaptive
void bubble_sort(int *a[],int n)
{ int temp;
int is_sorted=0;
  for(int i=0;i<n;i++){// for number of passes
  is_sorted=1;
//   printf("\nWORKING ON PASS NO. %d\n",i+1);
  for(int j=0;j<n-1-i;j++){// for comparison
     if(a[j+1]<a[j]) // for ascending order
     {
      temp=a[j];   
      a[j]=a[j+1];
      a[j+1]=temp;
// also can swap by this way
    //   a[j]=a[j] + a[j+1];
    //   a[j+1]=a[j]-a[j+1];
    //   a[j]=a[j]-a[j+1];
     }
  }
     if(is_sorted) return;
  }
}
void print_array(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

void main()
{
 int array[1000];
 int n;
 printf("ENTER THE NUMBER OF ELEMENTS YOU WANT TO ENTER:-\n");
 scanf("%d",&n);
 printf("ENTER YOUR ELEMENTS:-\n");
 for(int i=0;i<n;i++) scanf("%d",&array[i]);
 printf("THE ARRAY IS :-\n");
 print_array(array,n);
 bubble_sort(array,n);
 printf("\nARRAY AFTER SORTING IS:\n");
 print_array(array,n);

}