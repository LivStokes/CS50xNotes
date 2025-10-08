# Readability

- This problem set is about determining the reading grade level required to understand a given piece of text. The program, implemented in readability.c, calculates the grade level based on the Coleman–Liau index, a formula designed to estimate the complexity of English writing.

T- he program analyzes the text entered by the user by counting the number of letters, words, and sentences. It then applies the following formula:

index = 0.0588 * L - 0.296 * S - 15.8

where:
- L is the average number of letters per 100 words, and
- S is the average number of sentences per 100 words.

Using this index, the program determines the approximate U.S. school grade level of the text.

- If the result is less than 1, it prints “Before Grade 1”.
- If the result is 16 or higher, it prints “Grade 16+”.
- Otherwise, it prints “Grade X”, where X is the rounded grade level.

## Example:
If the user inputs:
Congratulations! Today is your day. You're off to Great Places! You're off and away!

The program will output:
Grade 3

Purpose:
This project demonstrates basic text analysis using C. It teaches how to:
- Count letters, words, and sentences in a string.
- Perform arithmetic operations and rounding with floating-point numbers.
- Use control structures and conditional logic to produce readable output.