#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q)
{
    printf("Enter the size of quque\n");
    scanf("%d",&q->size);
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q,int x)
{
    if(q->rear == q->size -1)
        printf("queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue *q)
{
    int x;
    if(q->front == q->rear)
        printf("queue is empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct queue q)
{
    for(int i = q.front+1 ; i <= q.rear;i++)
        printf("%d ",q.Q[i]);
    printf("\n");
}
int main()
{
    struct queue qu;
    create(&qu);
    enqueue(&qu,10);
    enqueue(&qu,30);
    enqueue(&qu,40);
    enqueue(&qu,50);
    enqueue(&qu,70);
    dequeue(&qu);
    Display(qu);
return 0;
}