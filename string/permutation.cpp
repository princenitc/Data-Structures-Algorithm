#include<iostream>

using namespace std;

void swap(char *c,char *d)
{
    char tmp = *c;
    *c = *d;
    *d = tmp;
}
void permutation(char s[],int k ) // Normal method to find the permutaion of a string
{
static int A[10] = {0};
static char res[10];
int i ;
if(s[k] == '\0')
{
    res[k] = '\0';
    cout << res << endl;
}
else
{
    for(i = 0; s[i] != '\0';i++)
    {
        if(A[i] == 0)
        {
            res[k]  = s[i];
            A[i] = 1;
            permutation(s,k+1);
            A[i] = 0;      
        }
    }
}

}

void permutate(char * s, int l, int h) //  More simplified version of the code
{
    int i ;
    if(l == h)
        cout << s << endl;
    else
    {
        for(i = l; s[i] != '\0';i++)
        {
            swap(s[l],s[i]);
            permutate(s,l+1,h);
            swap(s[l],s[i]);
        }
    }    
}

int main()
{
    char num []= "abc";
    permutation(num,0);
    char name[] = "prin";
    permutate(name,0,3);
    return 0;
}