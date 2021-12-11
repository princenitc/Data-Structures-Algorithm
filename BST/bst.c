#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;
// for recursive insert to work we need to pass the node element also 
struct Node* Rinsert(struct Node *p, int key)
{
    struct Node *t;
    if(p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = Rinsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = Rinsert(p->rchild,key);

    return p;
}

void iterativeInsert(int key)
{
    struct Node *t = root;
    struct Node *r,*p;
    if(root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
        while(t)
        {
            r = t;
            if(key < t->data)
                t = t->lchild;
            else if(key > t->data)
                t = t->rchild;
            else
                return;
        }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key < r->data)
        r->lchild  = p;
    else
        r->rchild = p;
}


void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}


struct Node * search(int key)
{
   struct Node *t = root;
   while(t)
   {
        if(t->data == key)
        return t;
        else if(t->data > key)
            t = t->lchild;
        else if(t->data < key)
            t= t->rchild;
   }
   return NULL;
}

int height(struct Node * p)
{
    int x,y;
    if(p == NULL) return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return (x>y) ? x+1 : y+1;
}

struct Node* InPrede(struct Node *p)
{
     while(p && p->rchild != NULL)
        p = p->rchild;
    return p;
}
struct Node* InSucc(struct Node *p)
{
     while(p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct Node * Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p == NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if(key < p->data)
        p->lchild= Delete(p->lchild,key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild,key);
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q = InPrede(p->lchild);
            p->data = q->data;
            p->lchild =  Delete(p->lchild,q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild ,q->data);
        }
    }
    return p;
}

int main()
{

    root = Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,20);
    Rinsert(root,8);
    Rinsert(root,30);
    Delete(root,10);
    inorder(root);
    if(search(10) == NULL)
        printf("\nNot found");
    else
        printf("\nfound !");
    return 0;
}