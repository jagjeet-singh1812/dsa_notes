// balance paranthesis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int size;
    int top;
    char *arr;
} stack;

int is_empty(stack *ptr) // time complexity is O(1)
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

int is_full(stack *ptr) // time complexity is O(1)
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

char pop(stack *s)
{
    if (is_empty(s))
    {
        return -1;
    }
    else
    {
        char VALUE = s->arr[s->top];
        s->top--;
        return VALUE;
    }
}

void push(stack *ptr, char value) // time complexity is O(1)
{
    if (is_full(ptr))
    {
        printf("Stack overflow!!! %s can be added to the stack\n", value); // is full top=s.size
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        // printf("THE %c has been added to stack\n", value);
    }
}

int paranthesismatcher(char *exp, int length)
{
    stack *sp = malloc(sizeof(stack));
    sp->size = length;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            if (is_empty(sp))
                return 0;
            pop(sp);
        }
        i++;
    }

    if (is_empty(sp))
    {
        return 1;
    }

    else return 0;
}

void main()
{
    char *expression;
    printf("ENTER YOUR EXPRESSION:-\n");
    scanf("%s", expression);
    if (paranthesismatcher(&expression, strlen(expression)))
    {
        printf("ITS AN VALID EXPRESSION\n");
    }
    else
    {
        printf("ITS NOT AN VALID EXPRESSION\n");
    }
}