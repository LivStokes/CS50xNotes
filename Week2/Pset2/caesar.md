# Caesar

This program implements Caesar’s cipher: a simple substitution cipher that "rotates" each alphabetical character in a plaintext message by a fixed number of positions (the key). For example, with a key of 1, A → B, B → C, …, Z → A; thus HELLO becomes IFMMP.

## Requirements

Implement your program in a file named caesar.c inside a directory called caesar.

- The program must accept exactly one command-line argument: a non-negative integer key k.

- If the program is run with no command-line arguments or with more than one, print Usage: ./caesar key and return 1.

- If the provided argument contains any non-digit characters, print Usage: ./caesar key and return 1.

- Convert the command-line key to an integer and use it to encrypt user input.

- Prompt the user with plaintext: (note the spacing) and read a line of text.

- Output ciphertext: followed by the ciphertext and a newline.

For each character in the plaintext:

- If it is an uppercase letter, rotate it forward by k positions through A–Z, preserving uppercase.

- If it is a lowercase letter, rotate it forward by k positions through a–z, preserving lowercase.

- Non-alphabetical characters must be output unchanged.

- The key can be greater than 26; rotation should wrap around the alphabet (use k % 26 for the effective shift).

- On success, return 0.

## Behavior examples

$ ./caesar // should throw an error
Usage: ./caesar key

$ ./caesar banana
Usage: ./caesar key

$ ./caesar 1 // Setting the key
plaintext:  HELLO
ciphertext: IFMMP

$ ./caesar 3
plaintext:  Hi!
ciphertext: Kl!


## Implementation hints

Check argc to make sure there is exactly one command-line argument.

Write a helper function (e.g., bool only_digits(string s)) to validate that the key contains only digits.

Convert the key string to an integer (e.g., atoi), and compute k = k % 26.

Write a rotate function that takes a char and the integer k, returns the rotated character (or the original char if non-alphabetical). Use isupper, islower, and character arithmetic to preserve case and wrap around.

Use get_string (from CS50) to get plaintext input.

## Purpose
This exercise practices command-line argument handling, input validation, character manipulation, and modular arithmetic in C while producing a simple, reversible encryption routine (Caesar’s cipher).