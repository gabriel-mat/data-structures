#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int queue[ARRAY_SIZE];     // global queue
int front = -1, rear = -1; // empty queue

// functions
void EnQueue(int value);
void DeQueue();
int isEmpty();
int isFull();
int Peek();

int main()
{
    return 0;
}

void EnQueue(int value)
{
    if ((rear + 1) % ARRAY_SIZE == front) // circular array
        return;

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % ARRAY_SIZE;

    queue[rear] = value;
}

void DeQueue()
{
    if (isEmpty())
        return;

    if (front == rear) // the queue will be empty
        front = rear = -1;
    else
        front = (front + 1) % ARRAY_SIZE; // circular array
}

int isEmpty()
{
    if (front == -1 && rear == -1 || front > rear)
        return 1;
    else
        return 0;
}

int Peek()
{
    return (queue[front]);
}