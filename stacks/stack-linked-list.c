#include <stdio.h>
#include <stdlib.h>

// the "top" must be the beginning of the list ( O(1) functions )

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL; // empty stack

// funtions
void ShowOptions();
void Push(int value);
void Pop();
void Print();

int main()
{
    int opt = 1, data;

    while (opt != 0)
    {
        ShowOptions();
        scanf("%d", &opt);

        switch (opt)
        {
        case 0: // quit
            break;

        case 1: // push
            printf("insert value: ");
            scanf("%d", &data);

            Push(data);
            break;

        case 2: // pop
            Pop();
            break;

        case 3: // print stack
            Print();
            break;
        }
    }

    return 0;
}

void ShowOptions()
{
    printf("\n");
    printf("(00) - quit\n");
    printf("(01) - push\n");
    printf("(02) - pop\n");
    printf("(03) - print stack\n");
    printf("\n");

    printf("select option: ");
}

void Push(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->link = top;

    top = newNode;
}

void Pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("\nempty stack!\n");
        return;
    }

    temp = top;
    top = top->link;

    free(temp);
}

void Print()
{
    struct node *temp = top;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");
}