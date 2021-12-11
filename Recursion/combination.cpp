#include<iostream>

using namespace std; 
int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return fact(n-1)*n;
}
int nCr(int n,int r) // this is the iterative approach to find the factorial of a number using the simple formula
// nCr = n!/(r!*(n-r)!)
// time complexity of this method is O(n)
{
    int t= fact(n);
    int d1 = fact(r);
    int d2 = fact(n-r);
    return t/(d1*d2);
}

int combination(int n,int r) // this method uses pascals triangle to calculate the combination of nCr.
{
    if(r > n)
        cout << "Error the opration can not be performed on this\n";
    if(r == 0 || r == n )
        return 1;
    return combination(n-1,r)+combination(n-1,r-1);
}
int main()
{

    cout << nCr(4,2);

return 0;

}