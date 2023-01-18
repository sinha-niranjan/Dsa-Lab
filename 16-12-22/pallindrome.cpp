#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{

    int n; 
    cout<<"Enter your number : ";
    cin>>n;
    int temp = n;
    int reverse =0;
    while(temp != 0)
    {
        int digit = temp%10;
        temp = temp/10;

        reverse =reverse*10 + digit;

    }
    if(n == reverse )
    {
        cout<<"Your entered number is palindrome. "<<endl;
    }
    else 
    {
        cout<<"Your entered number is not pallindrome."<<endl;
    }
   return 0;
}