
#include<stdio.h>
#include<stdlib.h>

 struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void createQueue(struct queue *q,int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node**)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct queue *q,  struct Node *x)
{
    if((q->rear+1)%q->size == q->front)
        printf("queue is full\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

 struct Node* dequeue(struct queue *q)
{
    struct Node *x = NULL;
    if(q->front == q->rear)
        printf("queue is empty\n");
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct queue q)
{
    if(q.front == q.rear)
        return 1;
    return 0;
}