# Memory
> Learning about pointers

- When we look at photos, the more we zoom, the more pixelated it gets. This is because theres only so many bits or bytes associated with them that prescribe what color those dots should be.

Different formats for images:
- PNG
- JPEG
- GIF

The simplest of them is a bitmap image which is a map of bits horizontally and vertically conceptually with 0s and 1s.
- Example 0 is back and 1 is white.

When it comes to colour, we need more than 0 and 1, we probably need 24 - Pixel art.

This pixel art is meant to motivate the topic of manipulating data t a lower level, including images and other thing.

## Hexidecimal
- Images can be represented as RBG - Red Green Blue.
- We can represent this using another system.
- We have binary which is base 2.
- We have decimal, which is base 10.
- We have hexidecimal, where you have 16 digits at your disposal. So known as base 16.

Composes of 6 or 3 digits. 
- #000000 - Black.
- #ffffff - White.
- #ff0000 - Red.
- #00ff00 - Green.
- #0000ff - Blue

Why ff?
- Hexideximal gives another 6 digits in our vocabulary.
0123456789ABCDEF
They are called digits out of convention as we need more symbols.

How does this work mathamatically?
- If there are teo place holders ##, each represent the 16th to the 0th place, the 16th to the 1 place.
- 0f represents the number 15.
- ff is the highest we can count in hexidecimal.
- This is 16 times 15 plus 1 time 15 which gives me 255.
- Can represent a single hexidecimal digit wether its 0 or f, using 4 bits no matter what.
- We use 2 hexidecimal digits - 1111 1111, to be able to describe a single bite, known as a bit, using 2 digits rather than 8.

## Memory
- A memory address is represented in hexadecimal format, a base-16 numbering system. 
- This format uses numbers 0-9 and letters A-F, offering a more compact representation than binary. 
- Hexadecimal makes it easier for programmers to read and work with memory addresses.

#include <stdio.h>
int main(void)
{
    int n = 50;
    printf("%i\n", n);
}

- Whats going inside the memory in this case?
- The computer finds room in the computer to store n 50 in 4 bites (ints are 4 bites). 
- The address in which it might live could be placed at the location 0x123.

## Pointers
- & = address of operator. The compiler will tell you where that variable is in the computers memory.

- '*' = dereference operator. Goes to an address.

- %p = print pointers.
- A pointer is a variable that stores the address of something.


int n = 50;
int *p = &n;

> int *p
- This is saying that I want a variable called p, the type of this variable is a pointer, and I want it to be the address of an integer.

> &n
- The address of n. 

> int *p = &n;
- Wherever n is, get the address of it ike 0x123 and assign it to the variable p, which is a pointer to the address of an integer.

![alt text](pointers.png)
```
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}
```
When terminated, this gives an address of 0x7ffc6f5b451c
- If did the math, it would bea  very large decimal number.
- Why this number? The server has gigabytes of memory, billions of bytes.
```
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", p);
}
```
If i take out int *p = &n;, I get a different address because things got organised in memory differently.

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", *p);
}

This gives me the integer 50.

- Two uses of the star opporator.
1. int *p = &n; - Declaring the pointer, creating the pointer, using star and type.
2. printf("%i\n", *p); - This means go there, dereference the address.

- Pointers are 64 bits, or 8 bytes.
- P is a variable whose value is an address.
- N is an integer at that address.

## Strings
string is not a standard c function.

> string s = "HI!";
- string s is storing the address of the first byte of the actual characters.
- The memory of a string starts at the 0th place in the array and ends at the null terminator \0.
- A string is just an address of its first character.

For example:
char *s = "HI!";
- A string is a char star.
```
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
```
    printf("%p\n", s);
Has the same address as
    printf("%p\n", &s[0]);

printf("%p\n", s); = 0x62b35b8ae004
printf("%p\n", &s[0]); = 0x62b35b8ae004
printf("%p\n", &s[1]); = 0x62b35b8ae005
printf("%p\n", &s[2]); = 0x62b35b8ae006
printf("%p\n", &s[3]); = 0x62b35b8ae007

The notion of persons:
typedef structs
{
    string name;
    string number;
} person;

- person = the name we gave to the data type
- struct { string name; string number } = what we wanted a person to be.
- typedef = how we brought it into existence.

typedef char * string;
- The right way would be:
typedef char *string; // string is not being declared as  variable here. but rather a type.

How to define a datatype for a string?
typedef char * string;
```
int main(void)
{
    char *s = "HI!";
    printf("%c\n", &s[0]);
    printf("%c\n", &s[1]);
    printf("%c\n", &s[2]);
}
```
## Pointer arithmetic
If every chunck of memory has an address and that address is a number, we can do math on addresses. If i can start in one location, we can go one byte away, 2 bytes away, 3 bytes away, just by adding 1 or 2 or 3.

Implication:
- No need for square bracket notation anymore to print out individual elements of an array.

Example:
```
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
```
- printf("%c\n", *(s + 1)); // Goes one location to the right.
```
int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
}
```
- This prints out the whole string.

What if I only want to print out part of the string?:
```
int main(void)
{
    char *s = "HI!";
    printf("%s\n", s + 1);
}
```
This prints out "I!"

## Erratum
This is comparing if two integers are the same or different.
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");

    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```
- What happens in memory is that both integers are side by side, 4 bytes each. (32 bites, 32 bites).

## String compare
- strcmp - string compare to compare the two strings properly.
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```
- Provides errors caling all strings different.

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```

- This is declaring it now to not only be a string, but more precisely the address of a character. Technically the first character of a string.

- This is storing the *s and *t in a different chunk of memory to the strings at s and t.
- So when asking to compare the string s and t, which is saying compare the two char *'s, which is also saying compare the two addresses, they are at two different places. So it will state "Different".
- A solution to this is strcmp.
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```
- This is fixing the solution by dereferencing s and t, and then under the hood in some sort of loop, iterates over these two strings in memory, checking wether the individual chars == eachother. Then stopping onve it hits \0 in either string.
- They do this by converting it somewhere in the loop ASCIIbeticaly.
- If they are the same character by character, then it returns 0.

## Copying and malloc
Where we might need to make copies of strings in memory
```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: "); // prompts user for string

    string t = s; // copys the string

    t[0] = toupper(t[0]); // capitalises first letter of the string (toupper uppercases a character.)

    printf("s: %s\n", s)
    printf("t: %s\n", t)

}
```
- This will output:
s = hi
s = Hi
t = Hi
- Because it is copying the memory in s to the memory in t. Meaning both the variables contain the same address. Even if we follow t's address it will lead me to the same addres as s.
- It wont matter if i follow s or t when i dereference either, as implied by the square bracket notation.

### Solution
Have to be more careful when making actual copies.
- Instead of blindly copying s and calling it t, we can use a function called malloc.

### Malloc
- Malloc = Memory allocation.
> This function lets us pass in as input, a number, How many bytes of memory do we want, and it will hand us back a chunk of memory.
> Specifically it will hand us back the address of that chunk of memory.
> Specifically the address of the first byte of that chunk of memory.

### Free
- Free is the opposite.
> Once were done with this memory, you can call free and give it back to the computer so that you dont eventually run out of memory.

How to leverage this in my own code?
- We can implement a copy a little more cleverly.
```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

}
```
- Instead of using char *t = s;, we can say that t initially should store the address of a new chunk of memory thats big enough to store the characters of s. We use this with malloc and free.
```
int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(4);

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

}
```
char *t = malloc(4);
- This gives me 4 bytes of memory and stores the address of the first byte in t. (This is a stupid aproach as we are hardcoding 4.)
- So we can use:
char *t = malloc(strlen(s) + 1);
- This finds out the length of the string and + 1 for the null character and ask malloc for that amount of bytes.
- What is stored in t now is the address of that chunk of memory, specifically the address of the first byte in that memory.
- After allocating that chunk of memory, we use a loop.
```
#include <stdlib.h> // To use malloc.

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(4);

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

}
```
- t[i] = s[i]; // This copys from left to right.
- i <= n; // This iterates from i less than or equal to n because i want to copy the null character aswell.
- The for loop iterates over s and t in lockstep such that h gets copied, i gets copied etc. Because its <=, the \0 also gets copied.
- Then we use toupper on t[0] and so only the h in t is now capitalized.

```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```

- This succesfully prints:
s = hi
s = hi
t = Hi

- In cases of error, malloc returns to you 0. If there is no valid bytes left.
- NUL means nul treminator \0.
- NULL means something went wrong.
- We need to defence this by creating outcomes for all possible wrong doings:

```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);
    if (t== NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```

- There are librarys and function to condense this code:
```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);
    if (t== NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```

- Although this program works, it can cause a  memory leak.
- We need to free the memory with the free.
```
int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);
    if (t== NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}
```
- This keeps track of how many bytes we ask for and free that byte onwards when requested.

## Valgrind
There are tools that can help us find these mistakes so that if and when tour program crashes, we dont have to stare at the screen for help.
- we can use software tools that detect these common errors.
- Valgrind is a command line program whose output will allow us to look at thr program for memory-related errors.

- Here is an example of a bug:
```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
}
```
- We are allocating a variable called x that is a pointer to an integer.
- We are allocating space for 3 integers.
> Give me memory for three of these things (the size of the integers).
- sizeof is an oporator in C that lets us figure out what is the size of the type of variable.
1. First mistake = we did not 0 index the array.
2. Second mistake = Not freeing memory.

- To debug this with valgrind we can use the command
valgrind ./[filename]
- This will give us cryptic output errors.

Errors to look out for:
1. invalid write of size 4
2. HEAP SUMMARY = 12 bytes in 1 blocks are definetly lost in record 1 of 1.
3. LEAK SUMMARY = definetly lost: 12 bytes in 1 blocks.

- losing 12 bytes must be a memory leak.
- Eventually i have to free x.

```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
}
```

## Garbage values 
```
#include <stdio.h>

int main(void)
{
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
```
- The problem with this is that i have neither hard coded those actual scores, nor have i prompted the user for the scores with get_int or anything else.
- When output, there is 1024 garbage values.

- If you know theres going to be more output than you can see at once, you can write:

./garbage |  less
- This shows you less of the output at a sime, one screenfull at a time.
```
int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    *y = 13

    y = x;
    
    *y = 13;
}
```
- The first *y = 13 will crash because we havent set an address for y yet meaning we are pointing to a random location and storing the value 13 at it which will crash.
- It is a garbage value.
- So take it away.

## Swapping
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

- This would swap the values of a and b.
- However, this would only be true in the scope of temp.

Example:
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n, x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

- a and b will swap values, however x and y will stay the same values.
- This is due to memory.
- We change the variables local to the swap function, but it has no effect on main that is using this function.
- This is due to passing things by value, we are passing copies of those values.
- When we pass an x and y, youre really passing in a copy of x and a copy of y that you can do anything you want to. Were calling them a and b in the context of swap, but that has no effect on the original versions of x and y.

- To correct this, we must add pointers so that the temp values point to the main values.
 
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

- So for our code, we need to change the main function, function swap to make it functionable:
- Passing it through the address.

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n, x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

## Overflow
Even though the code is correct, we have created another problem.
- Even though we have understanded how the stacks working, and we claim that the heao is where malloc takes memory from, having the two arrows heap and stack pointing at eachother is not a good design.
- If we keep calling heap, by calling malloc alot, we overflow the stack.
- Or if we call lots of functions as we might with recursion, we might overflow the stack.
Terms of art:
> Heap overflow
> Stack overflow
- If we call malloc many times, we may overflow some other area of memory with the heap.
- Stack overflow is when you call so many functions it overflows eachother and hit the heap or overflow eachother in some ways.
- These are examples of what are called buffer overflows where buffer means a chunk of memory.
- An array is just a buffer with a finite size that you can potentially overflow going past the boundaries of it.

## Scanf
Scanf is the opposite of printf.
- Used to read formatted data from the standard input stream.
```
// #include <cs50.h>
// #include <stdio.h>

// int main(void)
// {
//     int n;
//     printf("n: ");
//     scanf("%i", &n);
//     printf("n: %i\n", n);
// }

#include <stdio.h>

int main(void)
{
    char *s; // Contains a garbage value.
    printf("s: ");
    scanf("%s", s); // Dangerous because it wont know where the string will end.
    printf("s: %s\n", s);
}
```

## File I/O
File input and output.
Functions related to files: 
- fopen
- fclose
- fprintf
- fscanf
- fread
- fwrite
- fseek

>By creating a file phonebook.c and phonebook.csv
>Type this code:
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "w");

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number);

    fclose(file);
}
```
> And in terminal type:
Name: Olivia
Number: 92384092385

- The name and number will show in the file phonebook.csv

- There is a bug where when i upload a new name and number, itwill oberwrite the old name and number.
- This is because we chose to write to this file.
- We can use "a" instead of "w" to append.

```
int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number);

    fclose(file);
}
```
- This works for things like google sheets etc.
- Things can go wrong with files in terms of memory so we must use return values.

```
int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number);

    fclose(file);
}
```

To read and copy one file to another file , we can code:

```
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE; // Gives me a byte of 8 ints.

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0) // starts a loop that iterates over the file called src, byte by byte.
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}
```

- This file manipulation can be used in things such as image resolution like changing the colours, outlining, swapping bites to  make image other way around etc.
