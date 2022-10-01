#include <stdio.h>
#include <stdlib.h>
// queue is fifo(first in first out) Algorithm
// its can be implemented using array,linklist as well as stacks and other adts also
// enqueue is o(1) and dequeue is o(n)time complexity
//  first elemnt is at rear+1 and last is front
//here problem is its not efficient its inperspective of space complexity
//here problem  is also static memory allocation due to array used 
// we can also implement it with help of linklist and stacks 
typedef struct queue
{
  int size;
  int *arr;
  int rear;
  int front;
} queue;

int isempty(queue *q)
{
  if (q->rear == q->front)
  {
    return 1;
  }
  return 0;
}
int isfull(queue *q)
{
  if (q->rear == q->size - 1)
  {
    return 1;
  }
  return 0;
}

void enqueue(queue *q, int val)
{
  if (isfull(q))
  {
    printf("QUEUE OVERFLOW\n");
  }
  else
  {
    q->rear++;

    q->arr[q->rear] = val;
    printf("THE VALUE %d HAS BEEN ENTERED TO THE QUEUE\n", val);
  }
}

int dequeue(queue *q)
{
  int a;
  if (isempty(q) == 1)
  {
    printf("UNDERFLOW QUEUE\n");
    a = -1;
  }
  else
  {
    q->front++;
    a = q->arr[q->front];
  }
  return a;
}

void getrear(queue *q)
{
  if (isempty(q))
  {
    printf("QUEUE IS EMPTY\n");
  }
  else
  {
    printf("REAR VALUE: %d\n", q->arr[q->rear]);
  }
}

void getfront(queue *q)
{
  if (isempty(q))
  {
    printf("QUEUE IS EMPTY\n");
  }

  else
  {
    printf("FRONT VALUE: %d\n", q->arr[q->front+1]);
  }
}

void display(queue *q)
{
  if (isempty(q))
  {
    printf("QUEUE IS EMPTY\n");
  }
  else
  {
    printf("ELEMENTS ARE:");
    for (int i=q->front+1; i <=q->rear; i++)
    {
      printf("%d ", q->arr[i]);
    }
  }
}

void getsize(queue q)
{
  printf("SIZE OF QUEUE: %d\n", q.rear - q.front);
  // int count;
  // for(int i=q.front;i<=q.rear;i++ )
  // {
  //     count++;
  // }
  // printf("count: %d",count);
}

void main()
{
  int n, option, z;
  queue q;
  printf("ENTER THE MAX SIZE OF QUEUE YOU WANT:\n");
  scanf("%d", &n);
  // queue* q = (queue *)malloc(sizeof(queue));
  q.size = n;
  q.front = q.rear = -1;
  q.arr = (int *)malloc(q.size * sizeof(int));
  printf("YOUR QUEUE IS CREATED\n");
  do
  {
    printf("ENTER 1 FOR ENQUEUE\n");
    printf("ENTER 2 FOR DEQUEUE\n");
    printf("ENTER 3 FOR VALUE OF FRONT\n");
    printf("ENTER 4 FOR VALUE OF REAR\n");
    printf("ENTER 5 FOR SIZE\n");
    printf("ENTER 6 FOR DISPLAY\n");
    printf("ENTER YOUR OPTION:\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
    {
      int value;
      printf("enter value of value you want to enter\n");
      scanf("%d", &value);
      enqueue(&q, value);
      break;
    }

    case 2:
    {
      int result = dequeue(&q);
      printf("the element %d has been removed from the queue\n", result);
      break;
    }
    case 3:
    {
      getfront(&q);
      break;
    }
    case 4:
    {
      getrear(&q);
      break;
    }
    case 5:
    {
      getsize(q);
      break;
    }
    case 6:
    {
      display(&q);
      break;
    }

    default:
    {
      printf("wrong option selection\n");
    }
    }
    printf("do you want to continue(if yes press 1 else press 0)");
    scanf("%d", &z);
  } while (z == 1);
}