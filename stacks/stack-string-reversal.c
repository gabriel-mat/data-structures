#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

/*
 *   We can also reverse a linked list using a
 *   <struct node*> stack and Push() the nodes into it.
 *   e.g.:
 * 
 *      node *temp = stack.top();
 *      head = temp;
 *      stack.pop();
 * 
 *      while(!stack.isEmpty())
 *      {
 *          temp -> next = stack.top();        
 *          temp = temp -> next;
 *          stack.pop();
 *      }
 * 
 *      temp -> next = NULL;
 */

struct stack
{
    char data;
    struct stack *link;
};

struct stack *top = NULL;

// functions
int SizeStr(char *str);
void Push(char data);
void Pop();
void ReverseStr(char *str, int size);

int main()
{
    char string[MAX_SIZE + 1];

    printf("\nEnter a string: ");
    scanf("%50[^\n]", string);

    ReverseStr(string, SizeStr(string));

    printf("Reversed: %s\n", string);

    return 0;
}

int SizeStr(char *str)
{
    int size = 0;

    while (*(str + size) != '\0')
        size++;

    return size;
}

void Push(char data)
{
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));

    (*newNode).data = data;
    (*newNode).link = top;

    top = newNode;
}

void Pop()
{
    struct stack *temp;

    if (top == NULL)
    {
        printf("\nempty stack!");
        return;
    }

    temp = top;
    top = top->link;
    free(temp);
}

void ReverseStr(char *str, int size)
{
    for (int i = 0; i < size; i++)
        Push(str[i]);

    for (int i = 0; i < size; i++)
    {
        str[i] = top->data;
        Pop();
    }
}