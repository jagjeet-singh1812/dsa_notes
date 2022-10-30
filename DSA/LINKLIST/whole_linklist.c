#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *create_li(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_before(struct node *);
struct node *delete_li(struct node *);
struct node *sort_li(struct node *);

int main()
{
    int option;
    printf("** MAIN-MENU**\n");
    printf("1.Create a list\n");
    printf("2.Display a list\n");
    printf("3.Add a node at beginning\n");
    printf("4.Add a node at the end\n");
    printf("5.Add a node before a given node\n");
    printf("6.Add a node after a given node\n");
    printf("7.Delete a node at beginning\n");
    printf("8.Delete a node at the end\n");
    printf("9.Delete a node before a given node\n");
    printf("10.Delete a node after a given node\n");
    printf("11.Delete the entire list\n");
    printf("12.Sort the list\n");
    printf("13.Exit\n");
    do
    {
        printf("Entire Your Choice:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = create_li(head);
            printf("List Created\n");
            break;
        case 2:
            head = display(head);
            printf("\n");
            break;
        case 3:
            head = insert_beg(head);
            break;
        case 4:
            head = insert_end(head);
            break;
        case 5:
            head = insert_before(head);
            break;
        case 6:
            head = insert_after(head);
            break;
        case 7:
            head = delete_beg(head);
            break;
        case 8:
            head = delete_end(head);
            break;
        case 9:
            head = delete_before(head);
            break;
        case 10:
            head = delete_after(head);
            break;
        case 11:
            head = delete_li(head);
            printf("List Deleted");
            break;
        case 12:
            // head = sort_li(head);
            break;
        default:
            printf("Please choose between 1-13");
        }
    } while (option != 13);
    return 0;
}


struct node *create_li(struct node *head)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end \n");
    printf("Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (head == NULL)
        {
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
            printf("\n Enter the data: ");
            scanf("%d", &num);
        }
    }
        return head;
}

struct node *display(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        ptr = head;
        while (ptr!= NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

struct node *insert_beg(struct node *head)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return head;
}

struct node *insert_before(struct node *head)
{
    struct node *new_node, *ptr, *preptr;
    int val;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    printf("Enter the value before which the data need to be inserted: ");
    scanf("%d", &val);
    ptr = head;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return head;
}

struct node *insert_after(struct node *head)
{
    struct node *new_node, *ptr, *preptr;
    int val;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    printf("Enter the value after which the data need to be inserted: ");
    scanf("%d", &val);
    ptr = head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return head;
}

struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *delete_end(struct node *head)
{
    struct node *ptr, *preptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return head;
}

struct node *delete_before(struct node *head)
{
    struct node *ptr, *preptr;
    int val;
    printf("Enter the value after which the data need to be deleted: ");
    scanf("%d", &val);
    ptr = head;
    if (ptr->data == val)
    {
        delete_beg(head);
        return head;
    }
    else
    {
        while (preptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return head;
    }
}

struct node *delete_after(struct node *head)
{
    struct node *ptr, *preptr;
    int val;
    printf("Enter the value after which the data need to be deleted: ");
    scanf("%d", &val);
    ptr = head;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return head;
}

struct node *delete_li(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        head = delete_beg(ptr);
        ptr = ptr->next;
    }
    return head;
}