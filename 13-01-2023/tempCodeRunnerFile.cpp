#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // comstuctor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
void insertAthead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
void insertAtposition(Node *&head,Node* &tail, int pos, int data)
{
    Node *insertnode = new Node(data);
    Node *temp = head;
    int count = 1;
    if (pos == 1)
    {
        insertAthead(head, data);
        return;
    }
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, data);
        //   cout<<"ji"<<endl;
        return;
    }
    insertnode->next = temp->next;
    temp->next = insertnode;
}
void deleteAtposition(Node *&head, int pos)
{
    int count = 1;
    Node *temp = head;
    if (pos == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete (temp);
    }
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *to_delete = temp->next;
    temp->next = to_delete->next;
    to_delete->next = NULL;
    delete (to_delete);
}
int main()
{

    Node *Node1 = new Node(10);
    Node *head = Node1;
    Node *tail = Node1;
    Node1->next = NULL;
    print(head);
    cout << tail->data << endl;

    insertAthead(head, 23);
    print(head);
    cout << tail->data << endl;

    insertAttail(tail, 57);
    print(head);
    cout << tail->data << endl;

    insertAtposition(head,tail, 4, 65);
    print(head);
    cout << head->data << endl
         << tail->data << endl;

    //  deleteAtposition(head,3);
    //  print(head);
    //   cout<<head->data<<endl<<tail->data<<endl;

    return 0;
}