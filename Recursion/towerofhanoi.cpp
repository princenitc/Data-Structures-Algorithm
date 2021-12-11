#include<iostream>

using namespace std;
/*  Popular tower of hanoi problem*/
// time complexity of this code will be O(2^n)
// for tracing the time complexity of the problem we can use tree diagram using recursion
void TOH(int n, int a, int b, int c)
{
    if(n > 0)
    {
        TOH(n-1,a,c,b);
        cout << "from " << a << " to " << c << endl;
        TOH(n-1,b,a,c);
    }
}

int main()
{
    TOH(3,1,2,3);
return 0;
}