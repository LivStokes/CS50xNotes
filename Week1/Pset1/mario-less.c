#include <stdio.h>
#include <cs50.h>

void print_row(int bricks, int height);

int main(void)
{
    // Prompt user for input.
    int height;
    do
    {
        height = get_int("Height: ");
    } 
    while (height < 1 || height > 8); // So that it wont exceed < 1 or > 8


    // Print a pyramid of that height.
    for (int i = 0; i < height; i++)
    {
        print_row(i + 1, height);
    }
}

void print_row(int bricks, int height) // Declare new variable height.
{
    // To print spaces first:
    for (int i = 0; i < height - bricks; i++) // (height - bricks) times, meaning the top rows print more spaces and the bottom rows fewer, which shifts the #s to the right and creates a right-aligned pyramid shape.
    {
        printf(" ");
    }

    // To print the bricks:

    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}