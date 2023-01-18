#include <bits/stdc++.h>
using namespace std;

void insertion(int* arr,int n,int index,int elment)
{
    for(int i = n-1; i>=index;i--)
    {
        arr[i+1] = arr[i] ;
    }
    arr[index] = elment;
}

void print(int* arr,int n)
{
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
 
void deletion(int* arr ,int n,int index)
{
    for(int i=index;i<n;i++)
    {
        arr[i] = arr[i+1];
    }
}

int main()
{

    int arr[100];
    int n; cout<<"Enter the number of element in your array : "<<endl;
    cin>>n;
    cout<<"Enter your number : "<<endl;
    for(int i =0;i<n;i++) cin>>arr[i];

    cout<<"Enter the position where you want to insert your element : "<<endl;
    int index; cin>>index;
    cout<<"Enter your elment : "<<endl;
    int elment; cin>>elment;

    print(arr,n);
    cout<<"after insertion :"<<endl;
    n = n+1;
    insertion(arr,n,index,elment);

    print(arr,n);
    cout<<"Enter the index where you want to delete the element : "<<endl;
    int index1 ; cin>>index1;
    cout<<"after deletion :"<<endl;
    deletion(arr,n,index1);
    n = n-1;
    print(arr,n);


   return 0;
}