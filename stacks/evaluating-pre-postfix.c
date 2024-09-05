#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack
{
    float data;
    struct stack *link;
};

enum options
{
    prefix,
    postfix
};

struct stack *top = NULL; // empty stack

// functions
void Pop();
void Push(float value);
int isOperand(char c);
int isOperator(char c);
int StrLen(char *str);
float EvaluatePostfix(char *str);
float EvaluatePrefix(char *str);
float Calc(char operator, int n1, int n2);

int main()
{
    enum options op;
    char string[MAX_SIZE + 1];

    printf("Enter the expression: ");
    scanf("%100[^\n]", string);

    printf("\n(00) Prefix\n(01) Postfix\nChoose an option: ");
    scanf("%d", &op);

    switch (op)
    {
    case prefix:
        printf("\nresult: %.2f\n", EvaluatePrefix(string));
        break;

    case postfix:
        printf("\nresult: %.2f\n", EvaluatePostfix(string));
        break;

    default:
        printf("\n== invalid ==\n");
        break;
    }
    return 0;
}

void Push(float value)
{
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));

    newNode->data = value;
    newNode->link = top;

    top = newNode;
}

void Pop()
{
    if (top == NULL)
        return;

    struct stack *temp;

    temp = top;
    top = top->link;

    free(temp);
}

int StrLen(char *str)
{
    int len = 0;

    while (*(str + len) != '\0')
        len++;

    return len;
}

int isOperand(char c)
{
    if (c >= '1' && c <= '9')
        return 1;
    else
        return 0;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}

float EvaluatePostfix(char *str)
{
    int size;
    int op1, op2;
    float result;

    size = StrLen(str);

    for (int i = 0; i < size; i++)
    {
        if (isOperand(str[i]))
            Push(str[i] - '0');
        else if (isOperator(str[i]))
        {
            op2 = top->data;
            Pop();
            op1 = top->data;
            Pop();

            result = Calc(str[i], op1, op2);
            Push(result);
        }
    }

    return top->data;
}

float Calc(char operator, int n1, int n2)
{
    switch (operator)
    {
    case '+':
        return n1 + n2;

    case '-':
        return n1 - n2;

    case '*':
        return n1 * n2;

    case '/':
        if (n2 == 0)
            printf("Error!\n");
        else
            return (float)n1 / n2;
    }
}

float EvaluatePrefix(char *str)
{
    int size, num1, num2;
    float result;

    size = StrLen(str);

    for (int i = size - 1; i >= 0; i--)
    {
        if (isOperand(str[i]))
            Push(str[i] - '0');
        else if (isOperator(str[i]))
        {
            num1 = top->data;
            Pop();

            num2 = top->data;
            Pop();

            result = Calc(str[i], num1, num2);
            Push(result);
        }
    }

    return top->data;
}