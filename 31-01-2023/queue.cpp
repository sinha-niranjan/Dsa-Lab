// Date:- 31-01-2023  author :- Niranjan kumar
// queue implementation through array

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int size1)
    {
        size = size1;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int element);
    int pop();
    void print();
};

void Queue::push(int element)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
        arr[front] = element;
    }
    else if (rear == size - 1)
    {
        cout << "stack is overflow" << endl;
    }
    else
    {
        rear++;
        arr[rear] = element;
    }
}

int Queue::pop()
{
    if (front == -1)
    {
        cout << "stack is underflow " << endl;
        return -1;
    }

    int item = arr[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    return item;
}

void Queue::print()
{
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;

    Queue q(size);

    int ch;
    do
    {
        int choose;
        cout << "Enter 1 for push , 2 for pop , 3 for print : ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            cout << "enter your element : " << endl;
            int data;
            cin >> data;
            q.push(data);
            break;
        }
        case 2:
        {
            int val = q.pop();
            cout << "Your elment " << val << "is deleted." << endl;
            break;
        }

        case 3:
        {
            q.print();
        }
        }
        cout << "Enter 0 for exit else print another digit : " << endl;
        cin >> ch;
    } while (ch);

    return 0;
}