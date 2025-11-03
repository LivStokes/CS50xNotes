#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

// creating a linked list
int main(void)
{
    node *list = NULL; // we created pointer of type node * called list and initialize it to NULL because there is no list of numbers yet, so there is no garbage value. This means we have created the pointer at far left.

    for (int i = 0; i < 3; i++)
    { // We want to use malloc to create a node and put a number there, and do it again for another node and put a number in there, and a third time and put a number in there, and then somehow stitch these together.
        node *n = malloc(sizeof(node));  // create pointer called n, send to return value of malloc, where we have enough memory to fit a node. malloc returns address of a chunk of memory. Hence we must assign it to a pointer. This chunk of memory represents a node. We want a memory for a node, not a string.
        if (n == NULL) // memory check
        {
            // TODO free memory already malloc'd
            return 1; // signifies error
        }

        n->number = get_int("Number: ");
        n->next = NULL;

        // If list is empty, do this special case.
        if (list == NULL)
        {
            list = n;
        }
        // if list has numbers already, do this other case.
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) // creates a pointer set to list. Keeps going through loop so long as ptr is not NULL, set ptr = ptr->nxt which moves my list fan to point to the next node.
            {
                // if at end of list
                if (ptr->next == NULL) // if thing im pointing to next is NULL, nothing more to go.
                {
                    ptr->next = n; // change that NULL value to be the address of the new node.
                    break; // break out of the loop because im done.
                }
            }
        }
    }
    for (node *ptr = list; ptr != NuLL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
    return 0;
}
