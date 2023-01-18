#include <iostream>
#define MAXSIZE 10
using namespace std;

void Push();
int Pop();
void Traverse();

int stack[MAXSIZE];
int top = -1;



int main()
{
    int choice;
    char ch;
    do
    {
        cout<<"1 : push "<<endl;
        cout<<"2 : pop "<<endl;
        cout<<"3 : traverse "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            Push();
            break;
            case 2:
            Pop();
            break;
            case 3:
            Traverse();
            break;
            default:
            cout<<"You have entered wrong choice "<<endl;
        }
        cout<<"Do you want to continue (Y/y)";
        cin>>ch;
    } while (ch == 'y' || ch  == 'Y');
    
     
   return 0;
}

void Push()
{
    int item;
    cout<<"Enter the item that you want to enter : ";
    cin>>item;

    if(top == MAXSIZE-1)
    {
        cout<<"The stack is full "<<endl;
        return;
        
    }
    else{
        top = top + 1;
        stack[top] =  item;
    }
}

int Pop()
{
    int item ;
    if(top == -1)
    {
        cout<<"The stack is empty ";
        return -1;
    }
    else
    {
        item = stack[top];
        top = top-1;
        return item;
    }
    return -1;
}

void Traverse()
{
    int i ;
    if(top == -1)
    {
        cout<<"The stack is empty "<<endl;
        return ;
    }
    else{
        cout<<"The traversed elements are : ";
        for(int i = top;i>=0;i--)
        cout<<stack[i]<<" ";

        cout<<endl;
    }
}