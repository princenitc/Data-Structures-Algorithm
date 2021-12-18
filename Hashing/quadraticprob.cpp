#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

// function to do the quadratic hashing in the table
int hashIndex(int key)
{
    return key%SIZE;
}


int quadProb(int H[],int key)
{
    int index = hashIndex(key);
    int i =0;
    while(H[index+i*i]%SIZE != 0)
        i++;
    return (index+i*i)%SIZE;
}

void Insert(int H[],int key)
{
    int index = hashIndex(key);
    if(H[index] != 0)
        index = quadProb(H,key);
    H[index] = key;
}

int Search(int H[],int key)
{
    int index = hashIndex(key);
    int i =0;
    while(H[(index+i*i)%SIZE] != key)
    {  
        if(H[(index+i*i)%SIZE] == 0)
            return -1;
        i++;
    }
    return (i*i+index)%SIZE;
}

int main()
{
    int hashTable[10] = {0};
    
    Insert(hashTable,12);
    Insert(hashTable,25);
    Insert(hashTable,35);
    Insert(hashTable,26);
    Insert(hashTable,15);
    cout << "key is found at "<< Search(hashTable,12) << endl;
    return 0;
}