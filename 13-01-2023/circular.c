#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

struct node *tail = NULL;

void create()
{
    int ch;
    do
    {
        printf("Enter your data : ");
        int m;
        scanf("%d", &m);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = m;
        temp->next = NULL;
        if (tail == NULL)
        {
            tail = temp;
            temp->next = tail;
        }
        else
        {

            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
        }

        printf("Enter a digit for enter more data or enter 0 for exit : ");
        scanf("%d", &ch);
    } while (ch);
}

void display(node *tail)
{
    printf("Your linked list is : ");
    struct node *ptr = tail;
    do
    {
        printf("%d ", ptr->next->data);
        ptr = ptr->next;
    } while (ptr->next != tail->next);
    printf("\n");
}

void insertAtBeg()
{
    printf("Enter the value you want to insert at begining : ");
    int val;
    scanf("%d",&val);
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = val;
    temp->next = NULL;
    if (tail == NULL)
    {
        tail = temp;
        temp->next = tail;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
    }
}

void insertAtEnd()
{
    printf("Enter the value your want to insert at end : ");
    int val;
    scanf("%d",&val);
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = val;
    temp->next = NULL;
    if (tail == NULL)
    {
        tail = temp;
        temp->next = tail;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}

void insertAtAfterNode()
{
    printf("Enter the target for after which you want to insert : ");
    int target;
    scanf("%d", &target);
    int val;
    printf("Enter the value you want to enter : ");
    scanf("%d",&val);
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = val;
    temp->next = NULL;
    if (tail == NULL)
    {
        return;
    }
    else
    {
        struct node *ptr = tail;
        while (ptr->data != target)
            ptr = ptr->next;
        if (ptr != tail)
        {
            temp->next = ptr->next;
            ptr->next = temp;
        }
        else
        {
            temp->next = ptr->next;
            ptr->next = temp;
            tail = temp;
        }
    }
}

void deleteAtBeg()
{
    struct node* temp = tail->next;
    tail->next = tail->next->next;
     temp->next = NULL;
     free(temp);
}

void deleteAtEnd()
{
    struct node* temp = tail;
    while(temp->next != tail) temp = temp->next;
    temp->next = tail->next;
    struct node* temp1 = tail;
    tail =temp;
    temp1->next = NULL;
    free(temp1);
}

void deleteAtmid()
{
    int target;
    printf("Enter the value of target : ");
    scanf("%d",&target);
    struct node *temp = tail;
    while(temp->next->data != target)
    temp = temp->next;
    struct node* temp1 = temp->next;
    temp->next = temp->next->next;
    if(temp1 == tail)
    {
        tail = temp;
    }
    temp1->next = NULL;
    free(temp1);

}

int main()
{
    // struct node* tail= NULL;
    create();
    // printf("tail is : %d ",tail->data);
    display(tail);
    insertAtBeg();
    display(tail);
    insertAtEnd();
    display(tail);
    insertAtAfterNode();
    display(tail);
    deleteAtBeg();
    display(tail);
    deleteAtEnd();
    display(tail);
    deleteAtmid();
    display(tail);

    return 0;
}