#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head; // global

void Print();
void InsertValue(int value);

int main()
{
    int num, value;

    head = NULL; // empty list

    printf("How many elements?\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("\nenter the number: ");
        scanf("%d", &value);
        InsertValue(value);
    }

    Print();

    return 0;
}

void InsertValue(int value)
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
}