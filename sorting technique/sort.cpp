#include<bits/stdc++.h>
// Adaptive : if list is already sorted  then it should be getting least time to sort.
// Only Bubble sort and insertion sort are stable.
// Bubble , insertion and merge sort are adaptive.

using namespace std;
/*
Bubble sort : - 
No of passes performed in the algorithm - n-1;
No of comparisons are to be done - (n)*n-1/2;
No of swaps are performed (maximum) - (n-1)*n/2;
time complexity - O(n^2);
if list is sorted - O(n)  - and it is adaptive 
It stable also - as it does not changes the sequence of numbers if they are equal
*/
void bubbleSort(int A[],int n)
{
    for(int i =0;i < n-1;i++)
    {
        int flag = 0;
        for(int j = 0;j < n-1-i;j++)
        {
            if(A[j] > A[j+1])
            {
                swap(A[j],A[j+1]);
                flag = 1;
            }
        }
        if(!flag)return ;
    }
}
/*
Insertion Sort : - 
NO of passes - n-1;
No of comparisons - (n-1)*n/2 ;
NO of swaps is - O(n^2);
Insertion sort in array - O(n^2);
Insertion sort in  the linked list - O(n)
It is stable,adaptive.
Best case for insertion sort - list is sorted in the ascending order
Worst case for insertion sort - list is sorted in the descending order
*/
void insertion(int A[], int n)
{
    int j,x;
    for(int i = 1;i< n;i++)
    {
        j = i-1;
        x = A[i];
        while(j>= 0 && A[j] >x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

/*

Selection sort -: selection of the position in the perticular index.
No of comparisons -: n*(n-1)/2;
No of swaps -: n
In the k passes we gets the k smallest elements - Useful in the intermediate passes
*/
void selection(int A[],int n)
{
    for(int i = 0;i < n;i++)
    {
        int k = i;
        for(int j = i ;j < n;j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        swap(A[i],A[k]);
    }
}
/*
we select a elements as a pivot from the given series.
partitioning method is used in this call.
worst case time complexity - O(n^2)- it is same as that of a sorted list
best case time compolexity of the quick sort is - O(nlog(n))
averge case -  O(n^2)
*/
// if we do the partition from the middle then we may get the worst case in the order of O(n*log(n));
// also called as selection exchange sort and partioning sort
int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;

 do
 {
    do{i++;}while(A[i]<=pivot);
     do{j--;}while(A[j]>pivot);

 if(i<j)swap(A[i],A[j]);
 }while(i<j);

    swap(A[l],A[j]);
     return j;
}
void QuickSort(int A[],int l,int h)
{
    int j;

 if(l<h)
 {
    j=partition(A,l,h);
    QuickSort(A,l,j);
    QuickSort(A,j+1,h);
 }
}

/*
*/

void merge(int A[],int l,int m,int h)// merging the two arrays in a single arrays
{
    int i,j,k;
    i = l;
    j = m+1;
    k =l;
    int C[h+1];
    while(i <= m && j <= h)
    {
        if(A[i] < A[j])
            C[k++] = A[i++];
        else
            C[k++] = A[j++];
    }
    for(;j <= h;j++)
        C[k++] = A[j++];
    for(;i <= m;i++)
        C[k++] = A[i++];
    for(i = l;i <= h;i++)
        A[i] = C[i]; 
}
// No of the passes - log(n)
// time complexity - O(nlog(n))
void IMergeSort(int A[],int n)  // there is some issue with the iterative merge sort function. not running properly.
{
int p,l,h,mid,i;
for(p=2;p<=n;p=p*2)
{
for(i=0;i+p-1<n;i=i+p)
    {
    l=i;
    h=i+p-1;
    mid=(l+h)/2;merge(A,l,mid,h);
    }
    if(n-i>p/2)
    {
    l = i;
    h = i+p-1;
    mid = (l+h)/2;
    merge(A, l, mid, n-1);
    }
}
if(p/2<n)
{
    merge(A,0,p/2-1,n-1);
}
}

void recursiveMergeSort(int A[],int l,int h)
{
    int mid;
    if(l < h)
    {
        mid = (l+h)/2;
        recursiveMergeSort(A,l,mid);
        recursiveMergeSort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}

// time complexity of countsort - o(n)
// but uses a lot of memory
int maxElement(int A[],int n)
{
    int m = INT32_MIN;
    for(int i = 0;i < n;i++)
    {
        m = (A[i] > m) ? A[i] : m;
    }
    return m;
}
void countSort(int A[],int n)
{
    int *C;
    int max = maxElement(A,n);
    C = new int[max+1];
    for(int i = 0;i < max+1 ;i++)
        C[i] = 0;
    for(int i = 0;i < n;i++)
        C[A[i]]++;
    int i =0,j=0;
    while(i < max + 1)
    {
        if(C[i] == 0)
            i++;
        else
        {
            A[j++] = i;
            C[i]--;
        }
    }
}

// Bucket or Bin sort 
/*
time complexity - O(n)
- Huge space is required
*/
struct Node
{
    int data;
    Node *next;
};
void insert(Node **c ,int index)
{
    Node *tmp = new Node;
    tmp->data = index;
    tmp->next = nullptr;
    if(c[index] == nullptr)
        c[index] = tmp;
    else
    {
        Node *p = c[index];
        while(p->next != nullptr)
            p = p->next;
        p->next = tmp;
    }
}
int Delete(Node **c,int index)
{
    Node *p = c[index];
    c[index] = c[index]->next;
    int x = p->data;
    delete p;
    return x;
}
void bucketSort(int A[],int n)
{
    int max = maxElement(A,n);
    Node** C = new Node* [max+1];

    for(int i =0 ;i < max+1; i++)
        C[i] = nullptr;

    for(int i =0;i < n ;i++)  
        insert(C,A[i]);

    int i =0;
    int j =0;  
    while(i < max+1)
    {
        while(C[i] != nullptr)
            A[j++] = Delete(C,i);
        i++;
    }
}

/*radix sort : 
    time complexity - O(n)
*/
// In this the no of time of the calls of the function is increased instead of increasing the memory;

void Display(int A[],int n)
{
    for(int i = 0;i < n;i++)
        cout << A[i] << " ";
    cout << endl;

}
/*Sell sort : -
It is the extended version of the insetion sort with the little bit of modifications 
 of the gap in the  elemetns.
 it is inplace sorting,and it is comparison based.*/
 void shellSort(int A[],int n)
 {
     int gap,i,j,tmp;
     for(gap = n/2;gap >= 1;gap /= 2)
     {
         for(i = gap ;i < n;i++)
         {
            tmp = A[i];
            j = i-gap;
            while(j >= 0 && A[j] > tmp)
            {
                A[j+gap] = A[j];
                j =j-gap;
            }
        A[j+gap] = tmp;
         }
     }
 }
int main()
{
    int A[]= {3,7,9,10,6,5,2,4,11,2};
    int n = 10;
    shellSort(A,n);    
    Display(A,n);
}