// Date :- 30-01-2023  author :- Niranjan Kumar writing a code for qucik sort

#include <bits/stdc++.h>
using namespace std;

int sort(int beg, int end, int arr[])
{
    int left = beg;
    int right = end;
    int loc = beg;

    // right to  left
    while (true)
    {
        while (arr[loc] <= arr[right] && loc != right)
            right = right - 1;

        if (loc == right)
            return loc;

        if (arr[loc] > arr[right])
        {
            swap(arr[loc], arr[right]);
            loc = right;
        }

        // left to right

        while (arr[loc] >= arr[left] && left != loc)
        {
            left = left + 1;
        }
        if (loc == left)
            return loc;

        if (arr[loc] < arr[left])
        {
            swap(arr[loc], arr[left]);
            loc = left;
        }
    }
    return -1;
}

void print(int arr[], int n)
{
    cout << "Your array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter the size of array : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the element of array : " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "befor soting ";
    print(arr, n);

    stack<int> lower;
    stack<int> upper;  
    lower.push(0);
    upper.push(n - 1);

    while (!lower.empty())
    {
        int beg = lower.top();
        lower.pop();
        int end = upper.top();
        upper.pop();
        int loc = sort(beg, end, arr);
        if (loc - 1 - beg >= 2)
        {
            lower.push(beg);
            upper.push(loc - 1);
        }
        if (end - loc + 1 >= 2)
        {
            lower.push(loc + 1);
            upper.push(end);
        }
        
    }
    cout << "after sorting ";
    print(arr, n);

    return 0;
}
// 12 44 33 11 55 77 90 40 60 99 22 88 66 