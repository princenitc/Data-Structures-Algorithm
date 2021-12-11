#include<iostream>

using namespace std;

struct array
{
    int A[20]; // You need to make it a pointer if using heap
    int size;
    int length;
};

void append(struct array *arr,int x) // Appending the elements at last
{
   if(arr->length < arr->size)
   {
        arr->A[arr->length] = x;
        arr->length++;
   }
   else
    cout << "size Overflow !\n";
}

void insert(struct array *arr,int index,int num) // inserting an element at a perticular position in array
{
  if(index >= 0 && index <= arr->length)
  {
      for(int i =arr->length;i >index;i--)
      {
          arr->A[i] = arr->A[i-1];
      }
      arr->A[index] = num;
      arr->length++;
  }
}

int Delete(struct array *arr,int index)
{
    int x = 0;
if( index >= 0 && index < arr->length)
{
    x = arr->A[index];
    for(int i = index;i < arr->length;i++)
        arr->A[i] = arr->A[i+1];
    arr->length--;
    return x;
}
return 0;
}

int search(struct array *arr,int key) // Best case is O(1), Worst Case O(n),Average Case O(n)
{
    for(int i =0;i < arr->length;i++)
    {
        if(arr->A[i] == key)
            {
                int temporary = arr->A[i];
                arr->A[i] = arr->A[i-1];
                arr->A[i-1] = temporary;
                return i-1;
            }
    }
    return -1;
}
/*
The following are the improved linear search method which can be used to improve linear searching with increased number of seached
Transposition  : - if the key element is found then it will be swapped with the previous value.
                    i.e. swap(A[i],a[i-1]) and then return i-1.
Move to front/head : - if the searched elements is found then swap it with the first element.
                        i.e. swap(A[i],A[0]) and then return 0;
*/

int binarySearch(struct array arr,int key,int l,int h) // Much more efficient -worst case - O(ceil(log(n))),best case - O(1)
{
    if(l <= h)   // Average Case for Binary search will be - O(log(n))
    {
    int m = (l+h)/2;
    if(key < arr.A[m])
        return binarySearch(arr,key,l,m-1);
    if(key == arr.A[m])
        return m;
    if(key > arr.A[m])
        return binarySearch(arr,key,m+1,h);
    }
return -1;
}
int binarySearchIterative(struct array arr,int key,int l ,int h)
{
    while(l <= h)
    {
        int mid = (l+h)/2;
        if(arr.A[mid] == key)
            return mid;
        else if(key < arr.A[mid])
            h = mid-1;
        else if(key > arr.A[mid])
            l = mid + 1;
    }
return -1;
}

int get(struct array arr,int index) // time Complexity is - O(1)
{
    if(index >= 0 && index < arr.length)
        return arr.A[index];
return 0;
}

void set(struct array *arr,int index ,int x) // time complexity is - O(1)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int max(struct array arr) // Always will be the O(n) for an unsorted array and O(1) for sorted array
{
    int max = arr.A[0];
    for(int i = 1;i < arr.length;i++)
    {
        if(max < arr.A[i])
            max = arr.A[i];
    }
return max;
}

int min(struct array arr) // Always will be the O(n) for an unsorted array and O(1) for sorted array
{
    int min = arr.A[0];
    for(int i = 1;i < arr.length;i++)
    {
        if(min > arr.A[i])
            min = arr.A[i];
    }
return min;
}

int sum(struct array arr) // Always will be the O(n) 
{
    int total = 0;
    for(int i = 0;i < arr.length;i++)
    {
            total += arr.A[i];
    }
return total;
}

float average(struct array arr) // time Complexity will be O(n)
{
    return sum(arr)/(float)arr.length;
}
void Display(struct array arr)
{
    int i;
    cout << "Array elements are\n";
    for(int i =0;i < arr.length;i++)
        cout << arr.A[i] << " ";
    cout << endl;
}
/* There are two methods to reverse the arrays i.e. auxilary method : in this we create a compy of array and transfer the array elements from back and and then again copy from the duplicate array to original array*/
// Auxilary method is not much prefered due to extra space and O(n) time complexity

void reverse(struct array *arr)
{
    for(int i = 0 ;i <= arr->length/2;i++)
    {
        int cpelement = arr->A[i];
         arr->A[i] = arr->A[(arr->length-1-i)];
         arr->A[(arr->length-1-i)] = cpelement;
    }
}

void leftShift(struct array *arr,int index)
{
    for(int i = index;i < arr->length;i++)
        arr->A[i-1] = arr->A[i];
}



int main()
{
     int position,key;
    struct array arr = {{2,3,4,5,6},10,5};
    /*int n,i;
    cout << "Enter the size of array\n";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    cout << "Enter number of Numbers \n";
    cin >> n;
    arr.length = n;
    cout << "Enter the elements\n";
    for(int i = 0;i < n;i++)
    {
        cin >> arr.A[i];
    } 
    // The above section of code can be used to take the input from the user using heap
    cout << "Enter the number to be added at last\n";
    int append_last ;
    cin >> append_last;
    append(&arr,append_last);
    Display(arr);
    cout << "Enter the position at which the number is to be inserted\n";
    cout << "Enter the position\n";
    cin >> position;
    cout << "Enter the key\n";
    cin >> key;
    insert(&arr,position,key);
    Display(arr);
    cout << "Enter the index to deleted\n";
    cin >> position;
    key = Delete(&arr,position);
    cout << key << " is deleted.\n"; 
    Display(arr);
    cout << "Enter the number\n";
    cin >> key;
    position = binarySearchIterative(arr,key,0,5);
    (position != -1) ? cout << "Found!\n" : cout << "Not found!\n";
    cout << "enter the index to be found\n";
    cin >> position;
    cout << get(arr,position) <<endl;
    cout << "enter the index and no to be replaced\n";
    cin >> position >> key;
    set(&arr,position,key);
    Display(arr);
    cout <<"The sum of array is : " << sum(arr) << endl;
    cout << "The maximum of array is " << max(arr) << endl;
    cout << "The minimum of array is " << min(arr) << endl;
    cout << "Average of the array is " << average(arr)<<endl;*/
    Display(arr);
    reverse(&arr);
    Display(arr);
    return 0;
}