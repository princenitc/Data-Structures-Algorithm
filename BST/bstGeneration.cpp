#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public :
    Node *lchild ;
    int data ;
    Node *rchild;
}*root = nullptr;
void create(int pre[],int n)
{
    stack<Node*>stk;
    Node *t;
    int i =0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = root->rchild = nullptr;
    Node *p = root;
    while(i < n)
    {
        if(pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if(( pre[i] < (stk.empty() ? INT32_MAX : stk.top()->data)) && pre[i] > p->data)
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = nullptr;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}
void inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
int main()
{
    int arr[] = {30,20,10,15,25,40,50,45};
    create(arr,(sizeof(arr))/sizeof(arr[0]));
    inorder(root);
return 0;
}