#include <stdio.h>
#include <stdlib.h>

typedef struct node1
{
    int data;
    struct node1 *next;
} node;

node *head = NULL;

node *create_li(node *head)
{
    int number, value;
    node *ptr = (node *)malloc(sizeof(node));
    printf("ENTER THE NUMBER OF NODES YOU WANT TO ENTER :-\n");
    scanf("%d", &number);
        printf("ENTER THE DATA PART OF NODE YOU WANT TO ENTER:-\n");
        scanf("%d",&value);

       if (head == NULL)
        {  ptr->data = value;
            ptr->next=ptr;
            head = ptr;
            printf("%d has been added in linlist\n",ptr->data);
        }
    for (int i = 0; i < number-1; i++)
    {
        printf("ENTER THE DATA PART OF NODE YOU WANT TO ENTER:-\n");
        scanf("%d",&value);
        int i=2;
            node *q;
            q = head;
            while (q->next != head)
            {
                q = q->next;
            }
              ptr->data = value;
            q->next = ptr;
            ptr->next = head;
            printf("%d has been added at %d in linlist\n",ptr->data,i);
            i++;
        }
    
    return head;
}

node * traversal_in_circular_linklist(node *head)
{

    node *ptr;
    ptr = head;
    int i = 0;
    // do
    // {
    //     // here index 0 means the head;
    //     printf("the data part of %d node  is %d\n", i, ptr->data);
    //     ptr = ptr->next;
    //     i++;
    // } while (ptr->next!= head);
    //  printf("the data part of %d node  is %d\n", i, ptr->data);
    // return head;

 printf("the data part of %d node  is %d\n", i, ptr->data);
 ptr = ptr->next;
    while(ptr->next!=head)
    {
        // here index 0 means the head;
        printf("the data part of %d node  is %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

node *insert_at_first_in_circular_linklist(node *head, int insert_element)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *q;
    ptr->data = (insert_element);
    q = head;
    while (q->next != head)
    {
        q = q->next;
    }
    q->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

node *insertatend(node *head, int val)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *q;
    ptr->data = (val);
    q = head;
    while (q->next != head)
    {
        q = q->next;
    }
    q->next = ptr;
    ptr->next = head;
    return head;
}

void main()
{
int option,insert_element,index;
    // int option,insert_element,index;
    // node *head = (node *)malloc(sizeof(node));
    // node *second = (node *)malloc(sizeof(node));
    // node *third = (node *)malloc(sizeof(node));
    // node *fourth = (node *)malloc(sizeof(node));

    // head->data = 10;
    // head->next = second;

    // second->data = 12;
    // second->next = third;

    // third->data = 14;
    // third->next = fourth;

    // fourth->data = 16;
    // fourth->next = head; // this is main step in circular linklist
    



    printf("Enter 1 to create a circular linklist:\n");
    printf("Enter 2 for display:\n");
    printf("Enter 3 for insertion at start/beginning of an linklist:\n");
    printf("Enter 4 for insertion at any index of an linklist:\n");
    printf("Enter 5 for insertion at end of an linklist:\n");
    printf("Enter 6 for insertion at given node of an linklist:\n");
    printf("Enter the option you want to select:\n");
    scanf("%d",&option);

     switch (option)
     {

     case 1:
     {

    head=create_li(head);
    printf("The elements of circular linklist are:-\n");
    head=traversal_in_circular_linklist(head);
   // break;
     }
     case 2:
     {
        head=traversal_in_circular_linklist(head);
      //break;
     }

    case 3:
    {

        
     printf("Enter the data of the element you want to insert at first:\n");
     scanf("%d",&insert_element);
     head=insert_at_first_in_circular_linklist(head,insert_element);
    traversal_in_circular_linklist(head);
         //break;
     

    }
    case 4:{

//  printf("Enter the data of the element you want to insert in between i.e by index :  \n");
//      scanf("%d",&insert_element);
//      printf("Enter the index you want to insert the element :  \n");
//      scanf("%d",&index);
//       //note here index starts from 1 i.e after head i.e it cnt be used to insert at first/ scanf("%d",&index);
//      head=insert_at_index(head,insert_element,index);
//      traversal_in_circular_linklist(head);
//          break;

    }

    case 5:
    {
    printf("Enter the data of the element you want to insert in end :  \n");
    scanf("%d",&insert_element);
    head=insertatend(head,insert_element);
    traversal_in_circular_linklist(head);
    }

    case 6:{
//    printf("Enter the data of the element you want to insert in between i.e by index :  \n");
//        scanf("%d",&insert_element);
//        head=insert_at_given_node(head,insert_element,head);// note here third is node after which insertion to take place
//        linklist_traversal(head);
    }
    default:
        break;
    }

    free(head);

}