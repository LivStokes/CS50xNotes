#include <stdio.h>
#include <cs50.h>

void draw(int n); // Prototype of function

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++) // Gives me rows
    {
        for (int j = 0; j < i + 1; j++) // Gives me number of bricks per row
        {
            printf("#");
        }
        printf("\n"); // Prints new line per row
    }
}