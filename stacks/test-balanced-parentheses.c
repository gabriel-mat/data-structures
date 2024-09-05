#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char data;
    struct stack *link;
};

struct stack *top = NULL; // empty stack

// functions
int isOpen(char data);
int isClose(char data);
int rightClose(char data);
void Push(char data);
void Pop();

int main()
{
    char c;

    do
    {
        scanf("%c", &c);

        if (isOpen(c))
        {
            Push(c);
            continue;
        }

        if (isClose(c) && rightClose(c))
        {
            Pop();
            continue;
        }

        if (isOpen(c) || isClose(c))
        {
            printf("\nIs not balanced!\n");
            return 0;
        }

    } while (c != '\n');

    if (top == NULL)
        printf("\nbalanced!\n");
    else
        printf("\nIs not balanced!\n");

    return 0;
}

int isOpen(char data)
{
    if (data == '(' || data == '{' || data == '[')
        return 1;
    else
        return 0;
}

int isClose(char data)
{
    if (data == ')' || data == '}' || data == ']')
        return 1;
    else
        return 0;
}

void Push(char data)
{
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));

    (*newNode).data = data;
    (*newNode).link = top;

    top = newNode;
}

int rightClose(char data)
{
    if (top == NULL)
        return 0;

    if (top->data == '(' && data == ')')
        return 1;

    if (top->data == '{' && data == '}')
        return 1;

    if (top->data == '[' && data == ']')
        return 1;

    return 0;
}

void Pop()
{
    if (top == NULL)
        return;

    struct stack *temp = top;

    top = top->link;

    free(temp);
}