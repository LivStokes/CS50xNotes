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
            return 1; // signifies error
        }
        // (*n).number = get_int("Number: ");// *n goes to the address of the chunk of memory. We want to access the number field so we say *n.number. Because of order of operations, we need to make it clear that we want to go to the adderss first (*n), then go inside that chunk of memory and set the number to wahtever user types.
        //(*n).next = NULL; // changing next field to be some safe value that i know about like NULL.
        n->number = get_int("Number: ");
        n->next = list; // take new node, follow its arrow, and change it to its next field to be whatever the list is currently pointing at.

        list = n; // this connects the list together.
    }
    node *ptr = list; // this creates another variable to point at the start of the list
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; // setting ptr to the next in a while loop.
    }
}

// instead of (*n).number = get_int("Number: ");, we can use n->number = 1;
