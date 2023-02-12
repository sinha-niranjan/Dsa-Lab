// Date:- 06-02-2023  Author:- Niranjan Kumar Q:- implementation of priority queue through array

#include <bits/stdc++.h>
using namespace std;

class Priority_queue
{
    int *arr ;
    int *priority ;
    int size;
    public:
    Priority_queue()
    {
        arr = new int[100];
        priority = new int[100];
        size = -1;
    }
    void push();
    int front();
    int pop();
    void print();
    
};

void Priority_queue::push()
{
    int data ;
    cout<<"enter your data : "; cin>>data;
    cout<<"Enter the priority of data : "; int pr ; cin>>pr;

    if(size <100)
    {
        size++;

        arr[size] = data;
        priority[size]= pr;
    }
}

int Priority_queue::front()
{
    int max_pr = INT_MIN;
    int index = -1;

    for(int i =0;i<=size;i++)
    {
        if(max_pr == priority[i] && index>-1 && arr[index] < arr[i])
        {
            max_pr = priority[i];
            index = i;
        }
        else if(max_pr <priority[i])
        {
            max_pr = priority[i];
            index = i;
        }
    }

    return index;

}

int Priority_queue::  pop()
{
    int item;
    if(size < 100)
    {
        int index = front();
        item = arr[index];
        for(int i =index;i<size;i++)
        {
            arr[i] = arr[i+1];
            priority[i] = priority[i+1];
        }
        size--;
    }

    return item;
}

void Priority_queue:: print()
{
    for(int i =0;i<=size;i++)
    {
        cout<<arr[i]<<" "<<priority[i]<<endl;
    }
    cout<<endl;
}
 
int main()
{
     Priority_queue* pq = new Priority_queue();

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
            pq->push();
            break;
        }
        case 2:
        {
            int val = pq->pop();
            cout << "Your elment " << val << " is deleted." << endl;
            break;
        }

        case 3:
        {
            pq->print();
        }
        }
        cout << "Enter 0 for exit else print another digit : " << endl;
        cin >> ch;
     } while (ch);

   return 0;
}