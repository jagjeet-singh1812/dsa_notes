#include <stdio.h>
#include <stdlib.h>
// here you can always set custom size here
// here head is turned into top

typedef struct node
{
    int data;
    struct node *next;
} node;
  


int isempty(node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isfull()
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        return 1; // means dynamically memory cant be allocated only if all heap memory is exhausted so p==null
    }
    else
    {
        return 0;
    }
}
void linklist_traversal(node *top)
{
    int i = 1;
    while (top != NULL)
    {
        printf("The element at %d node is %d", i, top->data);
        top = top->next;
        i++;
    }
}
void push(node *top, int value)
{

    if (isfull() == 1)
    {
        printf("Stack Overflow");
           // if(s==NULL){
    //     printf("Stack Overflow");
    }
    else
    {
        node *s = (node *)malloc(sizeof(node));
        s->data = value;
        s->next = top;
        top = s;
    }
}

int pop(node **top)
{
    if (isempty(*top))
    {
        // printf("Stack underflow\n");
        return -1;
    }
    else
    {
        node *ptr = *top;
        *top = (*top)->next;
        int data_removed = ptr->data;
        free(ptr);
        return data_removed;
    }
}

void main()
{
    int option, rep, n;
    node *top = NULL;
                        
    printf("Enter the max size you want into heap/ custom size :-\n");
    scanf("%d", &(n));

    printf("node has been created successfully\n");

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
            printf("How many number you want to push in node:\n");
            scanf("%d", &number);
            for (int i = 0; i < number; i++)
            {
                int value;
                printf("Enter your value to be entered:-\n");
                scanf("%d", &value);
                push(top, value);
            }
            break;
        }
        case 2:
        {
            if (pop(top) == -1)
            {
                printf("stack underflow\n");
            }
            else
            {
                printf("The %d has been removed from the node\n", pop(&top));
            }
            break;
        }

        case 3:
        {
            linklist_traversal(top);
            break;
        }
        // case 4:
        // { int position;
        //     printf("Enter your position from top:");
        //     scanf("%d",&position);
        //     printf("The value at position %d is %d\n",position,peak(s,position));
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