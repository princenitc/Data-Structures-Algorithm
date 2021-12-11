#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n == 1)
        return 1;
    return factorial(n-1)*n;
}
int iterativeFactorial(int n){
    int f = 1;
    for(int i =1;i <= n;i++)
    {
        f = f*i;
    }
    return f;
}
int main()
{
    int r = 6;
    cout << iterativeFactorial(r);
    return 0;
}