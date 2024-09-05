#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct stack
{
    char data;
    struct stack *link;
} stack;

stack *top = NULL; // empty stack

// functions
void Push(char value);
void Pop();
int StrSize(char *str);
int isBalanced(char *str);
int isRightPair(char c);

int main()
{
    char str[MAX_SIZE + 1];
    scanf("%100[^\n]", str);

    if (isBalanced(str))
        printf("balanced!\n");
    else
        printf("not balanced :(\n");

    return 0;
}

void Push(char value)
{
    stack *newNode = (stack *)malloc(sizeof(stack));

    newNode->data = value;
    newNode->link = top;

    top = newNode;
}

void Pop()
{
    if (top == NULL)
        return;

    stack *temp;

    temp = top;
    top = top->link;

    free(temp);
}

int StrSize(char *str)
{
    int length = 0;

    while (*(str + length) != '\0')
        length++;

    return length;
}

int isBalanced(char *str)
{
    int size;

    size = StrSize(str);

    for (int i = 0; i < size; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            Push(str[i]);
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (!isRightPair(str[i]))
                return 0;
            else
                Pop();
        }
    }

    return top == NULL ? 1 : 0;
}

int isRightPair(char c)
{
    if (top == NULL)
        return 0;

    if (top->data == '(' && c == ')')
        return 1;

    if (top->data == '{' && c == '}')
        return 1;

    if (top->data == '[' && c == ']')
        return 1;

    return 0;
}