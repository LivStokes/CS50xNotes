#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int wordScore(string word);

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Prompt input
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score of words
    int score1 = wordScore(word1);
    int score2 = wordScore(word2);

    // Score Output
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Scoring Function
int wordScore(string word)
{
    // Array of points in order
    int pointSum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            int letters = toupper(word[i]) - 'A';
            pointSum += points[letters];
        }
    }
    return pointSum;
}