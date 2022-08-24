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
    return ptr;       //this return new head 
}





node * insert_at_end(node *head,int insert_element)
{
    node* ptr= (node *)malloc(sizeof(node));
    ptr->data= insert_element;
    node *p= head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

node * insert_at_given_node(node * head,int insert_element ,node* previousnode)
{

    node* ptr= (node *)malloc(sizeof(node));
    ptr->data= insert_element;

    ptr->next=previousnode->next;
    previousnode->next=ptr;

    return head;
}

node * insert_at_index(node *head,int insert_element,int index)
{
node* ptr= (node *)malloc(sizeof(node));
node *p = head;
int i=0;
while(i!=index-1)
{
    p=p->next;
    i++;
}
ptr->data=insert_element;
ptr->next=p->next;
p->next=ptr;
return head;
}


void main()
{
int insert_element,option,index;
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
fourth->data=15;
fourth->next=NULL;

printf("The present linklist is:\n");
linklist_traversal(head);

printf("Enter 1 for insertion at start/beginning of an linklist:\n");
printf("Enter 2 for insertion at any index of an linklist:\n");
printf("Enter 3 for insertion at end of an linklist:\n");
printf("Enter 4 for insertion at given node of an linklist:\n");
printf("Enter the option you want to select:\n");
scanf("%d",&option);
switch (option)
{

case 1:
{
printf("enter the data of the element you want to insert at first:\n");
scanf("%d",&insert_element);
head=insert_at_first(head,insert_element);
linklist_traversal(head);
    break;
}

case 2:
{
printf("Enter the data of the element you want to insert in between i.e by index :  \n");
scanf("%d",&insert_element);
printf("Enter the index you want to insert the element :  \n");
//note here index starts from 1 i.e after head i.e it cnt be used to insert at first
scanf("%d",&index);
head=insert_at_index(head,insert_element,index);
linklist_traversal(head);
    break;
}

case 3:
{
 printf("Enter the data of the element you want to insert in between i.e by index :  \n");
scanf("%d",&insert_element);  
head=insert_at_end(head,insert_element);
linklist_traversal(head);
}

case 4:
{ 

   printf("Enter the data of the element you want to insert in between i.e by index :  \n");
   scanf("%d",&insert_element);
   head=insert_at_given_node(head,insert_element,third);// note here third is node after which insertion to take place
   linklist_traversal(head);
}
default:
    break;
}

free(head);
free(second);
free(third);
free(fourth);
}