#include<bits/stdc++.h>

using namespace std;

void Insert(int A[],int n)
{
    int i = n;
    int tmp = A[n];
    while(i > 1 && tmp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = tmp;
}

/* Heap sort - Create a heap of the n elements .
Then delete the elements and the elements are already in a sortedorder.
create heap - log(n)
Delete n elements - n*log(n)
*/
int Delete(int A[],int n)
{
    int x,i,j,val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i*2;
    while(j < n-1)
    {
        if(A[j+1] > A[j])
        {
            j = j+1;
        }
        if(A[i] < A[j])
        {
            swap(A[i],A[j]);
            i = j;
            j = 2*j;
        }
        else
            break;
    }
    return val;
}
int main()
{
    int x[] = {0,10,20,30,25,5,40,35}; // 40,25,35,10,5,20,30
    int i ;

    for(i = 2;i <= 7;i++)
    {
        Insert(x,i);
    }
    for(int i = 7;i >= 1;i--)
        Delete(x,i);


    for( int i = 1;i <= 7;i++)
        cout << x[i] << " ";
    cout << endl;
return 0;
}