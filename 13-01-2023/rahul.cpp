#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

void insertAtbeg(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtend(Node *&head, Node *&tail, int data)
{

    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtposition(Node *&head, Node *&tail, int pos, int data)
{
    Node *nodetoinsert = new Node(data);
    Node *temp = head;
    if (pos == 1)
    {
        insertAtbeg(head, tail, data);
        return;
    }
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtend(head, tail, data);
        return;
    }
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}
int get_length(Node *&head)
{

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void deleteAtpos(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        cout << "hello" << endl;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete (temp);
    }
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *deletenode = NULL;
    if (temp->next->next == NULL)
    {
        deletenode = temp->next;
        temp->next = NULL;
        deletenode->prev = NULL;
        delete (deletenode);
    }
    deletenode = temp->next;
    temp->next = deletenode->next;
    deletenode->next->prev = temp;
    delete (deletenode);
}
int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtbeg(head, tail, 35);
    print(head);

    insertAtend(head, tail, 87);
    print(head);
    cout << head->data << endl
         << tail->data << endl;

    insertAtposition(head, tail, 4, 9867);
    print(head);
    cout << head->data << endl
         << tail->data << endl;

    cout << get_length(head) << endl;

    deleteAtpos(head, tail, 1);
    print(head);
    // cout<<head->data<<endl<<tail->data<<endl;

    return 0;
}