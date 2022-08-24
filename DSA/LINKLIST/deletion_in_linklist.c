#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// there are 4 types of deletion
// a) deletion at beginning-->its time complexity is O(1)i.e constant
// b) deletion in between-->its time complexity is O(n)
// c) deletion at end-->its time complexity is O(n)
// d) deletion after node-->its time complexity is O(1)i.e constant

void linklist_traversal(node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("Data part of %d node is %d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    }
}


node *deletion_at_beginning(node *head)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


node *deletion_at_index(node *head, int index)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    node *q = (node *)malloc(sizeof(node));
    q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}


node *deletion_at_end(node *head)
{
    node *p = (node *)malloc(sizeof(node));
    node *q = (node *)malloc(sizeof(node));
    p = head;
    q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}


node *deletion_at_node(node *head, int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *q = (node *)malloc(sizeof(node));
    ptr = head;
    q=head->next;
    while (q->data!=value&& q->next!=NULL)
    {
        ptr = ptr->next;
        q=q->next;
    }
    if(q->data==value)
    {
        ptr->next=q->next;
        free(q);
    return head;
    }

    else
    {
        // printf("data-part not found\n");
        return head;
    }
    
}


void main()
{
    int option, index;
    node *head;
    node *second;
    node *third;
    node *fourth;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));

    // linking first node to second
    head->data = 12;
    head->next = second;

    // linking second node to third
    second->data = 13;
    second->next = third;

    // linking third node to fourth
    third->data = 14;
    third->next = fourth;

    // linking fourth node to NULL i.e terminating the list
    fourth->data = 15;
    fourth->next = NULL;
    printf("The present linklist is:\n");
    linklist_traversal(head);

    printf("Enter 1 deletion at start/beginning of an linklist:\n");
    printf("Enter 2 deletion at any index of an linklist:\n");
    printf("Enter 3 deletion at end of an linklist:\n");
    printf("Enter 4 deletion at given data part of node of an linklist:\n");
    printf("Enter the option you want to select:\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
    {
        head = deletion_at_beginning(head);
        linklist_traversal(head);
        break;
    }
    case 2:
    {
        // note this cant be used for index : 0 so use only case 1 for it
        printf("Enter the index you want to delete the element :  \n");
        // note here index starts from 1 i.e after head as head is zero index i.e it cant be used to delete at zero index for it use case 1
        scanf("%d", &index);
        head = deletion_at_index(head, index);
        linklist_traversal(head);
        break;
    }
    case 3:
    {
        head = deletion_at_end(head);
        linklist_traversal(head);
        break;
    }
    case 4:
    {  int value;
        // node *p = (node *)malloc(sizeof(node));
        // p = scnaf("%s",node);
        printf("Enter the data of node you want to delete:");
        scanf("%d",&value);
        //if here data part is not present in linklist then this function simply return the original linklist without any changes.(modification can be made according to the question asked )
        head = deletion_at_node(head,value);
        linklist_traversal(head);
        break;
    }

    default:
    {
        printf("wrong option selection\n");
    }
    break;
    }
}