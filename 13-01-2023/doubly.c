#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

struct node* head = NULL;
struct node* tail = NULL;
void create()
{
    int ch;
    do
    {
        printf("Enter the data for node : ");
        int m; scanf("%d",&m);

        struct node* temp = (struct node* )malloc(sizeof(struct node));
        temp->data = m;
        temp->prev = NULL;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;

        }


        printf("Enter a digit for enter next node else enter 0 for exit :  ");
        scanf("%d",&ch);
    } while (ch);
    
}

void display()
{
   // printf("Your linked list : ");
    struct node* ptr = head;
    printf("Your linked list : ");
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertAtBeg()
{
    printf("Enter data for insert at begining : ");
    int data ; 
    scanf("%d",&data);
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtEnd()
{
    printf("Enter the data for insert at end : ");
    int data;
    scanf("%d",&data);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtAfterNode()
{
    printf("Enter the data of node after which you want to insert data  : ");
    int target; scanf("%d",&target);
    printf("Enter the data for insert : ");
    int data; scanf("%d",&data);
    struct node* temp = (struct node* )malloc(sizeof(struct node ));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;


    struct node* ptr = head;
    while(ptr->data != target && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        return ;
    }
    else if(ptr == head)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    // else if(ptr->next == NULL)
    // {
    //     tail->next = temp;
    //     temp->prev = tail;
    //     tail = temp;
    // }
    else
    {
        temp->next = ptr->next;
        temp->next->prev = temp;
        ptr->next = temp;
        temp->prev = ptr;
    }

}

void deleteAtBeg()
{
    printf("After deletion at begining : \n");
    struct node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
}

void deleteAtEnd()
{
    printf("After deletion at end : \n");
    struct node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    free(temp);
}

void deleteNode()
{
    printf("Enter the data for delete node : ");
    int target; scanf("%d",&target);
    struct node* ptr = head;
    if(head ->data == target)
    {
        head = head->next;
        head->prev = NULL;
        ptr->next = NULL;
        free(ptr);
        return;
    }
    while(ptr->next != NULL &&  ptr->next->data != target  )
    {
        ptr = ptr->next;
    }
     
    if(ptr->next->next == NULL && ptr->next->data == target)
    {
        ptr = tail;
        tail = tail->prev;
        tail->next = NULL;
        ptr->prev = NULL;
        free(ptr);
        return;
    }
    else if(ptr->next == NULL ) return;
    else
    {
        struct node* temp = ptr->next;
        ptr->next = ptr->next->next;
        ptr->next->prev = ptr;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }

}

int main()
{
    create();
    display();

    insertAtBeg();
    display();

    insertAtEnd();
    display();

    insertAtAfterNode();
    display();

    deleteAtBeg();
    display();

    deleteAtEnd();
    display();

    deleteNode();
    display();
    
    return 0;
}
// 10 1 20 0 5 30 10 15
