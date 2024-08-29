#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head; // global

void Print();
void InsertFirstPosition(int value);
void InsertNthPosition(int value, int position);

int main()
{
    int num, value, mode, position;

    head = NULL; // empty list

    printf("(01) Insert at 1st position.\n(02) Insert at a given position.\n\nMode: ");
    scanf("%d", &mode);

    printf("Number of elements: ");
    scanf("%d", &num);

    switch (mode)
    {
    case 1:
        // Inserting at fisrt position

        for (int i = 0; i < num; i++)
        {
            printf("\nenter the number: ");
            scanf("%d", &value);
            InsertFirstPosition(value);
            Print();
        }
        break;

    case 2:
        // Inserting at a given position

        for (int i = 0; i < num; i++)
        {
            printf("\n<value> <position>: ");
            scanf("%d %d", &value, &position);
            InsertNthPosition(value, position);
            Print();
        }
        break;

    default:
        printf("! you failed !\n");
        break;
    }

    return 0;
}

void InsertFirstPosition(int value)
{
    // Inserting at beginning

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    (*temp).data = value;
    (*temp).next = head; // the old 1st node will be the 2nd

    head = temp; // the new node is the 1st now
}

void Print()
{
    struct node *temp;

    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp != NULL)
            printf("> ");
    }

    printf("\n");
}

void InsertNthPosition(int value, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    position--; // now the 1st position is 0

    (*newNode).data = value;
    (*newNode).next = NULL;

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int i = 0; i < position - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}