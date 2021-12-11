#include<bits/stdc++.h>
#include "queuecpp.h"
using namespace std;

class Tree
{
    public :
    Node *root;
    Tree(){root = NULL;}
    /*In case if the root declared is private then for any tree tranversal this idea
    can be followed : 
    Declare same function without arguement and inside the function call, call the Normal  funtion i.e. :
    Make the  function without any parameter  :-
    preorder(){
        preorder(root);
    }
    * In the main() function call should be made for the preorder() Not for the preorder(root).
    * The technique used in the above function is Overloading.
    Same as above type of convention can be followed by the other traversal also which uses recursion.*/
    void preorder();
    void CreateTree();
    void preorder(Node *p);
    void inorder(Node *p);
    void postorder(Node *p);
    void levelorder(Node *p);
    int  Height(Node *root);
};

void Tree::CreateTree()
{
    class Node *p,*tmp;
    int x;
    class Queue qu(100);

    printf("Enter the Node value:\n");
    scanf("%d",&x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    qu.enqueue(root);
    while(!qu.isEmpty())
    {
        p = qu.dequeue();
        printf("Enter the left child of %d\n",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            tmp = new Node;
            tmp->data = x;
            tmp->lchild = tmp->rchild = NULL;
            p->lchild = tmp;
            qu.enqueue(tmp);
        }
        printf("Enter the right child of %d\n",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            tmp = (Node *)malloc(sizeof(Node));
            tmp->data = x;
            tmp->lchild = tmp->rchild = NULL;
            p->rchild = tmp;
            qu.enqueue(tmp);
        }
    }
} 

void Tree::preorder(Node *p)
{
     if(p)
    {
         printf("%d ",p->data);
         preorder(p->lchild);
         preorder(p->rchild);
    }     
}
void Tree::inorder(Node *p)
{
     if(p)
    {
         inorder(p->lchild);
         printf("%d ",p->data);
         inorder(p->rchild);
    }     
}
void Tree::postorder(Node *p)
{
     if(p)
    {
         postorder(p->lchild);
         postorder(p->rchild);
         printf("%d ",p->data);
          
}
}
int Tree::Height(Node *root)
{
    int x = 0,y = 0;
    if(root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    return (x>y)?x+1:y+1;
}

void Tree::levelorder(Node *root)
{
    Queue q(100);
    cout << root->data << " ";
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout << root->rchild->data << " ";
        }
    }
    cout << endl;
}
int main()
{
    Tree t;
    t.CreateTree();
    cout << "preorder : \n";
    t.preorder(t.root);
     cout << endl;
    cout << "inorder : \n";
    t.inorder(t.root);
    cout << endl;
    cout << "postorder : \n";
    t.postorder(t.root);
    cout << "\nlevel order : \n";
    t.levelorder(t.root);
    cout << "Height of the tree is : " << t.Height(t.root) << endl;
    return 0;
}