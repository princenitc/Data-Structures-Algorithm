#include<bits/stdc++.h>
#define SIZE 10
using namespace std;


int hashIndex(int key)
{
    return key%SIZE;
}


int linProb(int H[],int key)
{
    int index = hashIndex(key);
    int i =0;
    while(H[index+i]%SIZE != 0)
        i++;
    return (index+i)%SIZE;
}

void Insert(int H[],int key)
{
    int index = hashIndex(key);
    if(H[index] != 0)
        index = linProb(H,key);
    H[index] = key;
}

int Search(int H[],int key)
{
    int index = hashIndex(key);
    int i =0;
    while(H[(index+i)%SIZE] != key)
    {  
        if(H[(index+i)%SIZE] == 0)
            return -1;
        i++;
    }
    return (i+index)%SIZE;
}

int main()
{
    int hashTable[10] = {0};
    
    Insert(hashTable,12);
    Insert(hashTable,25);
    Insert(hashTable,35);
    Insert(hashTable,26);
    cout << "key is found at "<< Search(hashTable,35) << endl;
    return 0;
}