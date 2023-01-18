#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int co;
    int pow;
    struct node* next;
}node;



node* create(node* head)
{
    int ch ;
    do 
    {
        int val;
        int power;
        printf("Enter the co efficient  : ");
        scanf("%d",&val);
        printf("Enter power : ");
        scanf("%d",&power);
        node* temp = (node* )malloc(sizeof(node));
        temp->co = val;
        temp->pow = power;
        temp->next = NULL;
        if(head == NULL) head = temp;
        else{
            node* ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        printf("if you want to enter more element in node enter a digit or else 0 for exit : ");
        scanf("%d",&ch);
    }while(ch);

    return head;
}

void display(node* head)
{
    node* ptr = head;
    while(ptr->next!= NULL)
    {
        printf("%dX^%d + ",ptr->co,ptr->pow);
        ptr = ptr->next;
    }
    printf("%dX^%d \n ", ptr->co, ptr->pow);
}

node* add(node* head1,node* head2)
{
    node *ans = NULL;
    node *head = NULL;
    while(head1 != NULL)
    {
         
        if(head1->pow == head2->pow)
        {
            node* temp = (node* )malloc(sizeof(node));
            temp->co = head1->co + head2->co;
            temp->pow = head1->pow;
            temp->next = NULL;
            if(head == NULL)
            {
                ans = temp;
                head = temp;
            }
            else{
                ans->next = temp;
                ans = temp;
            }
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head;
}
int main()
{
node* head1 = NULL;
head1 = create(head1);
display(head1);
node* head2 = NULL;
head2 = create(head2);
display(head2);

node* ans = NULL; 
ans = add(head1,head2);
display(ans);

    return 0;
}