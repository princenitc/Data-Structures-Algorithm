#include<iostream>

using namespace std;

struct Node 
{
    Node *prev;
    int data;
    Node *next;
}*first = NULL;

void create(int A[],int n)
{
     Node *t,*last;
     int i ;
     first = new Node;
     first->data = A[0];
     first->prev = first->next = NULL;
     last = first;
     for(i = 1;i< n;i++)
     {
         t = new Node;
         t->data = A[i];
         t->next = last->next;
         t->prev = last;
         last->next = t;
         last = t;
     }
}

void Display(Node *p)
{
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int Length(Node *p)
{
    int count = 0;
   while(p)
   {
       count++;
       p = p->next;
   }
   return count;
}
void Insert(Node *p,int pos,int x)
{
    Node *t;
    int i ;

    if(pos < 0 || pos > Length(p))
        return ;
    if(pos == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for(i = 0;i < pos -1;i++)
            p = p->next;
        t = new Node;
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
}
int  Delete(Node *p,int pos)
{
    int x;
    if(pos < 1 || pos > Length(p))
        return -1;
    if(pos == 1)
    {
       first = first->next;
       if(first) first->prev = NULL;

       x = p->data;
       free(p);
    }
    else
    {
    for(int i = 0;i < pos -1;i++)
        p = p->next;

    p->prev->next = p->next;
    if(p->next) p->next->prev = p->prev;
    x = p->data;
    free(p);
    }
    return x;
}

void reverseList(Node *p)
{
    Node *tmp;
 while(p)
 {
     tmp = p->next;
     p->next = p->prev;
     p->prev = tmp;
     p = p->prev;
     if(p != NULL && p->next == NULL)
        first = p;
 }
}
int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    cout << Length(first) << endl;
    reverseList(first);
    Display(first);
    return 0;
}