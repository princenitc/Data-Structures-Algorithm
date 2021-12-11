#include<iostream>

using namespace std;
// time complexity of this function is o(2^n)
int fibonacci(int n) // this will be returning the nth  index term in fibaonnaci series array
{
   if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n-2) + fibonacci(n-1);
}


// time complexity of this function is o(n);
int fib(int n) // return the nth term in the fibancci series array;
{
    if(n < 2)
        return n;
    int a = 0, b = 1,s,i;
    for(i = 2;i <= n;i++)
    {
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

// This is the improved version of the fibonacci series using recursion 
// the following array can be created using static or global variavble
// the time complexity of this function is o(n)
// this approch of programming is called as memoization, to use the founded in recursion
static  int arr[100];
int fibonacci_improved(int n)
{
    if(n < 2)
    {
        arr[n]  = n;
        return n;
    } 
    else
    {
        if(arr[n-2] == -1)
            arr[n-2] = fibonacci_improved(n-2);
        if(arr[n-1] == -1)
            arr[n-1] = fibonacci_improved(n-1);
        return arr[n-2] + arr[n-1];
    }
}
int main()
{

    for(int i = 0;i < 100;i++)
        arr[i] = -1;
    cout << "the fibanacci series digit with for loop : " << fibonacci_improved(3);
    return 0;
}