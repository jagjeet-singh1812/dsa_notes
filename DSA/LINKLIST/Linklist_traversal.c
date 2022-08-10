#include<stdio.h>
#include<stdlib.h>
// link list is used for when we dont know initial max lenght i.e we need to define a[n](n is max lenght) as we need in array . so insertion and deletion is very easy in link list i.e its similar to chain (links)
// They not must be in consecutive memory location.they can be but its not a compusalary condition
// so here a drawback is an extra ptr memeory space is needed ,where as in array no extra memory was required in it
// its end point is when ptr points towards null
// here random access is not allowed as we have in  array as i.e if we know address of index 0 elemnt so we can access at index easily
// link list consist of 2 part i.e a data part and a ptr part

typedef struct node
{
    int data;
    struct node *next;   //self refrencing structure 
}node;
// traversal in link list is of O(n) time complexity

void linklist_traversal(node *ptr)
{ int i=1;
    while(ptr!=NULL)
    {
        printf("Data part of %d node is %d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
}



void main()
{
    int n;
    //here node is struct node as we have used typedef function
// allocate memeory for nodes in the linklist in heaps
  node *head;
  node *second;
  node *third;

  head=(node *)malloc(sizeof(node));
  second=(node *)malloc(sizeof(node));
  third=(node *)malloc(sizeof(node));
//linking first node to second
head->data=12;
head->next=second;

//linking second node to third
second->data=13;
second->next=third;

//linking third node to NULL i.e terminating the list
third->data=14;
third->next=NULL;

// printf("how many more node you need leaving the head:\n");
// scanf("%d",&n);
//     node *a[n];

// for(int i=1;i<n;i++)
// {
//     node *a[i];
//   a[i]=(node *)malloc(sizeof(node));
//     printf("enter the data of %d node:\n",i);
//     scanf("%d",&(a[i]->data));
//     a[i]->next=a[i+1];
// }
//     a[n]->next=NULL;

linklist_traversal(head);
free(head);
free(second);
free(third);
}
