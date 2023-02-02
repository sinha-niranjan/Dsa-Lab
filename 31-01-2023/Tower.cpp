// Date:- 31-01-2023  author:- Niranjan Kumar  tower of hanol

#include <bits/stdc++.h>
using namespace std;

void tower(int n,char beg,char aux,char end)
{
    if (n == 1)
    {
         
        cout<<beg<<"-->"<<end;
        return;
    }
    tower(n - 1, beg,end,aux);
     
     cout<<beg<<"-->"<<end<<endl;
    tower(n - 1, aux,beg,end);

     
}

int main()
{

    int n;
    cout << "Enter your number of hanol : ";
    cin >> n;
    char beg = 'a';
    char aux = 'b';
    char end = 'c';
    tower(n, beg,aux,end);

    return 0;
}