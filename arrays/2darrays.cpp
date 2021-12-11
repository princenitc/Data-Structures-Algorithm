#include<iostream>

using namespace std;

int main()
{
    int a[3][4] = {{1,2,3,1},{2,3,4,99},{24,35,656,56}}; // 2D array  creation using arrays
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    
    int *B[3]; // 2D arrays using pointer
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
     for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
            cout << B[i][j] << " ";
        cout << endl;
    }

    int **c;  // Representation of 2D arrays using double pointers
    c = new int*[3]; // c COde - c = ((int **))malloc(3*sizeof(int*));
    c[0] = new int[4];
    c[1] = new int[4];
    c[2] = new int[4];
     for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}