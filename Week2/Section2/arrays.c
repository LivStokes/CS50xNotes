#include <stdio.h>

// EXAMPLE FOUR TO GET RID OF MAGIC NUMBERS
int const size = 5;

int main(void)
{
    // Declare an array
    int numbers[size];

    // Populate an array
    // EXAMPLE ONE
    // numbers[0] = 1;
    // numbers[1] = numbers[0] * 2;
    // numbers[2] = numbers[1] * 2;
    // numbers[3] = numbers[2] * 2;
    // numbers[4] = numbers[3] * 2;

    // EXAMPLE TWO
    // int numbers[5] = {1, 2, 4, 8, 16};

    // EXAMPLE THREE
    numbers[0] = 1;
    for (int i = 1; i < size; i++)
    {
        numbers[i] = numbers[i - 1] * 2;
    }
    // Starts at 2, 4, 8, 16 (create seperate for loop for printf to grab the i = 0 numbers[0] = 1.)
    // Print out the values one by one
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", numbers[i]);
    }
}