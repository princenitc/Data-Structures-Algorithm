#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
  struct Node* root = NULL;

void Tcreate()
{
    struct Node *p,*tmp;
    int x;
    struct queue qu;
    createQueue(&qu,100);

    printf("Enter the Node value:\n");
    scanf("%d",&x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&qu,root);
    while(!isEmpty(qu))
    {
        p = dequeue(&qu);
        printf("Enter the left child of %d\n",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            tmp = (struct Node *)malloc(sizeof(struct Node));
            tmp->data = x;
            tmp->lchild = tmp->rchild = NULL;
            p->lchild = tmp;
            enqueue(&qu,tmp);
        }
        printf("Enter the right child of %d\n",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            tmp = (struct Node *)malloc(sizeof(struct Node));
            tmp->data = x;
            tmp->lchild = tmp->rchild = NULL;
            p->rchild = tmp;
            enqueue(&qu,tmp);
        }
    }
}

void preorder(struct Node *p)
{
     if(p)
     {
         printf("%d ",p->data);
         preorder(p->lchild);
         preorder(p->rchild);
     }     
 }
 void Inorder(struct Node *p)
 {
     if(p)
     {
         Inorder(p->lchild);
         printf("%d ",p->data);
         Inorder(p->rchild);
     }      }
void postorder(struct Node *p)
{
     if(p)
     {
         postorder(p->lchild);
         postorder(p->rchild);
         printf("%d ",p->data);
     }     
}
int main()
{
    Tcreate();
    preorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
return 0;
}