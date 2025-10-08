#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    // Prompt User.
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1; // initiallise to 1 because every 4 words has 3 spaces.
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++) // initialises i to 0, keep going as long as its less than the string called text, i++(one by one).
    {
        // LETTER COUNT
        // if ((text[i] > 65 && text[i] < 90 ) || (text[i] > 97 && text[i] < 122))
        if (isalpha(text[i])) // if text is between ASCII values 65 AND 90 A - Z OR 97 AND 122 a - z, then go through loop
        {
            letters++;
        }

        // WORDS COUNT
        else if (text[i] == 32) // if text has a space (32) count +1.
        {
            words++;
        }

        // SENTENCES COUNT
        else if (text[i] == 46 || text[i] == 63 || text[i] == 33) // if text has a, . (46), ? (63), ! (33) count +1.
        {
            sentences++;
        }
    }

    // GRADE LEVELS CALCULATIONS
    float L = (float) letters / (float) words * 100; // L = letters per 100 words
    float S = (float) sentences / (float) words * 100; // S = Sentences per 100 words
    // change ints to floats because int / int will give an int but we want decimals for answers.

    int index = round(0.0588 * L - 0.296 * S - 15.8); // Reading level formula
    // We want to round this up with a function called round. (double round(double x);)

    // GRADE SCORE
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
