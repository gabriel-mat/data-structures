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
void DeleteNthPosition(int position);
void ReverseList();

int main()
{
    int num, value, mode, position;

    head = NULL; // empty list

    do
    {
        printf("\n(01) Insert at 1st position.\n(02) Insert at a given position.\n(03) Delete a given position.\n(04) Reverse list.\n(05) Show list\n(06) Finish.\n\nMode: ");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            // Inserting at fisrt position

            printf("Number of elements: ");
            scanf("%d", &num);

            for (int i = 0; i < num; i++)
            {
                printf("\nenter the number: ");
                scanf("%d", &value);
                InsertFirstPosition(value);
                Print();
            }
            break;

            // Inserting at a given position
        case 2:

            printf("Number of elements: ");
            scanf("%d", &num);

            for (int i = 0; i < num; i++)
            {
                printf("\n<value> <position>: ");
                scanf("%d %d", &value, &position);
                InsertNthPosition(value, position);
                Print();
            }
            break;

        case 3:
            printf("Number of elements: ");
            scanf("%d", &num);

            for (int i = 0; i < num; i++)
            {
                printf("<position>: ");
                scanf("%d", &position);
                DeleteNthPosition(position);
                Print();
            }
            break;

        case 4:
            ReverseList();
            Print();
            break;

        case 5:
            Print();
            break;

        case 6:
            break;

        default:
            printf("\n\t== ! invalid ! ==\n");
            break;
        }
    } while (mode != 6);

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

void DeleteNthPosition(int position)
{
    struct node *temp1 = head;
    struct node *temp2 = head;

    // Fix the links
    // Free the memory

    position--; // the 1st position is 0

    if (position == 0)
    {
        head = temp1->next;
        free(temp1);
        return;
    }

    for (int i = 0; i < position - 1; i++)
        temp1 = temp1->next; // access the (position - 1)th node

    temp2 = (temp1->next)->next;

    // ( temp1 ) -> ( node that will be deleted ) -> ( temp2 )

    free(temp1->next);
    temp1->next = temp2; // fixing the links
}

void ReverseList()
{
    struct node *previous, *current, *next;

    previous = NULL;
    current = head;

    while (current != NULL)
    {
        next = (*current).next;
        (*current).next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}