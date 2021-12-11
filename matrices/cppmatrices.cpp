#include<iostream>
using namespace std;
 // Creating the diagonal matrix in cpp
class diagonal
{
    private : 
        int n;
        int *A;
    public : 
        diagonal();
        diagonal(int n)
        {
            this->n = n;
            A = new int[n];
        }
        void set(int i, int j,int x);
        int get(int i ,int j);
        void Displaydiagonal();
        ~diagonal(){
            delete [] A;
        }
};
void diagonal:: set(int i, int j, int x)
{
    if(i == j)
    {
        A[i] = x;
    }
}

int diagonal:: get(int i , int j)
{
    if(i == j)
        return A[i];
    else
        return 0;
}

void diagonal:: Displaydiagonal()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0; j< n;j++)
        {
            if(i == j)
                cout << A[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

// Lower trinagular matrix 


int main()
{
    class diagonal m(4);
    m.set(0,0,2);
    m.set(1,1,4);
    m.set(2,2,6);
    m.set(3,3,8);
    cout << m.get(0,3) << endl;
    m.Displaydiagonal();

return 0;
}