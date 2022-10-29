#include <stdio.h>
#include <stdlib.h>
#define max 10

int hashing(int k)
{
    return (k % max); // m is the size and k is value or key
}

void printing(int a[])
{
    printf("THE HASHING TABLE IS:-\n");
    for (int i = 0; i < max; i++)
    {
        printf("%d\t",a[i]);
    }
}

void set(int a[])
{
    for (int i = 0; i < max; i++)
    {
        a[i] = -1;
    }
}
void linearprobing(int a[], int val)
{
    for (int i = 0; i < max; i++)
    {
        int code = hashing(hashing(val) + i);
        if (a[code] == -1)
        {
            a[code] = val;
            break;
        }
    }
}
void  quadraticprobing(int a[],int val){
for(int i=0;i<max ;i++){
    int code= hashing(hashing(val)+i*i);
    if(a[code]== -1){
        a[code]= val;
        break;
    }
}
}
void main()
{
    int choice, option, n, val;
    int a[max], b[max];
    printf("HOW MANY NUMBER YOU WANT IN ARRAY:-\n");
    scanf("%d", &n);
    set(a);
    do
    {
        printf("ENTER 1 FOR LINEAR PROBING:-\n");
        printf("ENTER 2 FOR QUADRARTIC PROBING:-\n");
        printf("ENTER 3 FOR EXIT:-\n");
        scanf("%d", &choice);
        for (int i = 0; i < n; i++)
        {
            switch (choice)
            {
            case 1:

                printf("\n insert the value to be entered:-\n");
                scanf("%d", &b[i]);

                linearprobing(a, b[i]);

                printing(a);
                break;
            case 2:

             printf("\n insert the value to be entered:-\n");
                scanf("%d", &b[i]);

                quadraticprobing(a, b[i]);

                printing(a);
                break;
            
            case 3: exit(0);


            default:
                printf("WRONG OPTION SELECTION");
                break;
            }
        }
        printf("DO YOU WANT TO CONTINUE:-(if no press 0 else Anything");
        scanf("%d", &option);
    } while (option != 0);
}