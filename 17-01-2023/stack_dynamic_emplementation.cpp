#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

void freeNode(Node* &head1,int size);
void push(Node* &top,Node* &head1);
void pop(Node* &top,Node* &head1);

void freeNode(Node* &head1,int size)
{
    while(size--)
    {
        Node *temp = new Node(0);
        if(head1 == NULL)
        {
             
            head1 = temp;
            head1->next = NULL;
        }
        else
        {
            temp->next = head1;
            head1 = temp;
        }
        
    }
}
void push(Node* &top,Node* &head1)
{
    if(head1 == NULL)
    {
        cout<<"Stack is full "<<endl;
        return;
    }
    else{
        int item ; 
        cout<<"Enter the item that you want to enter : "<<endl;
        cin>>item;
        Node* ptr = head1 ;
        head1 = head1->next;
        ptr->data = item;
        if(top == NULL)
        {
            ptr->next = NULL;
            top = ptr;
            
        }
        else
        {
            ptr->next = top;
            top = ptr;
        }
    }
}

void pop(Node* &top,Node* &head1)
{
    if(top == NULL)
    {
        cout<<"stack is empty. "<<endl;
        return ;
    }
    else if(head1 == NULL)
    {
        Node* ptr = top;
        top = top->next;
        ptr ->next == NULL;
        head1 = ptr;
    }
    else
    {
        Node* ptr = top ;
        top = top->next;
        ptr->next = head1;
        head1 = head1->next;
        head1 = ptr;
    }
}

void traverse(Node* top)
{
    Node* ptr = top;
    while(ptr != NULL) 
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main()
{
    int n; 
    cout<<"Enter the number of free node : ";
    cin>>n;
    Node* head1 = NULL;
    freeNode(head1,n);

    Node* top = NULL;

    int choice;
    char ch;
    do
    {
        cout << "1 : push " << endl;
        cout << "2 : pop " << endl;
        cout << "3 : traverse " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push(top,head1);
            break;
        case 2:
           pop(top,head1);
            break;
        case 3:
            traverse(top);
            break;
        default:
            cout << "You have entered wrong choice " << endl;
        }
        cout << "Do you want to continue (Y/y)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

   return 0;
}