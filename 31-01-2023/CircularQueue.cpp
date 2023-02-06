// Date:- 06-02-2023  Author:- Niranjan Kumar Q:- implementation of circular queue through array.

#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size1)
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

void CircularQueue::push(int element)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
        arr[front] = element;
    }
    else if (front == (rear+1)%size)
    {
        cout << "Deque is overflow" << endl;
    }
    else
    {
        rear = (rear+1)%size;
        arr[rear] = element;
    }
}

int CircularQueue::pop()
{
    if (front == -1)
    {
        cout << "Deque is underflow " << endl;
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
        front = (front+1)%size;
    }

    return item;
}
void CircularQueue::print()
{
    // for (int i = front; i!=(rear+1)%size; i = (i+1)%size)
    if(front == -1)
    {
        cout<<"Deque is under flow "<<endl;
        return;
    }
    
    int i= front;
    do
    {
        cout << arr[i] << " ";
        i = (i+1)%size;
    }while(i != (rear+1)%size);


    // if(rear != -1)
    // cout<<arr[rear];
    cout << endl;
}
int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;

    CircularQueue q(size);

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
            if(val != -1)
            cout << "Your elment " << val << " is deleted." << endl;
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