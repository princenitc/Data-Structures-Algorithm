
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    Node *lchild;
    int data;
    Node *rchild;
};
class Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
    public:
    Queue() {front = rear = -1;size = 10;Q = new Node*[size];}
    Queue(int size){front = rear = -1;this->size = size;Q = new Node*[this->size];}
    void enqueue(Node *x);
    Node* dequeue();
    bool isEmpty();
};

void Queue::enqueue(Node *x)
{
    if((rear+1)%size == front)
        printf("queue is full\n");
    else
    {
        rear = (rear + 1)%size;
        Q[rear] = x;
    }
}

Node* Queue::dequeue()
{
    Node *x = NULL;
    if(front == rear)
        printf("queue is empty\n");
    else
    {
        front = (front +1)%size;
        x = Q[front];
    }
    return x;
}
bool Queue::isEmpty()
{
    if(front == rear)
        return true;
    return false;
}
