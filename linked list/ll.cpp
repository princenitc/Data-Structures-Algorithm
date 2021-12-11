#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node * next; // Self referential pointer
}*first=NULL,*second =NULL, *third = NULL;

void create(int A[],int n)
{
    int i ;
    struct Node *t,*last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i =1;i < n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[],int n)
{
    int i ;
    struct Node *t,*last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i =1;i < n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void Display(struct Node *p) // iterative calling of the printing of the elements of the linked list
{
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void RDislay(struct Node *p) // Recursive calling of printing of list elements in the reverse order.
{
    if(p != NULL) 
    {
        RDislay(p->next); 
        cout << p->data << " ";
    }
}

int countNode(struct Node *p)
{
    int count  = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
return count;
}

int recursiveCountNode(struct Node *p)
{
    if(p)
        return recursiveCountNode(p->next)+1;
    return 0;
}

int elementsSum(struct Node *p)
{
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
return sum;
}

int recursiveSum(struct Node *p)
{
    if(p)
        return recursiveSum(p->next) + p->data;
    return 0; 
}

int maximum(struct Node *p)
{
    int max = INT32_MIN;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
return max;
}

int recursiveMax(struct Node *p)
{
    int x = 0;
    if(p == NULL)
        return INT32_MIN;
    else
    {
        x = recursiveMax(p->next);
       return x>p->data ? x : p->data;
    }
}

bool search(struct Node *p,int key)
{
    while(p)
    {
        if(p->data == key)
            return true;
        p = p->next;
    }
return false;
}
bool Rsearch(struct Node *p, int key)
{
    if(p == NULL)
        return false;
    if(p->data == key)
        return true;
    else
         return Rsearch(p->next,key);
}

bool moveToHeadSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while(p)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return true;
        }
        q = p;
        p = p->next;
    }
return false;
}
void insert(int key, int position)
{
    Node *tmp  = new Node;
    Node *p = first;
    tmp->data = key;
    if(position == 0)
    {
    tmp->next = first;
    first = tmp;
    }
    else
    {
    for(int i =0;i < position-1 && p ;i++)
        p = p->next;
    tmp->next = p->next;
    p->next = tmp;
    }
}

void lastInsertion(int key) // Best way to create and insert in list
{
    Node * last;
    Node *t = new Node;
    t->data = key;
    t->next = NULL;
    if(first == NULL)
        first = last = t;
    else
        last->next = t;
        last = t;
}
void insertionInSortedlist(struct Node * p, int key)
{
    Node *q = NULL;
    Node *t  = new Node;
    if(p == NULL)
        first = t;
    else
    {
    while(p && p->data <= key)
    {
            q = p;
            p = p->next ;   
    }
    if(p == first)
    {
        t->next = first;
        first = t;
    }
    else
    {
    t->data = key;
    t->next = q->next;
    q->next = t;
    }
    }
}

void deleteNode(Node *p,int position)
{
    Node *ptr,*t; // Zero based indexing is used in the deletion
    int x; // if want to  know the deleted value then return this
    ptr = t = first;
    if(position < 0 || position > countNode(p))
    return;
    if(position == 0)
        {
            ptr = first;
            first = p->next;
            x = ptr->data;
            delete ptr;
        }
    else
        {
            for(int i = 0;i < position && p ;i++)
            {
                    ptr = t;
                    t = t->next;                
            }
            ptr->next = t->next;
            x = t->data;
            delete t;
        }
}
bool checkingListSortedOrNot(Node *p)
{
   int x = INT32_MIN;
    while(p)
    {
        if(p->data < x)
            return false;
        x = p->data;
        p = p->next;        
        
    }
    return true;
}

void removeDuplicates(Node *p) // Removing duplicates from the sorted linked list
{
    Node *ptr = p;
    Node *t = p->next;
    while(t)
    {
    if(ptr->data != t->data)
    {
       ptr = t;
       t = t->next;
    }
    else
    {
        ptr->next = t->next;
        delete t;
        t = ptr->next;
    }
    }
}

void reverseList(Node *p) // Reversing a link list using link modification 
// swapping of data is also a way but that is costly
{
    Node *r,*q;
    r = q = NULL;
    while(p)
    {
        r = q ;
        q = p;
        p = p->next;
        q->next = r; 
    }
    first = q;
}



void RReverseList(Node *q,Node *p) // Recursive reversing of llist
{
    if(p != NULL)
    {
        RReverseList(p,p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
void concatenate(Node *p,Node *q)
{
    third = p;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
}


void mergeList(Node *p,Node *q)
{
    Node * last;
    if(p->data <= q->data)
    {
       third = last = p;
       p = p->next;
       last->next = NULL;
    }
    else
    {
       third = last = q;
       q = q->next;
       last->next = NULL;
    }
    while(p && q)
    {
         if(p->data <= q->data)
    {
       last->next = p;
       last = p;
       p = p->next;
       last->next = NULL;
    }
    else
    {
       last->next = q;
       last = q;
       q = q->next;
       last->next = NULL;
    }
    }
    if(p)
        last->next = p;
    if(q)
        last->next = q;
}



bool isLoop(Node *f)
{
   Node *p,*q;
   p = q = f;
   do
   {
       p = p->next;
       q = q->next;
       (q !=NULL) ? q = q->next : q;
   }while(p && q && p != q);
   if(p == q)
    return true;
    else 
    return false;
}



int main()
{
    Node *t1,*t2;

    int A[] = {10,20,30,40,50,60,70};
    create(A,7);

    t1 = first->next->next;
    t2 = first->next->next->next->next->next->next;
    t2->next = t1;
    cout << isLoop(first) << endl;   
return 0;
}
