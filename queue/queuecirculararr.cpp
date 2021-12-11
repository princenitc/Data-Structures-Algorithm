#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q)
{
    printf("Enter the size of quque\n");
    scanf("%d",&q->size);
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size == q->front)
        printf("queue is full\n");
    else
    {
        q->rear = (q->rear + 1)%q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x;
    if(q->front == q->rear)
        printf("queue is empty\n");
    else
    {
        q->front = (q->front +1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    int  i = q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i = (i+1)%q.size;
        /* code */
    } while (i != (q.rear + 1)%q.size);
    
    printf("\n");
}
int main()
{
    struct Queue qu;
    create(&qu);
    enqueue(&qu,10);
    enqueue(&qu,30);
    enqueue(&qu,40);
    enqueue(&qu,50);
    enqueue(&qu,70);
    Display(qu);
return 0;
}