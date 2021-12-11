#include<bits/stdc++.h>

using namespace std;

class Node
{
    public :
    Node *lchild;
    int data;
    Node* rchild;
};
class BST
{
    private : 
    Node *root;
    public :
    BST(){root = nullptr;}
    Node* getRoot();
    void setRoot(Node *p){root = p;}
    Node *Rinsert(Node *p,int key);
    void iterativeInsert(int key);
    Node* search(int key);
    void inorder(Node* p);
    Node* Delete(Node* p,int key);
    Node* InSucc(Node* p);
    Node* InPrede(Node* p);
    int height(Node* p);
    Node* Rsearch(Node *p,int key);
};
Node* BST::Rsearch(Node *p,int key)
{
    if(p == nullptr)
        return nullptr;
    if(p->data == key)
        return p;
    else if (key < p->data)
        return Rsearch(p->lchild,key);
    else if (key > p->data)
        return Rsearch(p->rchild,key);
    return nullptr;
}
Node* BST::getRoot()
{
    return root;
}
Node* BST::Rinsert(Node *p, int key)
{
    Node* t;
    if(p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        return t;
    }
    if(key < p->data)
        p->lchild = Rinsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = Rinsert(p->rchild,key);
    return p;
}

void BST::iterativeInsert(int key)
{
    Node *t = root;
    Node *r,*p;
    if(root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
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

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    if(key < r->data)
        r->lchild  = p;
    else
        r->rchild = p;
}


void BST::inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}


Node * BST::search(int key)
{
   Node *t = root;
   while(t)
   {
        if(t->data == key)
        return t;
        else if(t->data > key)
            t = t->lchild;
        else if(t->data < key)
            t= t->rchild;
   }
   return nullptr;
}

int BST::height(Node * p)
{
    int x,y;
    if(p == nullptr) return -1;
    x = height(p->lchild);
    y = height(p->rchild);
    return (x>y) ? x+1 : y+1;
}

Node* BST::InPrede(Node *p)
{
     while(p && p->rchild != nullptr)
        p = p->rchild;
    return p;
}

Node* BST::InSucc(Node *p)
{
     while(p && p->lchild != nullptr)
        p = p->lchild;
    return p;
}

Node* BST::Delete(Node *p,int key)
{
    Node *q;
    if(p == nullptr)
        return nullptr;
    if(p->lchild == nullptr && p->rchild == nullptr && p->data == key)
    {
        if(p == root)
            root = nullptr;
        delete p;
        return nullptr;
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
    
    BST ftree;
    ftree.iterativeInsert(10);
    ftree.iterativeInsert(1);
    ftree.iterativeInsert(3);
    ftree.iterativeInsert(5);
    ftree.iterativeInsert(15);
    ftree.iterativeInsert(12);
    ftree.iterativeInsert(16);
    ftree.inorder(ftree.getRoot());
    cout << endl;
    (ftree.search(16) != nullptr) ? cout << "Iterative found\n" : cout << "Iterative Not found\n";
    (ftree.Rsearch(ftree.getRoot(),16) != nullptr) ? cout << "Recursive found\n" : cout << "Recursive not found\n";
    cout << ftree.height(ftree.getRoot()) << endl;
    ftree.Delete(ftree.getRoot(),12);
    ftree.inorder(ftree.getRoot());
    cout << endl << ftree.InPrede(ftree.getRoot()->lchild)->data;
    cout << endl << ftree.InSucc(ftree.getRoot()->rchild)->data << endl;
    // This is all the test cases for the iterative methodology 
    cout << "---------------------------\n";
    BST stree;
    Node *first;
    first = stree.Rinsert(stree.getRoot(),10); // first value is inserted
    stree.setRoot(first);                // after the first insertion you need to make the first node as the root node;
    stree.Rinsert(stree.getRoot(),1);
    stree.Rinsert(stree.getRoot(),3);
    stree.Rinsert(stree.getRoot(),5);
    stree.Rinsert(stree.getRoot(),15);
    stree.Rinsert(stree.getRoot(),12);
    stree.Rinsert(stree.getRoot(),16);
    stree.inorder(stree.getRoot());
    cout << endl;
    (stree.search(10) != nullptr) ? cout << "Iterative found\n" : cout << "Iterative Not found\n";
    (stree.Rsearch(stree.getRoot(),16) != nullptr) ? cout << "Recursive found\n" : cout << "Recursive not found\n";
    cout << stree.height(stree.getRoot()) << endl;
    stree.Delete(stree.getRoot(),12);
    stree.inorder(stree.getRoot());
    cout << endl << stree.InPrede(stree.getRoot()->lchild)->data;
    cout << endl << stree.InSucc(stree.getRoot()->rchild)->data << endl;
return 0;
}