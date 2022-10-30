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
        return 0;// no need of else was there
}

int isfull(node *top)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)//note malloc only return null when memory allocation cannot be done..
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
        printf("The element at %d node is %d\n", i, top->data);
        top = top->next;
        i++;
    }
}


node* push(node *top, int value)
{

    if (isfull(top))
    {
        printf("Stack Overflow");
        
    }
    else
    {
        node *s = (node *)malloc(sizeof(node));
        s->data = value;
        s->next = top;
        top = s;
        return top;
    }
}

int peak(node* top,int position)
{
    node*p=(node *)malloc(sizeof(node));
    p->next=top;
    int i=1;
while(i!=position-1)
{
    p=p->next;
    i++;
}
return p->data;
}

int nodetop(node*top)
{
    node *p;
    p=top->next;
    return p->data;
}


int nodebottom(node* ptr)
{
node*p;
  p=ptr;
while(p->next!=NULL)
{
    p=p->next;
}
return p->data;
}

int pop(node **top)//or just declare top globally and then change local variables name 
{
    if (isempty(top))
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
    int option, rep;
    node *top = NULL;

    printf("stack has been created successfully with\n");

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
             top=push(top, value);
             printf("%d is Entered to the stack\n");
            }
            break;
        }
        case 2:
        {
            if (pop(&top)==-1)
            {
                printf("stack underflow\n");
            }
            else
            {
                printf("The %d has been removed from the node\n", pop(&top));
            break;
        }

        case 3:
        {
            linklist_traversal(top);
            break;
        }
        case 4:
        { int position;
            printf("Enter your position from top:");
            scanf("%d",&position);
         
            printf("The value at position %d is %d\n",position,peak(top,position));
            break;
        }
        case 5:
        {
            printf("The node at the top is %d\n",nodetop(top));
            break;
        }
        case 6:
        {
            printf("The node at the bottom is %d\n",nodebottom(top));
            break;
        }
        default:
        {
            printf("wrong option selected...pls enter a valid choice");
        }
        }
    }
        printf("Do you want to continue:(enter 1 for yes and 0 for no)\n");
        scanf("%d", &rep);
        printf("\n");
    } while (rep != 0);
    }