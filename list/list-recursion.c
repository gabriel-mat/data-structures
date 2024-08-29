#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void Print(node *N);
void ReversePrint(node *N);
node *ReverseList(node *N);
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

    head = ReverseList(head); // access and modify the head node

    printf("\n\nPrint (after reversion): ");
    Print(head);

    printf("\nReversed print (after reversion): ");
    ReversePrint(head);

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

node *ReverseList(node *N)
{
    if (N->next == NULL || N == NULL)
        return N;

    node *newHead = ReverseList(N->next);

    node *n = N->next;
    n->next = N;
    N->next = NULL;

    return newHead;
}