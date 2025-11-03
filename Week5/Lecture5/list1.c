#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // If an array is just a sequence of values contiguous in memory, and malloc is just a function that gives you a chunk of contiguous memory, we can use malloc to give us this memory and treat the first part of it as space for an int, second for space for another int, and third for a space for another int.
    if (list == NULL) // If no memory available for list, return NULL.
    {
        return 1; // error, exits program.
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes, need more space to allocate more space for 4th int.
    int *tmp = malloc(4 * sizeof(int)); // reallocate a new array thats a little bigger.
    if (tmp == NULL) // checking that nothing goes wrong.
    {
        free(list); // if no valid return, must free.
        return 1;
    }

    // copy everything from old array into the new array.
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i]; // put into the tmp array at location i, what ever is in the original array at location i. Similar to string copy.
    }
    // if i want to add a 4th number to this array:
    tmp[3] = 4;

    free(list); // free malloc of original array.

    list = tmp; // keep new chunk of memory. this renames new chunk of memory.

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Time passes
    free(list); // free the new list.
    return 0;
}
