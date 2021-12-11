#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void push(struct stack *st,int x)
{
    if(st->top ==  st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
int pop(struct stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack st,int index)
{
    int x = -1;
    if(st.top-index+1 <= -1)
        printf("Invalid Position\n");
    else
        x = st.s[st.top-index+1];
    return x;
}
int isEmpty(struct stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int top(struct stack st)
{
    if(st.top == -1)
    return -1;
    return st.s[st.top];
}

int isFull(struct stack st)
{
    if(st.top == st.size-1)
    return 1;
    return 0;  
}
void create(struct stack *st)
{
    printf("Enter the size of the stack\n");
    scanf("%d",&st->size);
    st->s = (int *)malloc(st->size*sizeof(int));
    st->top = -1;
}
void display(struct stack st)
{
    for(int i = st.top;i >= 0;i--)
        printf("%d ",st.s[i]);
    printf("\n");
}
int main()
{
    struct stack st;
    create(&st);
   // push(&st,10);
    //push(&st,20);
   // push(&st,30);
  //  push(&st,40);
    //push(&st,50);
    printf("%d\n",isEmpty(st));
    printf("%d\n",isFull(st));
    display(st);
}