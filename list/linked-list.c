#include <stdio.h>

/*
 * Linked list
 *
 * - the adress of the head ("first") node gives us access of the complete list
 * - the next adress of the final element must be null
 * - access to elements: O(n)
 * - insertion: O(n)
 *
 */

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    node first, second, third;
    node *pointer = &first; // head node adress must be stored

    first.data = 5;
    first.next = &second;

    second.data = 10;
    second.next = &third;

    third.data = 15;
    third.next = NULL;

    while (pointer != NULL)
    {
        printf("%d -> ", (*pointer).data);
        pointer = (*pointer).next;
    }

    return 0;
}