#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node * next;
}*Head;

void create(int A[],int n)
{
    int i ;
    struct Node *t,*last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for(i = 1;i < n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(Node *h)
{
    do
    {
        cout << h->data << " ";
        h = h->next;
    }while(h != Head);
    cout << endl;    
}
void RDisplay(Node *h)
{
    static int flag = 0;
    if(h != Head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(Node *p)
{
    int count = 0;
    do
    {
        count++;
        p = p->next;

    } while (p != Head);
    return count;
}

void Insert(Node *p,int index,int x) // Normal indexing from 1 onwards
{
    Node *t;
    int i;
    if(index < 0 || index > Length(p))
        return;
    if(index == 0)
    {
        t = new Node;
        t->data = x;
        if(Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while(p->next != Head) p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for(i = 0;i < index-1;i++) p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
void Delete(Node *p,int index)
{
    Node *q;
    int i;
    if(index < 0  || index > Length(Head))
        return;
    if(index == 1)
    {
        while(p->next != Head) p = p->next;
        if(Head == p)
            {
                delete Head;
                Head == NULL;
            }
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
    for(int i = 0;i < index-2;i++) p = p->next;
    q = p->next;
    p->next = q->next;
    delete q;
    }
}
int main()
{

    int A[] = {2,3,4,5,6};
    create(A,5);
    Delete(Head,3);
    RDisplay(Head);
    cout << endl;

}