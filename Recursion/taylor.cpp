#include<iostream>

using namespace std;

double taylor(double x,double a) // Normal approach of the taylors series
{                                   // time complexity for this function will be o(n^2) 
    static double p = 1, f= 1;
    double r;
    if(a == 0)
        return 1;
    else
    {
        r = taylor(x,a-1);
        p = p *x;
        f = f*a;
        return r + p/f;
    }
}
double hornerTaylor(double x, double a) // This approach uses the o(n) as we take comman terms from the expression
                                        // using for loop 
{
    double res = 1;
    for(double i = a;i > 0;i--)
    {
        res = 1 + (x/i)*res;
    }
    return res;
}
double hornerRecursive(int x, int a) // o(n) using the recursion 
{
    static double s = 1;
    if(a == 0)
        return s;
    //s = 1 + x*s/a;  --- > here we need to type cast the division  or else we can do this with this method; 
    s = 1+x/(double)a * s;
    return hornerRecursive(x,a-1);
}

int main()
{
    cout << hornerRecursive(1,10) << " " << hornerTaylor(1,10) ;
    return 0;

}