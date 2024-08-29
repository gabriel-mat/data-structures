#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *globalHead;

void Print(node *N);
void ReversePrint(node *N);
void ReverseList(node *N);
node *Insert(node *head, int data);

int main()
{
    node *head = NULL;
    int num, value;

    printf("\nnumber of nodes: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("value: ");
        scanf("%d", &value);
        head = Insert(head, value);
    }

    printf("\nPrint: ");
    Print(head);

    printf("\nReversed print: ");
    ReversePrint(head);

    globalHead = head;
    ReverseList(globalHead); // access and modify the global variable

    printf("\n\nPrint (after reversion): ");
    Print(globalHead);

    printf("\nReversed print (after reversion): ");
    ReversePrint(globalHead);

    printf("\n");

    return 0;
}

void Print(node *N)
{
    if (N == NULL)
        return;

    printf("%d", (*N).data);

    if (N->next != NULL)
        printf(" > ");

    Print((*N).next); // recursive call
}

node *Insert(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    node *temp2;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        temp2 = head;

        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        temp2->next = temp;
    }

    return head;
}

void ReversePrint(node *N)
{
    if (N == NULL)
        return;

    ReversePrint((*N).next); // recursive call

    if (N->next != NULL)
        printf(" > ");

    printf("%d", N->data);
}

void ReverseList(node *N)
{
    if (N->next == NULL)
    {
        globalHead = N;
        return;
    }

    ReverseList(N->next);

    node *previous = N->next; // the next node will be the previous
    previous->next = N;
    N->next = NULL;
}