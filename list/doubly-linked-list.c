#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
} node;

node *head = NULL; // global node pointer

// functions
void ShowOptions();
void InsertAtHead(int value);
void Print();
void ReversePrint();

int main()
{
    int opt, qtd, data;

    do
    {
        ShowOptions();
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            break;

        case 1:
            printf("\nhow many nodes? ");
            scanf("%d", &qtd);

            printf("values: ");
            for (int i = 0; i < qtd; i++)
            {
                scanf("%d", &data);
                InsertAtHead(data);
            }
            break;

        case 2:
            Print();
            break;

        case 3:
            ReversePrint();
            break;
        }
    } while (opt != 0);

    return 0;
}

void ShowOptions()
{
    printf("\n(00) - quit\n");
    printf("(01) - insert at head\n");
    printf("(02) - print list\n");
    printf("(03) - reverse print list\n");

    printf("\nselect option: ");
}

void InsertAtHead(int value)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = head;

    if (head != NULL)
        head->previous = newNode;

    head = newNode;
}

void Print()
{
    node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void ReversePrint()
{
    node *temp = head;

    if (head == NULL)
        return;

    // going to last node
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->previous;
    }

    printf("\n");
}