#include<stdio.h>
#include<stdlib.h>

// All the other functionlities of the avl tree function can be taken from the other bst codes.
struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;
int nodeHeight(struct Node *p)
{
    int h1,h2;
    h1 = (p && p->lchild) ? p->lchild->height : 0;
    h2 = (p && p->rchild) ? p->rchild->height : 0;
    return (h1 > h2) ? h1+1 : h2+1;
}

struct Node* LLRotation(struct Node *p)
{
   struct Node *pl,*plr;
   pl = p->lchild;
   plr = pl->rchild;
   pl->rchild = p;
   p->lchild = plr; 

   p->height = nodeHeight(p);
   pl->height = nodeHeight(pl);

   if(p == root)
    root = pl;

    return pl;
}

struct Node* RRRotation(struct Node *p)
{
   struct Node *pr,*prl;
   pr = p->rchild;
   prl = pr->lchild;
   pr->lchild = p;
   p->rchild = prl; 

   p->height = nodeHeight(p);
   pr->height = nodeHeight(pr);

   if(p == root)
    root = pr;

    return pr;
}

struct Node* LRRotation(struct Node *p)
{
    struct Node *pl,*plr;
    pl = p->lchild;
    plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if(root == p)
        root = plr;
    return plr;
}
struct Node* RLRotation(struct Node *p) // done by me
{
    struct Node *pr,*prl;
    pr = p->rchild;
    prl = pr->lchild;

    pr->lchild = prl->lchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if(root == p)
        root = prl;
    return prl;

}
int balanceFactor(struct Node *p) // it is height of left subtree - height of right subtree
{
    int h1,h2;
    h1 = (p && p->lchild) ? p->lchild->height : 0;
    h2 = (p && p->rchild) ? p->rchild->height : 0;
    return h1-h2;
}


struct Node* Rinsert(struct Node *p, int key)
{
    struct Node *t;
    if(p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = Rinsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = Rinsert(p->rchild,key);
    p->height = nodeHeight(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLRotation(p);
    return p;
}
int main()
{
    root = Rinsert(root,90);
    Rinsert(root,80);
    Rinsert(root,85);
    printf("%d\n",root->data);
return 0;
}