#include<iostream>

using namespace std ;

int main()
{
    int A[4] = {1,2,3,4};
    int *p;
    p = new int[6]; // cpp style
    // for c style we can write it as p = (int *)malloc(5*sizeof(int))
    p[0] = 3;
    p[1] = 3;
    p[2] = 432;
    p[3] = 65;
    p[4] = 242;
    p[5] = 356;
    for(int i = 0;i < 4;i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    for(int i =0;i < 6;i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
return 0;
}