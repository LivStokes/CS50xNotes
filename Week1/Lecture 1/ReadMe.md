Focusing on input of source code to an output of the machine code. This is achieved by a Compiler. Focusing on C.

To start coding, the terminal in GitHub will allow for gcc and other inline commands

IN TERMINAL
code hello.c -> creates a file called hello.c

IN CODESPACE
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}

make hello -> represents the compiler. making a programme called hello that is somewhere in the file.

./hello -> to run the machine code.

\n -> new line
\r -> carraige return
\" -> 
\'
\\ -> to type a literal \ 
...

#include <stdio.h> -> header file to access library. (Allows code such as the printf functionality). Stands for standard io.

manual.cs50.io -> simplified version of manual.
E.g. stdio.h library includes :
fclose - close a file
fopen - open a file
fprintf - print to a file
fread - read bytes from a file
fscanf - get input from a file
fwrite - write bytes to a file
printf - print to the screen
scanf - get input from a user
sprintf - print to a string

for printf:
This function prints a “formatted string” to the screen. It expects as input a “format string” that specifies what to print and zero or more subsequent arguments. The format string can optionally contain “conversion specifications,” placeholders that begin with % that specify how to format the function’s subsequent arguments, if any. For instance, if c is a char, this function can print it as follows using %c:

printf("%c\n", c);
Alternatively, this function could format that same value as an int as well using %i, as in an ASCII chart:

printf("%c %i\n", c, c);
And this function can print strings without any conversion specifications as well:

printf("hello, world\n");
Among this function’s supported conversion specifications are:

Conversion Specification	Type
%c	char
%f	double
%f	float
%i	int
%li	long
%s	string
To print an actual percent sign, use %%.

To specify the “precision” of a float or a double, %f can optionally contain a . after the % followed by a number of decimal places. For instance, this function could format the value of one third to one decimal place using %.1f:

printf("%.1f\n", 1.0 / 3.0);


from CS50.h
Focus : get_string

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("what's your name? ");
    printf("hello, answer\n");
}

$ make hello
$ ./hello
What's your name? Olivia
hello, answer
$

to make two phrases (if you want to say something followed by something else in the world of C, you need placeholders instead of joining things together, unike Python and other languages.)
$s means to put another string here, like a placeholder or a template in code where you plug in some values.
It can take two or more inputs by seperating them with a comma.
If a comma is inside quotes it is the literal grammatical comma. 
If a comma is outside quotes it is C seperating the first input to this function printf from the second.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("what's your name? ");
    printf("hello, %s\n", answer);
}

commands to run in terminal:
ls - list the files in current folder.
cd - change directory.
cp - copy file or folder.
mkdir - make directory.
mv - move file or rem=name one of those to a different name.
rm - remove. (y/n)
rmdir -remove directory.

mkdir hello -> creates folder called hello.
mv hello.c hello -> moves hello.c into hello folder.
mv hello.c old.c -> renames file
cp hello.c backup.c -> copys hello.c file to another file called backup.c
mv hello.c .. -> moves file back a directory.

string means text in the programming world.

Other types of values:
bool -> boolean true/false
char -> single character
double -> real numbers with decimal point of fractions
float -> real numbers with decimal point of fractions
int -> integer
long -> long integers
string -> text

for cs50.h library, use get_(value)

Introducing concept conditionals: expression that is evaluated.
If something is true, do this. Else, maybe do this other thing.

SINGULAR FORK

if (x < y)
{
    printf("x is less than y\n");
}

TWO WAY FORK

if (x < y)
{
    printf("x is less than y\n");
}
else
{
    printf("x is not less than y\n");
}

THREE WAY FORK

if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is not less than y\n");
}
else
{
    printf("x is equal to y\n");
}

= -> assigns a return value from right-hand side of a line code to the left-hand side.
== -> equals to.

C operators:
=
<
<=
>
>=
==
!= -> not equal to.
...

variables:
int counter = 0;

this means take current value (0) and add 1.
counter = counter + 1;
OR (adds one, then two, then three)
counter += 1;
OR (only adds one)
counter++;
OR (to decriment)
counter--;


$ code compare.c

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
}

$ make compare
$ ./compare
What's x? 1
What's y? 2
x is less than y

$./compare
What's x? 2
What's y? 1
NO OUTPUT (only have if x < y)

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else
    {
        printf("x is not less than y\n");
    }
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");

    }
    else if (x == y)
    {
        printf("x is equal to y");
    }
}

when using strings use double quotes -> "_"
When using single chars use single quotes -> '_'

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");
    if (c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n')
    {
        printf("Not agreed.\n")
    }
}

This code does not aquire for answers Yes or Y. only 'y' or 'n'.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
}

|| -> or
&& -> both have to be true which is two boolean expressions at once.

#include <stdio.h>

int main(void)
{
    printf("meow\n");
    printf("meow\n");
    printf("meow\n");
}

instead of printing the meow 3 times, we use a WHILE LOOP:

#include <stdio.h>

int main(void)
{
    int i = 3;
    while (i > 0)
    {
        printf("meow\n");
        i--;
    }
}

This means that the integer is less than 3 but is in a while loop where the integer is greater than 0 decrementing.
So it will loop and printf three times. 

#include <stdio.h>

int main(void)
{
    int i = 1;
    while (i <= 3)
    {
        printf("meow\n");
        i++;
    }
}

This code also works the same but is not the most conventional way.

#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}

This is the best code.

To condense it even more we use a FOR LOOP:

for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while (true)
    {
        printf("meow\n");
    }
}

This looses control as it is an infinite loop.
CTRL + C to escape in the terminal.

#include <cs50.h>
#include <stdio.h>

void meow(void)
{
    printf("meow\n");
}

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}


INT MAIN must go ontop of the code as it is the MAIN FUNCTION.
It wont work unless you call the function first at the top, under the librarys:
void meow(void);

#include <cs50.h>
#include <stdio.h>

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

#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
     meow(3);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}

variables only exist in the scope in which you create them/ inside the curly braces.

#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    meow(n);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}


DO WHIE LOOP -> will do something no matter what but will potentially do it again and again while some question is true, such as n being less than 1.


#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void meow(int n);

int main(void)
{
    int times = get_positive_int();
    meow(times);
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n;
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}


For the asignment, use design50 to check code.


To create Mario ? boxes:
#include <stdio.h>

int main(void)
{
    printf("????\n");
}

But we want to create a code that changes amount of ?.
We can use any loops. In this class we use the for loop.

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
}

prints ????$

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("?\n");
    }
}

prints 
?
?
?
?
$

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n");
}

prints 
????
$


#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("###\n");
    }
}

prints
###
###
###
$

#include <stdio.h>

int main(void)
{
    for (int row = 0; row < 3; row++)
    {
       for (int col = 0; col < 3; col++)
       {
            printf("#");
       }
       printf("\n");
    }
}

also prints
###
###
###
$


Code so i can use it again:

#include <stdio.h>
#include <cs50.h>

void print_row(int n);

int main(void)
{
    const int n = 3;
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }
}

void print_row(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}


const int -> constant integer which will not ever change.

<!-- operators:
+ -> addition
- -> minus
* -> multiplied
/ -> divided
% -> remainder
... -->


For a calculator: 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    int z = x + y;

    printf("%i\n", z);
}

to condense the calculator, delete unnessesary int z and put x+ y elsewhere:

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", x + y);
}

To multiply code:

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");

    printf("%i\n", x * 2);
}


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int dollars = 1;
    while (true)
    {
        char c = get_char("Here's %i. Double it and give it to the next person.", dollars);
        if (c == 'y')
        {
            dollars *= 2;
        }
        else
        {
            break;
        }
    }
}

break is a keyword that if youre inside of a loop, you can forcibly break out of the loop early if and when you want to.


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int dollars = 1;
    while (true)
    {
        char c = get_char("Here's %i. Double it and give it to the next person.", dollars);
        if (c == 'y')
        {
            dollars *= 2;
        }
        else
        {
            break;
        }
    }
    printf("Here's $%i.\n", dollars);
}

This will keep doubling the dollars until it hits the max number of bits which is 32. Because of integer overflow.

max number of int = 2147483647
min number of int = -2147483648

to overcome this write integer as a LONG INT. int -> long int. %i -> %li.

Long integers also over flow
max number of long int = 9223372036854775807
min number of long int = -9223372036854775808



There's a photograph of a Boeing 787 years ago that actually had issues beyond the most recent issues with Boeing airplanes, whereby after 248 days, the Boeing 787, years ago, can lose all of its electrical power due to the generator control units simultaneously going into failsafe mode, whatever that means.
But if you dig into this, it turns out that there was a software counter in these airplanes years ago that would overflow after 248 days of continuous power. 
248 days, why?
Well, Boeing was using a 32-bit integer. And they were using it to count tenths of seconds. And it turns out, if you do the math, after 248 days, you have used too many tenths such that you overflow the size of a 32-bit integer.
The plane would essentially have this integer, this tiny, stupid little variable, overflow. But generally speaking, when your numbers suddenly go negative or 0, bad things happen.


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", x / y);
}

if i want to do x:3 y:2 it should be 1.5. But it outputs 1. This is because of a truncation. Int + int = int.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%f\n", x / y);
}
WRONG

I cant just change %i to %f (float).
Instead i can change everything to floats with get_float etc.
I want the user to type an int, but i want to show them real numbers with decimal points for correct math.
I can use whats called a casting value.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%f\n", (float) x / y);
}

There are fancy ways to tell how many digits i want to show.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%.50f\n", (float) x / y);
}

this wil give 1 / 3
0.33333334326744079589843750000000000000000000000000

floating-point imprecision is a fundamental problem with computers today.



32 bits eventually maxes out at, like, 4 billion positive, or 2 billion if you want negative and positive.
And it turns out, if you count the number of seconds between 1970 on up, on the day January 19, 2038, the world might again end because all of these clocks are going to overflow. And we're going to end up in the year 0 or negative something. Now, what's the solution there? I mean, my god, it's the exact same thing. Stop using so few bits. Use more bits. But bits and memory and computers used to be expensive. Nowadays, storage is so much more available.
But among the things we'll discuss then is how you can throw both hardware and software at this problem.
But for now, maybe set a Google Calendar reminder for January 19, 2038.
