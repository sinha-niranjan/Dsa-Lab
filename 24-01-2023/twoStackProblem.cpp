#include <bits/stdc++.h>
using namespace std;

class Stack
{

    int top1;
    int top2;
    int size;
    int count;
    int *arr;

public:
    Stack()
    {
        cout << "Enter the size of total array : " << endl;
        cin >> size;

        arr = new int[size];
        top1 = -1;
        top2 = size;
        count = size;
    }
    void push()
    {
        int ch;
        do
        {
            int flag ;
            cout<<"if you want to push in stack 2 so enter 2 else enter 1 for stack 1 : "<<endl;
            cin>>flag;
        if(flag == 1)
        {
            if (count == 0)
            {
                cout << "stack is overflow " << endl;
            }
            else
            {
                int data;
                cout << "enter your data to insert in first stack : " << endl;
                cin >> data;
                top1++;
                arr[top1] = data;
                count--;
            }
        }

        else if(flag == 2)
        {
            if (count == 0)
            {
                cout << "stack is overflow " << endl;
            }
            else
            {
                int data;
                cout << "enter your data to insert in second stack : " << endl;
                cin >> data;
                top2--;
                arr[top2] = data;
                count--;
            }
        }

        cout<<"Enter 0 for exit : ";
        cin>>ch;
        } while (ch);
    }
     

     int pop()
     {
        int flag;
        cout << "if you want to pop in stack 2 so enter 2 else enter 1 for stack 1 : " << endl;
        cin >> flag;
        if(flag == 1)
        {
            if(top1 == -1 || count == size)
            {
                cout<<"stack is under flow "<<endl;
                return -1;
            }
            else{
                int item = arr[top1];
                top1--;
                count++;
                return item;
            }
        }
        else if(flag == 2)
        {
            if (top2 == size || count == size)
            {
                cout << "stack is under flow " << endl;
                return -1;
            }
            else
            {
                int item = arr[top2];
                top2++;
                count++;
                return item;
            }
        }
        return -1;
     }

    void display()
    {
        cout << "first part of stack is : ";
        for (int i = top1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
        cout << "second part of stack is : ";
        for (int i = top2; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main()
{
    Stack* st = new Stack();
    int ch;
      do
      {
        cout<<"Enter 1 for again push or pop : "<<endl;
        cin>>ch;
        st->push();
        st->display();
        st->pop();
        st->display();
      } while (ch);
      

    return 0;
}