#include<bits/stdc++.h>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class Tree{
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }  // Passing Private Parameter in Constructor
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }
    int Height(Node* p);
    int Height() { return Height(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
    void iterativeLevelorder(Node *p); 
    void iterativeLevelorder(){iterativeLevelorder(root);}
    int count(Node *p);
    int count(){return count(root);}
    int countLeaves(Node *p);
    int countLeaves(){return countLeaves(root);}
    int countDegree1(Node *p);
    int countDegree1(){return countDegree1(root);}
    int countDegree2(Node *p);
    int countDegree2(){return countDegree2(root);}
    int Sum(Node *p);
    int Sum(){return Sum(root);}
};
 
Tree::Tree() {
    root = nullptr;
}
 
Tree::~Tree() {
    // TODO
}
 
void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;
 
    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);
 
    while (! q.empty()){
        p = q.front();
        q.pop();
 
        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }
 
        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}
 
void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
 
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}
 
void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    cout << root->data << ", " << flush;
    q.emplace(root);
 
    while (! q.empty()){
        p = q.front();
        q.pop();
 
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }
 
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}
 
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return -1;
    }
 
    l = Height(p->lchild);
    r = Height(p->rchild);
 
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

int Tree::count(Node *p) // counting the no of the nodes present in the tree
{
    if(p)
        return count(p->lchild) + count(p->rchild) + 1;
    return 0;
}

int Tree::countLeaves(Node *p) // counting the no of the leave nodes present in the tree
{
    if(p)
    {
        if(!p->lchild && !p->rchild)
            return countLeaves(p->lchild)+countLeaves(p->rchild)+1;
        return countLeaves(p->lchild) + countLeaves(p->rchild) ;
    }
    return 0;
}
int Tree::countDegree1(Node *p) // counting all the Nodes with the degree 1
{
    if(p)
    {
        if((!p->lchild && p->rchild) || (p->lchild && !p->rchild))
            return countDegree1(p->lchild) + countDegree2(p->rchild) + 1;
        return countDegree1(p->lchild) + countDegree1(p->rchild); 
    }
    return 0;
}

int Tree::countDegree2(Node *p) // counting all the nodes with the degree 2
{
    if(p)
    {
        if(p->lchild && p->rchild)
            return countDegree2(p->lchild) + countDegree2(p->rchild) + 1;
        return countDegree2(p->lchild) + countDegree2(p->rchild);
    }
    return 0;
}

int Tree::Sum(Node *p) // sum of all the elements of the tree
{
    if(p)
    {
        return p->data + Sum(p->lchild) + Sum(p->rchild);
    }
    return 0;
}

void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}


 
void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}


 
void Tree::iterativePostorder(Node *p) {
    stack<long int> stk;
    long int temp;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace((long int)p);
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}



void Tree::iterativeLevelorder(Node *p)
{
    queue<Node*>qu;
    if(p)
        {
            cout << p->data << ","<<flush;
            qu.emplace(p);
        }
    while(! qu.empty())
    {
        p = qu.front();
        qu.pop();

        if(p->lchild)
        {
            cout << p->lchild->data << ","<<flush;
            qu.emplace(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data << "," << flush;
            qu.emplace(p->rchild);
        }
    }
   cout << endl; 
}
 
int main() {
 
    Tree bt;
 
    bt.CreateTree();
    cout << endl;
 
    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;
 
    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;
 
    cout << "Height: " << bt.Height() << endl;
 
    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();
 
    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();
 
    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();
    
    cout << "IterativeLevelorder: " << flush;
    bt.iterativeLevelorder();
    cout << endl;

    cout << "Number of Nodes in the tree are : " << bt.count() << endl;

    cout << "Number of leaf Nodes in the tree are : " << bt.countLeaves() << endl;
    
    cout << "Number of Nodes with the Degree 1 are : " <<bt.countDegree1() << endl;

    cout << "Number of Nodes with the degree 2 are : " << bt.countDegree2() << endl;

    cout << "Sum of the all the Nodes is : " << bt.Sum() << endl;
    return 0;
}