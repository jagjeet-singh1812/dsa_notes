#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}node;

// there are 4 types of insertion
// a) insertion at beginning-->its time complexity is O(1)i.e constant
// b) insertion in between-->its time complexity is O(n)
// c) insertion at end-->its time complexity is O(n)
// d) insertion after node-->its time complexity is O(1)i.e constant

void linklist_traversal(node *ptr)
{ int i=1;
    while(ptr!=NULL)
    {
        printf("Data part of %d node is %d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
}

node * insert_at_first(node *head,int insert_element)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->next=head;
    ptr->data=insert_element;
    return ptr;
}


void main()
{
int insert_element;
 node *head;
  node *second;
  node *third;
  node *fourth;

  head=(node *)malloc(sizeof(node));
  second=(node *)malloc(sizeof(node));
  third=(node *)malloc(sizeof(node));
  fourth=(node *)malloc(sizeof(node));

//linking first node to second
head->data=12;
head->next=second;

//linking second node to third
second->data=13;
second->next=third;

//linking third node to fourth 
third->data=14;
third->next=fourth;

//linking fourth node to NULL i.e terminating the list
third->data=15;
third->next=NULL;

linklist_traversal(head);
printf("enter the data of the element you want to insert at first:\n");
scanf("%d",&insert_element);
head=insert_at_first(head,insert_element);
linklist_traversal(head);

free(head);
free(second);
free(third);
}