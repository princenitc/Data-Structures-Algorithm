#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL;
void push(char x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Stack Overflow\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    char x = -1;
    if(top == NULL)
        printf("Empty stack\n");
    else
    {
        struct Node *p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

char peek(int index)
{
    struct Node *p = top;
    for(int i =0;i<index-1 &&(p) ;i++)
        p = p->next;
    if(p == NULL)
        return -1;
    return p->data;
}
char Top()
{
    if(top)
        return top->data;
    return -1;
}

int isFull()
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    int r = (p) ? 1 : 0;
    free(p);
    return r;
}

int isEmpty()
{
    if(top == NULL)
        return 1;
    return 0;
}
void display()
{
    struct Node *p = top;
    while(p)
    {
        printf("%d ",p->data);
        p  = p->next;
    }
    printf("\n");
}
int pre(char c)
{
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
return 0;
}

int isOperand(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 0;
    return 1;
}
 char * infixToPostfix(char *p)
 {
     char * ans;
     ans = (char*)malloc((strlen(p)+2)*sizeof(char));
     int i =0,j=0;
     while(p[i] != '\0')
     {
         if(isOperand(p[i]))
            ans[j++] = p[i++];
        else
        {
            if(pre(p[i]) > pre(top->data))
                push(p[i++]);
            else
                ans[j++] = pop();
            
        }
     }
    while(top != NULL)
        ans[j++] = pop();
    ans[j] = '\0';
    return ans;
 }

int main()
{
   char *infix = "a+b*c";
   push('#');
   printf("%s \n",infixToPostfix(infix));
    return 0;
}