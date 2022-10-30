#include<stdio.h>
#include<stdlib.h>
#define n 5
int arr[10];
 int top=-1;

// typedef struct node{

// int top;
// int *arr;
// int size;

// }node;

int push(int val){
// if(top=-1){
//     printf("STACK IS was EMPTY");
// }
 if (top == n-1)
{
    printf("STACKOVERFLOW\n");
    return 0;
}
else
{
    arr[top]=val;
    top++;
    return 1;
}
}


void main(){
  int option,choice,rep;
    printf("stack has been created successfully with array\n");

    do
    {
        printf("Enter 1 for pushing in node\n");
        printf("Enter 2 for poping in node\n");
        printf("Enter 3 for displaying the node\n");
        printf("Enter 4 for peaking the node\n");
        printf("Enter 5 for node at top\n");
        printf("Enter 6 for node at bottom\n");
        printf("Enter your desired option:-\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            int number;
            printf("How many number you want to push in node:()\n");
            scanf("%d", &number);
            for (int i = 0; i < number; i++)
            {
                int value;
                printf("Enter your value to be entered:-\n");
                scanf("%d", &value);
             number=push(value);
             if(number==1){
             printf("%d is Entered to the stack\n",value);
             }
             else{
             printf("%d is cannot be Entered to the stack\n",value);
             }
            }
            break;
        }
        // case 2:
        // {
        //     if (pop(&top)==-1)
        //     {
        //         printf("stack underflow\n");
        //     }
        //     else
        //     {
        //         printf("The %d has been removed from the node\n", pop(&top));
        //     break;
        // }

        // case 3:
        // {
        //     linklist_traversal(top);
        //     break;
        // }
        // case 4:
        // { int position;
        //     printf("Enter your position from top:");
        //     scanf("%d",&position);
         
        //     printf("The value at position %d is %d\n",position,peak(top,position));
        //     break;
        // }
        // case 5:
        // {
        //     printf("The node at the top is %d\n",nodetop(top));
        //     break;
        // }
        // case 6:
        // {
        //     printf("The node at the bottom is %d\n",nodebottom(top));
        //     break;
        // }
        default:
        {
            printf("wrong option selected...pls enter a valid choice");
        }
        }
    
        printf("Do you want to continue:(enter 1 for yes and 0 for no)\n");
        scanf("%d", &rep);
        printf("\n");
    } while (rep != 0);
    }
