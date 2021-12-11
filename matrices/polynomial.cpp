#include<iostream>

using namespace std;
 
/*
class term
{
    public :
        int coeff;
        int exp;
};
class poly
{
    private:
    int n;
    term *t;

    public :
    poly(int n)
    {
        this->n = n;
        t = new term[n];
    }
};

int main()
{
    cout << "Enter the no of terms \n";
    int n ;
    cin >> n;
    poly p;
    p(n);
return 0;
}
*/

struct term
{
    int coeff;
    int exp;
};
struct poly
{
    int n;
    struct term *t;
};
void create(struct poly *p)
{
    cout << "Enter the no of terms\n";
    cin >> p->n;
    p->t = (struct term *)malloc(p->n*(sizeof(struct term)));
    cout << "Enter the terms \n";
    for(int i = 0;i < p->n;i++)
    {
        cin >> p->t[i].coeff >> p->t[i].exp;
    }
}
void Display(struct poly p)
{
    int i ;
    for(int i = 0;i < p.n;i++)
    {
        cout << p.t[i].coeff << "x" << p.t[i].exp<<" + ";
    }
    cout << endl;
}
struct poly * add(struct poly p1,struct poly p2)
{
    struct poly *sum;
    sum = (struct poly *)malloc(sizeof(struct poly));
    sum->t = (struct term *)malloc((p1.n + p2.n )*sizeof(struct term));

    int i ,j ,k;
    i = k = j =0;
    while(i < p1.n && j < p2.n)
    {
        if(p1.t[i].exp > p2.t[j].exp)
            sum->t[k++] = p1.t[i++];
        else if(p1.t[i].exp < p2.t[j].exp)
            sum->t[k++] = p1.t[j++];
        else
        {
            sum->t[k].exp = p1.t[i].exp;
            sum->t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }
    for(;i < p1.n ;i++)
        sum->t[k++] = p1.t[i];
    for(;j < p2.n;j++)
        sum->t[k++] = p2.t[j];
    sum->n = k;
    return sum;
}
int main()
{
    struct poly p1,p2,*p3;
    create(&p1);
    Display(p1);
    cout << endl;
    create(&p2);
    Display(p2);
    cout << endl;
    p3 = add(p1,p2);
    cout <<"final polynomial is \n";
    Display(*p3);
    return 0;
}