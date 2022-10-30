#include<stdio.h>
#include<conio.h>

// graphs are non linear data structure
// tree is a type of graph only
// graph is collection connection of node or vertices joined with help of edges
// two representation are adjancency matrix(or cost adj matrix) and 
// bfs is breadth first search which one of algorithm for graph traversal

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
  printf("YOUR QUEUE IS+ CREATED\n");
//   


}