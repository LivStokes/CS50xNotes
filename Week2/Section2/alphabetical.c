// Check if a lowercase string's characters are in alphabetical order. If yes print yes, if no print no.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get user input
    string text = get_string("Input: \n");

    // Iterate through each element in the string
    for (int i = 1; i < strlen(text); i++)
    {
        // Check if it is alphabetical
        // printf("%c - %i\n ", text[i], text[i]); // This gives us the ascii value of each character %c - %i.
        if (text[i] < text[i - 1]) // If text i - 1, if the next character is bigger than the first, then quit.
        {
            printf("No\n");
            return 0;
        }
    }
    // Print out yes or no
    printf("Yes\n");
}