#include<iostream>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sum(n-1)+n;
}
int main()
{
    cout  << "Sum of the 22 Using recursion is : "<< sum(22) << endl;
}