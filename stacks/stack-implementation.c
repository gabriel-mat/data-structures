#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1; // empty stack

// functions
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

void Push(int value)
{
    top++;

    if (top == MAX_SIZE)
    {
        printf("\nstack overflow!\n");
        return;
    }

    stack[top] = value;
}

void Pop()
{
    if (top == -1)
    {
        printf("\nstack is empty!\n");
        return;
    }

    top--;
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

void Print()
{
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);

    printf("\n");
}