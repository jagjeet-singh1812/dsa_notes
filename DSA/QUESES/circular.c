#include <stdio.h>
#include <stdlib.h>
 //use for efficiently use space in queue (SPACE COMPLEXITY)
 //circular increment is ex-  q->rear=(q->rear+1)%(q->size)
 //here one index that is arr[0]is front (front=rear=0) for checking is full 
typedef struct circularqueue
{
  int size;
  int *arr;
  int rear;
  int front;
} queue;

int isempty(queue *q)
{
  if (q->rear==q->front==-1)
  {
    return 1;
  }
  return 0;
}


int isfull(queue *q)
{
  if ((q->rear+1)%q->size == q->front)
  {
    return 1;
  }
  return 0;
}

void enqueue(queue *q, int val)
{
  if (isfull(q))
  {
    printf("CIRCULAR QUEUE OVERFLOW\n");
  }
  else if(isempty(q))
  {
       q->front=q->rear=0;
       q->arr[q->rear]=val;
    printf("THE VALUE %d HAS BEEN ENTERED AS THEFIRST ELEMENT OF THE QUEUE\n", val);
  }
  else
  {
    q->rear=(q->rear+1)%(q->size);
    q->arr[q->rear] = val;
    printf("THE VALUE %d HAS BEEN ENTERED TO THE QUEUE\n", val);
  }
}

int dequeue(queue *q)
{
  int a;
  if (isempty(q))
  {
    printf("UNDERFLOW CIRCULAR QUEUE\n");
    a = -1;
  }
  else if(q->rear==q->front){
  q->front=q->rear;
  }
  else
  {
    q->front=(q->front+1)% q->size;
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
    printf("FRONT VALUE: %d\n", q->arr[q->front]);
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
    int i=q->front;
    printf("ELEMENTS ARE:");
    // for (int i=q->front; i <=q->rear; (i+1)q->size)
    // {
    //   printf("%d ", q->arr[i]);
    // }
    while(i!=q->rear){
      printf("%d ",q->arr[i]);
      i=(i+1)/q->size;
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
  printf("YOUR CIRCULAR QUEUE IS CREATED\n");
  do
  {
    printf("ENTER 1 FOR ENQUEUE IN CIRCULAR QUEUE\n");
    printf("ENTER 2 FOR DEQUEUE IN CIRCULAR QUEUE\n");
    printf("ENTER 3 FOR VALUE OF FRONT IN CIRCULAR QUEUE\n");
    printf("ENTER 4 FOR VALUE OF REAR IN CIRCULAR QUEUE\n");
    printf("ENTER 5 FOR SIZE IN CIRCULAR QUEUE\n");
    printf("ENTER 6 FOR DISPLAY IN CIRCULAR QUEUE\n");
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
