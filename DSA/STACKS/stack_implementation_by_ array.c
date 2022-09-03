#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int is_empty(stack *ptr)// time complexity is O(1)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0; // no need of else case was there its only for understanding purpose
    }
}

int is_full(stack *ptr)// time complexity is O(1)
{
    
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0; // no need of else case was there its only for understanding purpose
    }
}

int stacktop(stack *s)
{
    return s->arr[s->top];
}

int stackbottom(stack *s)
{
    return s->arr[0];
}
//array index= top-i+1;
//note here position starts from 1 from the top
int peak(stack *ptr, int position)// time complexity is O(1)
{
int array_index=ptr->top  - position+ 1;
if(array_index<0)
{
    return -1;
}
else
{
    return ptr->arr[array_index];
}
}

// you can only pop at top=>0 and pop cant at top=-1
// int pop(stack *ptr)// time complexity is O(1)
// {
//     if (is_empty(ptr))
//     {
//         // printf("Stack underflow\n");
//          // is empty top=-1
//         return -1;
//     }
//     else
//     {
//         int val=ptr->arr[ptr->top];
//         // ptr->top = ptr->top-1; 
//         //  also can do
//         ptr->top--;
//         return val;
//     }
// }

int pop(stack *s)
{
    if(is_empty(s))
    {
        return -1;
    }
    else
    {
        int value=s->arr[s->top];
        s->top--;
        return value;
    }
}
void push(stack *ptr, int value)// time complexity is O(1)
{
    if (is_full(ptr))
    {
        printf("Stack overflow!!! %d can be added to the stack\n", value); // is full top=s.size
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("THE %d has been added to stack\n", value);
    }
}



void main()
{
    //  stack s;
    //  printf("Enter the size of stack i.e array:-\n");
    //  scanf("%d",&s.size);
    //  s.top=-1;
    //  s.arr=(int *)malloc(s.size*sizeof(int));
    // and (*s).size can be also written as s-> size by using arrow operation
    // as easily call by refrence can be used and any array can be edited so above method is not used...
    int option,rep;
    stack *s = (stack *)malloc(sizeof(stack));
    printf("Enter the size of stack i.e array:-\n");
    scanf("%d", &(s->size));
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");


do{
    printf("Enter 1 for pushing in stack\n");
    printf("Enter 2 for poping in stack\n");
    printf("Enter 3 for displaying the stack\n");
    printf("Enter 4 for peaking the stack\n");
    printf("Enter 5 for stack at top\n");
    printf("Enter 6 for stack at bottom\n");
    printf("Enter your desired option:-\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
    {
        int number;
        printf("How many number you want to push in stack:\n");
        scanf("%d", &number);
        while (number-- > 0)
        {
            int value;
            printf("Enter your value to be entered:-\n");
            scanf("%d", &value);
            push(s, value);
        }
        break;
    }
    case 2:
    {
    if(pop(s)==-1)
    {
     printf("Stack underflow\n");
    }
    else
    {
        s->top+=1;
        printf("The %d has been removed from the stack\n",pop(s));
    }
        break;
    }
    case 3:
    {
       for(int i=1;i<=s->top+1;i++)
       {
        printf("The value at position %d is %d\n",i,peak(s,i));
       }
        break;
    }
    case 4:
    { int position;
        printf("Enter your position from top:");
        scanf("%d",&position);
        printf("The value at position %d is %d\n",position,peak(s,position));
        break;
    }
    case 5:
    { 
        printf("The stack at the top is %d\n",stacktop(s));
        break;
    }
    case 6:
    { 
        printf("The stack at the bottom is %d\n",stackbottom(s));
        break;
    }
    default:
    {
        printf("wrong option selected...pls enter a valid choice");
    }
    }
    printf("Do you want to continue:(enter 1 for yes and 0 for no)\n");
    scanf("%d",&rep);
    printf("\n");
    }while(rep!=0);
}