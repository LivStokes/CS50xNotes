Agenda :
- Variables and Operators
- Functions
- Loops
- Problem Set 1

# Variables and Operators
## Part 1 Variables and Types Input and Printing.

Example of the Phone Book:
looking for a contact or person, flipping pages, or going to middle and using a more efficient algorithm of finding that person.

How phone books comprise. What are the components of those?

Imagine that one of the variables in a phone book is called "calls". So maybe it is the number of calls that one friend called you.
Maybe they called 4 times. 
This can be imagined having this square or a little box that stores some value, in this case it is 4.

int calls = 4;
type, name, assignment operator, value;
Can be worded like,
Create an integer named calls that gets the value 4.

int x = 50;
Create an integer named x that gets the value 50.

int calls = 4;
calls = calls + 1;

Makes the calls = 5.

So say I didn't have that number of calls stored in the phone book just yet. I wanted to get it from the user.
How can we get input from the user?

int calls = get_int("Calls: ");
Prompt -> get_int -> calls
"Calls: " -> get_int -> 4

Function name = get_int
Function input = ("Calls: ");

%i %d are interchangeable.
Theyre both used for integers if we want to print them out.
%d is a little deprecated and weve veen using %i since. Default to %i.

How to print values:

int calls = 4;
printf("calls equals %i, calls);

%i is a format code, one of the options used for integers.

Types and format codes:
Numbers:
%i = int
%f = float

Text:
%c = char
%s = string

True/False:
%i = boolean


Write a program "Hello, World"
#include <stdio.h>

int main(void)
{
    printf("Hello, World\n");
}

Write a program "Hello, "name""
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");
    printf("Hello, %s\n", name);
}

Write a program that stores and prints out some information (like name, age, phone number) of your friends.
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Name
    string name = get_string("What is your name? ");

    // Age
    int age = get_int("What is your age? ");

    // Hometown
    string hometown = get_string("What is your hometown? ");


    // Phone Number
    string number = get_string("What is your number? ");

    printf("My new frineds name is %s, %i, they are from %s and their phone number is %s\n", name, age, hometown, number);
}

## Part 2 Loops and Condtionals
if (calls < 1) // boolean expression
{
    printf("Call more often!"); // conditional code
}
else
{
    printf("Thanks for calling!");
}

Loops:
While loop:
int i = 0;
while (i < 2)
{
    printf("%i\n", i); // %i prints out an integer on a new line, the integer.
    i = i + 1;
}

for loop:
for (int i = 0; i < 2; i++)
{
    printf("%i\n", i);
}

When to use for loops:
When you know the exact number of steps.

When to use while loops:
More fluid,

## Part 3 Mario
Starting with pyraminds.
Left- aligned pyramid:

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for input.
    int height = get_int("What is the height of the pyramid? ");

    // Print a pyramid of that height.
}

#include <stdio.h>
#include <cs50.h>

void print_row(int bricks);

int main(void)
{
    // Prompt user for input.
    int height = get_int("What is the height of the pyramid? ");

    // Print a pyramid of that height.
    for (int i = 0; i < height; i++)
    {
        print_row(i + 1); // so that it gets initialised at 1 rather than 0.
    }
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}

This gives me:
height 4:
<!-- 
#
##
###
#### 
-->

What if i ask a height of -2? It kics me out.
To stop this we need a do while loop.
int main(void)
{
    // Prompt user for input.
    int height;
    do
    {
        height = get_int("What is the height of the pyramid? ");
    }
    while (height < 1);


    // Print a pyramid of that height.
    for (int i = 0; i < height; i++)
    {
        print_row(i + 1);
    }
}

How do i make it go the other way?