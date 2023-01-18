#include<stdio.h>

void insertion(int *arr, int n, int index, int elment)
{
    for (int i = n - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = elment;
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void deletion(int *arr, int n, int index)
{
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100];
    int n;
    int index;
    printf("Enter the number of element in your array : ");
    scanf("%d",&n);
    printf("Enter your number : " );
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    printf( "Enter the position where you want to insert your element : " );
     
    scanf("%d",&index);
    printf("Enter your elment : ");
    int elment;
    scanf("%d",&elment);

    print(arr, n);
    printf("after insertion :");
    n = n + 1;
    insertion(arr, n, index, elment);

    print(arr, n);
    printf("Enter the index where you want to delete the element : ");
    int index1;
    scanf("%d",&index1);
    printf("after deletion :");
    deletion(arr, n, index1);
    n = n - 1;
    print(arr, n);

    return 0;
}