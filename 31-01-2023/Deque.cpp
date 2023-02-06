// Date:- 06-02-2023  Author:- Niranjan Kumar Q:- impementation of Deque through linked list

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Deque{
    Node* front;
    Node* rear;
    Node* size;
    public:
    Deque()
    {
        front = NULL;
        rear = NULL;
        size =0;
    }
    // void freeNode(Node *&head1, int size);
    void push_front();
    void push_back();
    int pop_front();
    int pop_back();
    void traverse();
};

// void Deque:: freeNode(Node *&head1, int size);
void Deque::push_front(){
    int data;
    cout<<"Enter your number to insert in front :"<<endl; cin>>data;
    Node* temp = new Node(data);
    if(front == NULL)
    {
        front = temp;
        rear = temp;
        size++;
    }
    else
    {
        temp->next = front;
        front = temp;
        size++;
    }
}
void Deque::push_back()
{
    int data;
    cout << "Enter your number to insert in back :" << endl;
    cin >> data;
    Node *temp = new Node(data);
    if(temp == NULL)
    {
        cout<<" This is overflow memory is not allocated "<<endl;
        return;
    }
    if (front == NULL)
    {
        front = temp;
        rear = temp;
        size++;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        size++;
    }
}
int Deque::pop_front(){
    int data = -1;
    if(front == NULL)
    {
        cout<<"Queue is under flow "<<endl;
    }
    else{
        Node* temp = front;
        front = front->next;
        data = temp->data;
        temp->next = NULL;
        delete temp;
    }
    return data;
}
int Deque::pop_back(){
    int data = -1;
    if (front == NULL)
    {
        cout << "Queue is under flow " << endl;
    }
    else
    {
        Node* ptr = front;
        while(ptr->next != rear)
        ptr = ptr->next;
        Node *temp = rear;
        rear = ptr;
        ptr->next = NULL;
        data = temp->data;
        delete temp;
    }
    return data;
}

void Deque::traverse()
{
    Node *ptr = front;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    Deque *head = new Deque();
    int choice;
    char ch;
    do
    {
        cout << "1 : push from back " << endl;
        cout << "2 : push from front " << endl;
        cout << "3 : pop from back " << endl;
        cout << "4 : pop from front " << endl;
        cout << "5 : traverse " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            head->push_back();
            break;
        case 2:
            head->push_front();
            break;
        case 3:
            head->pop_back();
            break;
        case 4:
            head->pop_front();
            break;
        case 5:
            head->traverse();
            break;
        default:
            cout << "You have entered wrong choice " << endl;
        }
        cout << "Do you want to continue (Y/y)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}