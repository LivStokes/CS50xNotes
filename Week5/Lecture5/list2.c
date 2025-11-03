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
    int *tmp = realloc(list, 4 * sizeof(int)); // instead or allocating new array of size 4, we can realloc to reallocate for me. If there is more memory back to back, it will give more memory to the right of that memory instead of a whole new memory.
    // In order for realloc to work, we need to tell it the address of the original chunk of memory.
    // Malloc takes two arguments, realloc takes 2, the first being the address.
    if (tmp == NULL) // checking that nothing goes wrong.
    {
        free(list); // if no valid return, must free.
        return 1;
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
