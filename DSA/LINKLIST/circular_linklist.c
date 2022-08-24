#include <stdio.h>
#include <stdlib.h>

typedef struct node1
{
    int *data;
    struct node1 *next;
} node;


void traversal_in_circular_linklist(node *head)
{

    node * ptr=(node*)malloc(sizeof(node));
    ptr=head;
    // printf("The data part of head node is %d\n",head->data);
    // int i=1;
    // while(ptr->next!=head)
    // {
    // ptr=ptr->next;
    // printf("The data part of %d node is %d\n",i,ptr->data);
    // i++;
    // }
    int i=0;
do{
 //here index 0 means the head;
    printf("the data part of %d node  is %d\n",i,ptr->data);
    ptr=ptr->next;
    i++;
}while(ptr!=head);

}

node *insert_at_first_in_circular_linklist(node *head,int insert_element)
{
    node *ptr=( node* )malloc(sizeof(node));
    node *q=( node* )malloc(sizeof(node));
    ptr->data=insert_element;
    q=head->next;
    while(q->next!=head)
    {
      q=ptr->next;
    }
    q->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}


void main()
{

int option,insert_element,index;
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));

    head->data = 10;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 16;
    fourth->next = head;//this is main step in circular linklist
printf("The elements of circular linklist are:-\n");
traversal_in_circular_linklist(head);

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
 printf("Enter the data of the element you want to insert at first:\n");
 scanf("%d",&insert_element);
 head=insert_at_first_in_circular_linklist(head,45);
traversal_in_circular_linklist(head);
     break;
 }

 case 2:
 {
 printf("Enter the data of the element you want to insert in between i.e by index :  \n");
 scanf("%d",&insert_element);
 printf("Enter the index you want to insert the element :  \n");
 scanf("%d",&index);
  //note here index starts from 1 i.e after head i.e it cnt be used to insert at first/ scanf("%d",&index);
 head=insert_at_index(head,insert_element,index);
 linklist_traversal(head);
     break;
 }

// case 3:
// {
//  printf("Enter the data of the element you want to insert in between i.e by index :  \n");
// scanf("%d",&insert_element);  
// head=insert_at_end(head,insert_element);
// linklist_traversal(head);
// }

// case 4:
// { 

//    printf("Enter the data of the element you want to insert in between i.e by index :  \n");
//    scanf("%d",&insert_element);
//    head=insert_at_given_node(head,insert_element,third);// note here third is node after which insertion to take place
//    linklist_traversal(head);
// }
// default:
//     break;
}

free(head);
free(second);
free(third);
free(fourth);
}