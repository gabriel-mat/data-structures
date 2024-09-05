#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

enum options
{
    quit,
    enqueue,
    dequeue,
    print
};

struct node *front = NULL;
struct node *rear = NULL; // necessary to get O(1)

// functions
void Enqueue(int value);
void Dequeue();
void ShowOptions();
void PrintQueue();

int main()
{
    int data;
    enum options op;

    do
    {
        ShowOptions();
        scanf("%d", &op);

        switch (op)
        {
        case quit:
            break;

        case enqueue:
            printf("\ninsert value: ");
            scanf("%d", &data);

            Enqueue(data);
            break;

        case dequeue:
            Dequeue();
            break;

        case print:
            PrintQueue();
            break;

        default:
            printf("invalid!\n");
            break;
        }
    } while (op != quit);

    return 0;
}

void Enqueue(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) // empty queue
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void Dequeue()
{
    struct node *temp = front;
    if (front == NULL) // empty queue
        return;

    if (front == rear) // the queue will be empty
        front = rear = NULL;
    else
        front = front->next;

    free(temp);
}

void ShowOptions()
{
    printf("\n");
    printf("(00) - quit\n");
    printf("(01) - enqueue\n");
    printf("(02) - dequeue\n");
    printf("(03) - print queue\n");
    printf("select option: ");
}

void PrintQueue()
{
    struct node *temp = front;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}