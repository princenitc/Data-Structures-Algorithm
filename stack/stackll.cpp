#include<iostream>

using namespace std;

class Node
{
    public :
    int data;
    Node *next;
};
class stack
{
    Node *top;
    public :
    stack() {top = NULL;};
    void push(int x);
    int pop();
    void display();
    int isEmpty();
    int isFull();
    int Top();
    int peek(int x);
};
void stack::push(int x)
{
    Node *t = new Node;
    if(t == NULL)
        printf("Stack Overflow\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int stack::pop()
{
    int x = -1;
    if(top == NULL)
        printf("Empty stack\n");
    else
    {
         Node *p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

int stack::peek(int index)
{
    struct Node *p = top;
    for(int i =0;i<index-1 &&(p) ;i++)
        p = p->next;
    if(p == NULL)
        return -1;
    return p->data;
}
int stack::Top()
{
    if(top)
        return top->data;
    return -1;
}

int stack:: isFull()
{
    Node *p = new Node;
    int r = (p) ? 1 : 0;
    free(p);
    return r;
}

int stack::isEmpty()
{
    if(top == NULL)
        return 1;
    return 0;
}
void stack::display()
{
     Node *p = top;
    while(p)
    {
        printf("%d ",p->data);
        p  = p->next;
    }
    printf("\n");
}

int main()
{
    stack st;
    st.push(20);
    st.push(30);
    st.push(11);
    st.push(99);
    st.display();
    st.pop();
    st.pop();
    cout << st.peek(2) <<endl;
    st.display();
    return 0;
}