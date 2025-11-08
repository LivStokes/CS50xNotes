# Arrays
Preprocessing. Compiling. Assembling. Linking. Debugging. Arrays. Strings. Command-Line Arguments. Cryptography.

## Real world problems
Reading Levels:
1. Grade 1
2. Grade 3
3. Grade 10

## Cryptography / Compiling
- Scrambling information.
- Source code -> compiler -> machine code
- clang hello.c
- ./a.out
- make = clang
```
#include <stdio.h>

int main(void)
{
   printf("hello, world\n") ;
}
```
- code hello.c
- clang hello.c
- ls in this folder will now be a.out, hello.c
- We can provide more arguments to clang with command line arguments.
- When run command, you can type name of command/programme your running, you can also give arguments to input to that program.
- When using make hello, the argument your running is hello.
- clang -o hello hello.c // -o means output of file called hello when you compile hello.c
- ./hello
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n, name);
}
```
- clang -o hello hello.c -lcs50
is equivelent to 
- make hello.c
> ./hello

- When we use make, 4 things happen:
1. preprocessing
2. compiling
3. assembling
4. linking

- #include <stdio.h> -> preprocessor directive (starts with hashtag)
```
void meow(void);
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

void meow(void)
{
    printf("meow\n");
}
```

### compiling:
- means it gets translated from one language to another language (C to assembly code) goes from source code to zeros and ones total.

### Assembling:
- Converts ones and zeros: converting your assembly code into machine code

### Linking:
- How many files are involved in the prccess of compiling this code?
```
#include <cs50.h?
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name";)
}
```
- There are three. 
- The main programme, cs50.h, and stdio.h.

- What happens in the fourth and final step of building your program, compiling program is this: hello.c, cs50.c, and stdio.c.

## Debugging
- Debugging is the process of locating and removing bugs from your code.
- Debugging technique: rubber duck debugging - talk to inanimte object to help through code and why its not working.
- // Buggy example for printf
```
#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 3; i++)
    {
        printf("#\n");
    }
}
```
- The code prints 4 blocks instead of 3.
so then type code buggy0.c into the terminaland write the code above.
- // Buggy example for printf
```
#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 3; i++)
    {
        printf("i is %i\n", i); // this helps identify issue.
        printf("#\n");
    }
}
```
- Running this code, you will see numerous statements, including i is 0, i is 1, i is 2, and i is 3. Seeing this, you might realize that further code needs to be corrected as follows:
```
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("#\n");
    }
}
```
- This code can be further improved as follows:
- // Buggy example for debug50
- code buggy.c
```
#include <cs50.h>
#include <stdio.h>

void print_column(int height);

int main(void)
{
    int h = get_int("Height: ");
    print_column(h);
}

void print_column(int height)
{
    for (int i = 0; i <= height; i++)
    {
        printf("#\n");
    }
}

IN TERMINAL:
make buggy
./buggy
Height: 2
//#
//#
//#
```
- debug50 ./buggy
"Looks like you havent set any breakpoints.
- A breakpoint is a stop sign you can add to any line of code and tell the computer to break execution at that point.
- A red dot appears when hovered on left side of code. When clicked it places dot.
- It runs the code and stops at the breakpoint.

Locals
h = 32766
This means previous program used tge same memory inside of the computer for something else.
It is whats called a Garbage value (remnants of what the momory was previously used for. which has no significance to us.)

When click run over, the programm will run and pause on the next line.
This asks us the height in terminal.
When type 3, top left local h = 3.
Step over again, it still prints 4 #.

Rub debuggy again and press step into, this execution jumped into the print column functon.
When press step over again, it moves to printf("#\n");
Terminal window at the bottom opens. i = 0,.
Step over that and i = 1, then i = 1, then i = 2, then i = 3. In terminal this prints 4 #.

This gives me the ability to step through my code line by line at a normal pace.

## Types / scores
Data Types Sizes:
- bool = 1 byte
- int = 4 bytes
- long = 8 bytes
- float = 4 bytes
- double = 8 bytes
- char = 1 byte
- string = ? bytes

When storing memory, they are contiguous back to back in memory chip.
E.g.
```
#include <stdio.h>
int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    // Print average
    printf("Average: %f\n", (score1 + score2 + score3) / 3);
}
```
- Error = truncation after the decimal point (int + int + int / int = get back int)
- To solve, change 3 to 3.0, or cast the 3 to a float by adding (float) before it.
- Now when i run the code by make scores ./scores, it gives me an average of 59.333333
- What is badly designed abuot this program?
- If i want more score i would keep just adding score 4,5,6... and it becomes too long. Instead we can set the value to just scores.

## Arrays
An array is a sequence of values back to back / contiguous in memory all of which are the same data type.

int scores[3];

The syntax for creating not one, but any number of values is by specifying what type the value should be - int, what name te variable should be - scores, how many integers do you want to be associated. Use square brackets.

Square brackets indicate an array of integers. in this case its an array of 3 values (starting from 0).

int scores[3];

scores[0] = 72;
scores[1] = 73;
scores[2] = 33;

printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);


All same variable, but indexing the array by jumping to a specific location.

How to make it better again:

#include <stdio.h>

int main(void)
{
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}

Still poory designed as there is still the magic number 3 everywhere.

I can create another variable above scores[3] which says int N = 3;
If I want to tell the computer to not let even me change this number, write const int N = 3;

Use capitals for constants.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int N = 3;
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) N);
}

When using floats they may be slightly imprecise.
// Average three numbers using an array, a constant, and a helper function

#include <cs50.h>
#include <stdio.h>
// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void)
{
    // Get scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    // Print average
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}

## Strings

#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!':

    printf("%i %i %i\n", c1, c2, c3);
}

Why use single quotes instead of double?
Because its a character and not a string.

if i use %i instead of %c, it will pring 72 73 33, the ASCII equivelant to those letters.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%s\n", s);
}

A string is an array of characters.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%c %c %c\n", s[0], s[1], s[2]);
}

- A string is a sequence of characters, an array is a sequence of values.

## String Length

The way a computer keeps track of where the end of a string is, the length of the string / array thats storing the string is technically 4. Its 1 plus whatever the actual length of the array is.

It spends one extra byte always for strings and fills them with all 0s, 00000000. ( which indicates where the string stops.)
Typically the convention i sto put \0 to make clear that this is a special character.

So... if i make the code 

int main(void)
{
    string s = "HI!";
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}

the fourth %i will be 
H I ! 0, 0 indicates where the sting ends. \0 is NUL.

When you use double quotes, thats a visual cue to the language to indicate a string to terminate with \0.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string = words[2];
    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
}

This is a mechanical way of figuring out dynamically the length of a string.
So if i write Name: Olivia, I will get 6 because I am not including the null character.

#include <cs50.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);
}

int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}

This is creating the function strlen (string length).

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0; i < strlen(s); i++) // no need to call strlen. Can improve.
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
this is better:
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0; n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

## Uppercase
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') // Can change to ASCII a = 97, z = 122.
        {
            // Change s[i] to uppercase
            printf("%c", s[i] - 32)
        }
        else
        {
            // Just print s[i]
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```
Can use the ctype.h library toupper function to get:
```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
```
## Command Line Arguments (argc and argv)
They are arguments are words you can type at the command line to influence the behaviour of the programme.
E.g.
make hello - hello is the command line argument.
clang hello.c - hello.c is the command line argument.
hello -o hello hello.c -o and hello hello.c are the command line argumentS.

How to write code that accesses workds at the command line?
 
We can change the (void) in main to accept command line arguments.

#include <stdio.h>

int main(int argc, string argv[])
{
    ...
}

- These are two arguments, one is a int and the other is an array of strings.
- When an array is passed into a function, leave [] empty.
- This implies that main can, if you want, take an int and array of strings.

- argc = argument count (how many command line arguments have been provided)
- argv = argument vector (vector is often another word for an array)

### How to use this technique?
- Old way:
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("Whats your name? ");
    printf("hello, %s\n", answer);
}
```
- New way:
```
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("hello, %s\n", argv[0]);
}

make greet
./greet Olivia
output: Hello, ./greet
```
- If you make argv[0] it will output ./(programme name).
- So argv[1] would output: Hello, Olivia, which is the next string of the command.
- To avoid printing out (null) if user inputs an extra string, we can code:
```
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("This is too few or too many strings\n");
    }
}
```
- To get all displays of command line:
```
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}
```

## Cowsay

If i enter cowsat moo in terminal :
$ cowsay moo

moo 

        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
$ 

$ cowsay -f duck quack
 _______
quack 

 \
  \
   \ >()_
      (__)__ _
$

$ cowsay -f dragon RAWR
 ______
RAWR 

      \                    / \  //\
       \    |\___/|      /   \//  \\
            /0  0  \__  /    //  | \ \    
           /     /  \/_/    //   |  \  \  
           @_^_@'/   \/_   //    |   \   \ 
           //_^_/     \/_ //     |    \    \
        ( //) |        \///      |     \     \
      ( / /) _|_ /   )  //       |      \     _\
    ( // /) '/,_ _ _/  ( ; -.    |    _ _\.-~        .-~~~^-.
  (( / / )) ,-{        _      `-.|.-~-.           .~         `.
 (( // / ))  '/\      /                 ~-. _ .-~      .-~^-.  \
 (( /// ))      `.   {            }                   /      \  \
  (( / ))     .----~-.\        \-'                 .~         \  `. \^-.
             ///.----..>        \             _ -~             `.  ^-`  ^-_
               ///-._ _ _ _ _ _ _}^ - - - - ~                     ~-- ,.-~
                                                                  /.-~

## Exit Status

Error code 1132 in zoom or Error code 404 in webpage. This happens when someone puts code in when error happens.

0 means success, any other number means failure. Because theres thousands of things that could go wrong. e.g. 1132, 404.

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}

echo $?
This is what is the return value.

if i say
./status
Missing command-line argument
$ echo $?
1

if i say 
./status Olivia
hello, Olivia
$ echo $?
0

## Encryption
Cryptography
Encryption is the process of scrambling information, but in a reversable way.

Mental model:
input -> [] -> output
plaintext -> [] -> ciphertext
[cipher]

whats in the middle is an algorithm implemented in code.
Cipher is the type of function that enciphers information from plaintext to ciphertext.

Catch with a cipher is that it must rely on a secret valur known as a key that is provided to ciphers as a second input.

E.g.
If the input plaintext is Hi!, and the key is 1, the outbut would be IJ!, if you are using an encryption algorithm known as the Caesar cipher.
A becomes B, B becomes C etc.

ROT13, means rotating numbers by 13.

ROT26 is bad because it goes A to A, B to B etc.
- Decripting is just minusing the key, e.g. -1 C to B, B to A etc.