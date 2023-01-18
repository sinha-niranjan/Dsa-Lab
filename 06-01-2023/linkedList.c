#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

struct node* head = NULL;

void create()
{
    int flag ;
    do
    {
        
        int m; 
        struct node* temp = NULL , *ptr = NULL; 
        temp = (struct node*)malloc(sizeof(struct node));
        if(temp == NULL) printf("Memory not allocated successfully \n");
        printf("\nEnter your data for node : ");
        scanf("%d",&m);

        temp->data = m;
        temp->next = NULL;
        if(head == NULL) head = temp;
        else{
            ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }

        printf("if you want to enter another node type any digit and if you want to complete your input enter 0 :  ");
        scanf("%d",&flag);
        
    } while (flag);
    
}

void insertAtBeg()
{
    struct node* temp;
    int m;
    printf("\nEnter your data for insert at begining : ");
    scanf("%d",&m);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = m;
    temp->next = head;
    head = temp;
}

void insertAtMid()

{
    struct node* temp = NULL,*ptr = NULL;
    int m,p;
    printf("\nEnter your data after which you want to insert : ");
    scanf("%d", &p);
    printf("\nEnter your data for insert after %d : ",p);
    scanf("%d",&m);
     
    temp = (struct node* )malloc(sizeof(struct node));
    temp->data = m;
    ptr = head;
    while(ptr->data != p)
    {
        ptr  = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;

}
void deleteAtBeg()
{
    printf("first node is deleted \n");
    struct node* temp = head;
    head = head->next;
    free(temp);
}
void deleteAtMid()
{
    struct node* ptr = NULL,*temp = NULL;
    int p;
    printf("Enter your data whom you want to delete : ");
    scanf("%d",&p);
    ptr = head;
    while(ptr->next->data != p) ptr = ptr->next;
    temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
}
void display()
{
    struct node* ptr = head;
    while(ptr != NULL) 
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverseDisplay(node *head)
{
    if(head == NULL) return;

    reverseDisplay(head->next);
    printf("%d ",head->data);

}

void reverse()
{
    node* prev = NULL;
    node* curr = head;
    node* forw = NULL;
    while(curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    head = prev;
}

int main()
{

    create();
    display();
    insertAtBeg();
    display();
    insertAtMid();
    display();
    deleteAtBeg();
    display();
    deleteAtMid();
    display();
    reverse();
    display();
    reverseDisplay(head);
    printf("\n");
    display();

    return 0;
}