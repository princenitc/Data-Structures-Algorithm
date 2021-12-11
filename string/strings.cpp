#include<iostream>
using namespace std;
int stringLength(char * c)
{
    int i ;
      for(i =0;c[i] != '\0';i++)
    {

    }
    return i;
}
void toUpper(char * c)
{
    int i ;
    for(i =0;c[i] != '\0';i++)
    {
        if(c[i] >= 'a' && c[i] <= 'z')
            c[i] -= 32;
    }
}
void toLower(char * c)
{
    int i ;
    for(i =0;c[i] != '\0';i++)
    {
        if(c[i] >= 'A' && c[i] <= 'Z')
            c[i] += 32;
    }
}

void alternateCase(char * c)
{
    int i ;
    for(i = 0;c[i] != '\0';i++)
    {
        if(c[i] >= 'a' && c[i] <= 'z')
            c[i] -= 32;
        else if(c[i] >= 'A' && c[i] <= 'Z')
            c[i] += 32;      
    }
}
void vowels_print(char * c)
{
    int i ;
    for(i = 0; c[i] !='\0';i++)
    {
        if((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
        {
            if(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u' ||c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U' )
                cout << c[i] << " ";
        }
    }
    cout << endl;
}
void consonants_print(char * c)
{
     int i ;
    for(i = 0; c[i] !='\0';i++)
    {
        if((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
        {
            if(!(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u' ||c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U' ))
                cout << c[i] << " ";
        }
    }
    cout << endl;

}
int count_Words(char * c)
{
    int i,count =0;
    for(i =1;c[i] != '\0';i++)
    {
        if(c[i] == ' ' && c[i-1] != ' ')
            count++;
    }
return count+1;
}

int string_validation(char * c)
{
    int i;
    for(i =0;c[i] != '\0';i++)
    {
        if(!(c[i]>='a' && c[i]<='z') && !(c[i]>='A' && c[i] <='Z') && !(c[i]>='0' && c[i]<='9'))
        return 0;
    }
return 1;
}
void swap_(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void string_reverse(char * c)
{
    int i ,j;
    for(j = 0; c[j] != '\0';j++)
    {

    }
    for(i =0,j = j-1;i<j;i++,j--)
        swap_(&c[i],&c[j]);
}

void comparing_string(char * c,char * d)
{
    int i,j;
    for(i =0,j=0;c[i] != '\0' && d[i] != '\0';i++,j++)
    {
        if(c[i] != d[i])
            break;
    }
    if(c[i] == d[i]) cout << "Equal\n";
    else if(c[i] < d[i]) cout << "A is Smaller\n";
    else cout <<"A is Larger\n";
}
bool pallindrome(char * c)
{
     int i ,j;
    for(j = 0; c[j] != '\0';j++)
    {

    }
    for(i =0,j = j-1;i<j;i++,j--)
        {
            if(c[i] != c[j])
                return false;
        }
    return true;
}

void finding_duplicates(char * c) // only for small case
{
    int i ;
    char H[26]= {0};
    for(i =0;c[i] != '\0';i++)
    {
        H[c[i]-'a']++;
    }
    for(i = 0;i < 26;i++)
    {
        if(H[i] > 1)
        {
            printf("%c %d\n",i+'a',H[i]);
        }
    }

}
int anagram(char *c,char * d)
{
    int H[26]={0};
    int i;
    if(stringLength(c) != stringLength(d))
    {
        cout << "Not an anagram.\n";
        return 0;
    }
    for(i = 0;c[i] != '\0';i++)
        H[c[i]-'a']++;
    for(i = 0; d[i] != '\0';i++)
    {
            H[d[i]-'a']--;
            if(H[d[i]] < 0)
            {
                cout << "Not an anagram.\n";
                return 0;
            }
    }
cout << "It is anagram!\n";
return 1;
}

int main()
{
    char a[] = "prince";
    char surname[] = "ChauHaN";
    cout << stringLength(a)<<endl;
    toUpper(a);
    cout << a << endl;
    toLower(a);
    cout << a << endl;
    alternateCase(surname);
    cout << surname << endl;
    vowels_print(a);
    consonants_print(a);
    char w[] = "this is the sequence of words entered to check the    number of   words";
    cout << count_Words(w) <<endl;
    char first[] = "princ";
    char second[] = "pDiUse";
    cout << string_validation(first) << " " << string_validation(second) << endl;
    string_reverse(a);
    cout << a << endl;
    
    char cpm1[] = "madan";
    char cmp2[]  = "nadam";
    comparing_string(cpm1,cmp2);
    cout << pallindrome(cpm1) << endl;
    finding_duplicates(cmp2);
    char a_ [] = "prince";
    char b_ [] = "ecinpr";
    cout << anagram(a_,b_);
    return 0;
}