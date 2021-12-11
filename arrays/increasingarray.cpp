#include<iostream>

using namespace std;

int main()
{
    int *p ;
    p = new int[5];
    p[0] = 1;
    p[1] = 23;
    p[2] = 454;
    p[3] = 4;
    p[4] = 123;
    int *q ;
    q = new int[10];
    for(int i = 0;i < 5;i++)
        q[i] = p[i];
    delete [] p;  // in c style it can be written as free(p);
    p =q;
    q = NULL;
    for(int i =0;i < 10;i++)
        cout << p[i] << " ";
    cout << endl;
}