#include<iostream>
using namespace std;

struct array {
    int A[20];
    int length;
    int size;
};

void swap(int *a,int *b)
{
    int temp  = *a;
    *a = *b;
    *b = temp;
}

void Display(struct array arr)
{
    for(int i = 0;i < arr.length ; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void negativesort(struct array *arr) // Moving all the negative elements to the left and +ve to the right
{
    int i = 0;
    int j = arr->length;
    while(i < j)
    {
        while(arr->A[i] < 0)i++;
        while(arr->A[j] >= 0 ) j--;
        if(i < j)
            swap(&arr->A[i],&arr->A[j]);
    }
}
struct array * merge(struct array *arr, struct array *ar)
{
    int i =0;
    int j =0;
    int k =0;
    struct array *C;
    C = new struct array;
    while(i < arr->length && j < ar->length)
    {
    if(arr->A[i] < ar->A[j])
        C->A[k++] = arr->A[i++];
    else
        C->A[k++] = ar->A[j++];
    }
    for(;i < arr->length;i++)
        C->A[k++] = arr->A[i];
    for(; j < ar->length;j++)
        C->A[k++] = ar->A[j];
    C->length = arr->length + ar->length;
    C->size = 30;
return C;
}

struct array * Union(struct array *arr, struct array *ar)
{
    int i =0;
    int j =0;
    int k =0;
    struct array *C;
    C = new struct array;
    while(i < arr->length && j < ar->length)
    {
    if(arr->A[i] < ar->A[j])
        C->A[k++] = arr->A[i++];
    else if(arr->A[i] > ar->A[j])
        C->A[k++] = ar->A[j++];
    else
    {
        C->A[k++] = arr->A[i++];
        j++;
    }
    }
    for(;i < arr->length;i++)
        C->A[k++] = arr->A[i];
    for(; j < ar->length;j++)
        C->A[k++] = ar->A[j];
    C->length = k;
    C->size = 30;
return C;
}


struct array * Difference(struct array *arr, struct array *ar)
{
    int i =0;
    int j =0;
    int k =0;
    struct array *C;
    C = new struct array;
    while(i < arr->length && j < ar->length)
    {
    if(arr->A[i] < ar->A[j])
        C->A[k++] = arr->A[i++];
    else if(arr->A[i] > ar->A[j])
       j++;
    else
    {
        i++;
        j++;
    }
    }
    for(;i < arr->length;i++)
        C->A[k++] = arr->A[i];
    C->length = k;
    C->size = 30;
return C;
}


struct array *Intersection(struct array *arr, struct array *ar)
{
    int i =0;
    int j =0;
    int k =0;
    struct array *C;
    C = new struct array;
    while(i < arr->length && j < ar->length)
    {
    if(arr->A[i] < ar->A[j])
        i++;
    else if(arr->A[i] > ar->A[j])
        j++;
    else if(arr->A[i] == ar->A[j])
    {
        C->A[k++] = arr->A[i++];
        j++;
    }
    }
    C->length = k;
    C->size = 30;
return C;
}

int main()
{
    struct array arr = {{2,6,10,15,25},5,10};  // both the list must be sorted
    struct array ar = {{3,6,7,15,20},5,10};
    struct array *ans;
    ans = Difference(&arr,&ar);
    for(int i = 0;i < ans->length;i++)
        cout << ans->A[i] << " ";
    cout << endl; 
}