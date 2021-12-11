#include<iostream>

using namespace std;

int power(int m, int n) // Most easy approach to go with the program
{
    if(n == 0)
        return 1;
    return power(m,n-1)*m;
}
int newPower(int m,int n) // More efficint than the other one as it involves less no of multiplication hence less time
{
    if(n == 0)
        return 1;
    if(n%2 == 0)
    {
        return newPower(m*m,n/2);
    }
    else
    {
        return m*newPower(m*m,(n-1)/2);
    }
}
int main()
{
    int b = 3, p = 5;
    cout << newPower(b,p) ;
    return 0;
}