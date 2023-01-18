#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{

    int n; cout<<"Enter the size of array : ";
    cin>>n;

    int* arr = new int[n];
    cout<<"Enter your array : ";
    for(int i =0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);
    int count =0;
    for(int i =0;i<n;i++)
    {
        if(arr[n-1] == arr[i]) count++;
    }
    cout<<arr[n-1-count]<<" : is your second largest number in your aray."<<endl;

   return 0;
}