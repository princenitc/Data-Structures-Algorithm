#include<iostream>
using namespace std;
void _missing(int arr[],int n)
{
   int l = arr[0];
   int h = arr[n-1];
   int diff = l;
   for(int i = 0;i < n;i++)
   {
       if(arr[i]-i != diff)
       {
            while(diff < arr[i]-i)
            {
                cout << diff + i << " ";
                diff++;
            }     
       }
   }
}
void Hash(int arr[],int n,int min ,int max)
{
    int h[min+max] = {0};
    for(int i = 0;i < n;i++)
        h[arr[i]]++;
    for(int i = min;i <=max ;i++ )
        {
            if(h[i] == 0)
                cout << i << " ";
        }
    cout << endl;
}

int main()
{
    int n;
    cout<<"Enter the no of elements in the array\n";
    cin>> n;
    int A[n];
    cout << "Enter the elements : \n";
    for(int i =0;i < n;i++)
        cin >> A[i];
    int mini,maxi;
    cout << "Enter the minimum and maximum values\n";
    cin >> mini >> maxi;
    Hash(A,n,mini,maxi);
return 0;
}