#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

int hashOne(int key)
{
    return key%SIZE;
}

int hashTwo(int key)
{
    return SIZE - (key % SIZE);
}

void Insert(int H[],int key)
{
    int index = hashOne(key);
    int i = 0;
    while(H[(index+i*hashTwo(key))%SIZE] != 0)
        i++;
    H[(index+i*hashTwo(key))%SIZE] = key;    
}

int main()
{
    int H[10] =  {0};
    Insert(H,5);
    Insert(H,25);
    Insert(H,15);
    Insert(H,35);
    Insert(H,95);
return 0;
}