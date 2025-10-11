
## Command line arguments

Examples of command line arguments:
make mario
./caesar 13

int main(int argc, string argv[])
{

}

What does it stand for?
int argc -> ARGument Count 
Number of command line arguments
string argv -> ARGument Vector
Array of strings holding multiple values

E.g. How to change alphabetical.c into a command line argument:

Check if a lowercase string's characters are in alphabetical order. If yes print yes, if no print no.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) // Changed output of main to argc, argv.
{
    // Get user input
    if (argc != 2) // If no second argument provided then exit and printf Please provide a word
    {
        printf("Please provide a word.\n");
        return 1;
    }

    string text = argv[1]; // Changed the string to take argument vector.
    int len = strlen(text);

    for (int i = 0; i < len(text); i++) // Going character by character. Using len so that strlen is used only one time on work and after i can keep using it as a variable.
    {
        if (!isalpha(text[i])) // Checking if its not alpha.
        {
            printf("This is not a letter.\n");
            return 2; // Distinguishing between the different errors.
        }
    }

    // Iterating through each element in the string.
    for (int i = 1; i < len(text); i++)
    {
        if (text[i] < text[i - 1])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}

isaplha function checks if it is alphabetical or not.
Return 0 if program runs successfully
Run 1, 2, 3 etc, to signify different errors.