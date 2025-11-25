# Python
- Higher level language which does lower level stuff more quick
e.g. asking for memory, giving memory back.
- you don't have to manage your own memory. 
- You can iterate over things much more quickly than using a traditional for loop as in C
- has even more of an ecosystem of libraries
- libraries being code that other people wrote that you can use.
-  We began in week 0, hello, in the world of scratch. Then trasitioned to a complex c implementation.
- In Python, if you want to implement hello, world, it's going to be reduced to a single one line.
> print("hello, world")
- No need for \n, f in printf, or ;

## Librarys
- We saw some libraries in C, we're also going to see them in Python, even more powerfully so.
- In the world of Python, just know that libraries are generally called **modules** and **packages**.
- There's some slight difference between those two, but, for now, module packages are just Python terminology for what we already to be libraries. 
- In Python, there is still going to be a CS50 library, but very brief training wheels that are available, if only to ease the transition from C to Python.
> import cs50
- There's alternative syntax you might see over time where if you only want to import one or specific things, you don't have to import the whole library.
- You can import from cs50 a specific function or symbol more generally like this.
> from cs50 import get_strinf
- Building on the program we wrote already by doing something just like we did in week 0 as well as in week 1, where we got input from the user.
- We had to introduce get_string.
- We also had to introduce, in the context of printf, these placeholders like %s. 
- There are several different ways to solve the same problem in Python.
- We can declare a variable called answer
> answer = get_string("Whats your name? ")
Then
> print("Hello, " + answer)
- The + represents concatanation.
Or
> print("Hello,", answer)
- In python if you pass 1+ arguments to the print function, they will all be printed with a single space inbetween them.
- A third and most common way:
> print(f"Hello, {answer}")
- Most common way.
- Pythons print function to format a string by pluging in one or more values is to place an f on the left of the string itself. AKA an f string. 
- Put curly braces and the name of the actual thing you want to plug in to that location. 
    - This is called variable interpolation whereby the variable's value, answer in this case, will be substituted without the curly braces appearing in the final output. 
    - So that's then how we might implement exactly that same feature using this thing called a format string.

### Example explanation
- code hello.py
```
print("hello, world")
```
vs 
- code hello1.c
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("Whats your name?: ");
    printf("Hello, %s\n", answer);
}
```
- Change pythons code to get input from the user:
```
from cs50 import get_string

answer = get_string("Whats your name?: ")
print(f"hello, {answer}")
```
- If we forget f, it wont print out the actual answer and will give back hello, {answer}.
- Differences: Didn't have to declare the type of variable.
- Python as an interpreter will figure it out from context.

## Positional parameters
- In Python, the default seems to be to give you a new line at the end of any print statement.
- how do you actually get those back-- or get rid of that if you indeed do?
- All of these parameters or arguments we've been using for weeks, where you just put a comma-separated list of arguments or values inside of parentheses when calling a function to give those functions input, those have been called positional parameters because the order has always mattered.
- The first thing, the second thing, the third thing influences what the function does with those arguments.

- In python theres also named parameters whereby you can actually specify not just a generic comma-seperated list of values for which the order matters. 
- You can instead provide the name of a variable and its value, the name of a variable and its value, specifically, the name of a parameter and its value as a comma-separated list, the upside of which is that it's a little clearer to you, the reader, you the programmer, what does what? 
- And it's also not nearly as vulnerable to you just screwing up the order and getting them slightly out of order and constantly having to check the documentation as to what goes in what order.
- If you recall using fread or fwrite, for instance, which takes a few arguments, those two are particularly annoying. 
- If we could just use the names of those parameters, it might've eliminated some ambiguity. 
- So how can we use in Python named parameters?
- Well, let's just do a relatively simple example that's actually pretty commonly leveraged, which is this:
```
print(Hello, world")
```
- If I want to get rid of this, though, I can do that by consulting the documentation for Python.
- The official documentation for Python lives at this URL, docs.python.org. 
- At this particular URL, there is a list of all of the functions that come built into Python itself.
> docs.python.org/3/library/functions.html
- In this documentation we can find print:
    - print(*objects, sep=' ', end='\n', file=None, flush=False)
- This is the signature or prototype for the print function.
- There is a function called print that potentially takes, 1, 2, 3, 4, 5 or more aruments or parameters. But why?
- Here is some new syntax:
    - *objects.
- This does not mean pointers. 
- There's a * but nothing to do with memory or * or memory or pointers. 
- This means that there's going to be 0 or more objects that can come as a comma-separated list. 
- We used the feature when printed hello + name. 
- When we use hello, name. we got back one-- passed in one or two arguments.
- This just means you can pass in 0 or more just by their position.

sep=' ', end='\n', file=None, flush=False 
- This is name parameters.
- The print function comes with one named parameter called sep for seporator, whose default value is a single space per the quote, unquote.
- The print function also comes with an end named parameter whose default value is \n.
- The print function also comes with file and flush, more on it later.
- The fact that these things have names sep and end means I can use these named parameters if I so choose to override their default arguments. 
    - So, for instance, if I want to override the separator, I can use, quote, unquote, "something else" in between words. 
    - If I want to override the new line, I can change the backslash n to something else as well.
```
print("hello, world", end="!")
```
-  So long as you put your positional arguments first and any things that have explicit names after those, Python can distinguish one from the other. 

### Variables
- C decleration:
```
int counter = 0;
```
- Python decleration:
```
counter = 0
```
- C changing count number
```
counter = counter + 1;
```
- Python changing count number
```
counter = counter + 1
```
- In C we can also do this
```
counter += 1;
```
- In python we do this:
```
counter += 1
```
- Python does not have ++ or --.

### Data types that python supports (30m)
- In C we have a data type list such as
    - bool
    - char
    - double
    - float
    - int
    - long
    - string

- In python we have
    - bool
    - float
    - int
    - str

- Pythons data structures:
    - range
    - list
    - tuple
    - dict
    - set

## Calculator
- Implementing a simple calculator:
In C:
```
int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", w + y);
}
```
In python:
```
x = input("x: ")
y = input("y: ")

print(x + y)
```
- x and y comes back as strings, concatenatingx and y.
- To fix this we do:
```
x = int(input("x: "))
y = int(input("y: "))

print(x + y)
```
- There is a function in Python called int, which takes as input a string. 
- It will do its best to convert that string to the actual int that resembles it.

## Conditionals
- In C, if you wanted to compare x and y as variables and say conditionally x is less than y:
```
if (x < y)
{
    printf("x is less tan y\n");
}
```
- In python it looks like this:
```
if x < y:
    print("x is less than y")
```
- There's a colon suddenly, which we did not have in C. 
- In Python, this is both a plus and a minus depending on your religion when it comes to whitespace in programs.
- In Python, they were frustrated by students and presumably colleagues alike formatting their code poorly that, in Python, indentation matters.
- So if you want to execute print conditional on x being less than y, you can't just put print right below if and expect the reader and the interpreter to figure things out. 
- You must indent by convention four spaces instead.
- the colon means execute conditionally everything that's indented below that as though there were curly braces instead.
- In C, If you wanted to do an if-else:
```
if (x < y)
{
    printf("x is less than y\n");
}
else
{
    printf("x is not less than y\n");
}
```
- In python it looks more like this:
```
if x < y:
    print("x is less than y")
else:
    print("x is not less than y")
```
- In C if you wanted to do an if, else if, else:
```
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```
- In python it looks like this:
```
if ( x < y)
    print("x is less than y")
elis x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```
- So we know what we can use these conditionals in this way. 

## Compare
- Let's go ahead now and revisit some programs from C but this time using some new syntax and features.
- Compare3.c in C:
```
{
    int x = get_int("Whats x? ");
    int y = get_int("Whats y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
```
- Implementation in python:
```
from cs50 import get_int

x = get_int("Whats x? ")
y = get_int("Whats y? ")

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```
- Comparing integers in Python logically works exactly the same way as in C, but things, recall, in Python got a little weirder when we actually tried comparing, say, strings instead.
- Why is it harder to compare strings in C?
- A string is really a char star, which is the address of the first character in the string. So whenever you compare two strings with equals equals in C, you're really comparing the memory addresses, and those probably are not going to be the same.
- in Python, if you want to manipulate strings, I can use the input function.
```
s = input("s: ")
t = input("t: ")

if s == t:
    print("Same")
else:
    print("Different")
```
- Ìn C, a program that used the getchar function to ask the user, do you agree with some terms and conditions:
```
int main(void)
{
    char c = get_char("Do you agree? ");

    if (c == 'Y' || c == 'y'");
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c =='n');
    {
        printf("Not agreed.\n");
    }
}
```
- In python:
```
s = input("Do you agree? ")

if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")
```
- If you want to express the idea of "or," literally write "or" instead of vertical bars and double ampersands and the like.
-  What Python does with parentheses is that if you don't need them logically to combine Boolean expressions, just don't use them at all.
- We can further tighten this code up:
```
s = input("Do you agree? ")

if s in ["Y", "y"]:
    print("Agreed.")
elif s in ["N", "n"]:
    print("Not agreed.")
```
- In Python, exists-- "in"-- as a preposition-- is a Python keyword.
- If we want to addres all outcomes such as "YeS", "yEs" etc.
- In C we used toupper or tolower to convert the user input to be all the same.
- In python we do something different.

## Object-Oriented Programming
- Python itself is known as an object oriented language (OOP).
- This reffers to a new and improved version of C structs.
- In C we had structs whereby we could create our own data types for like persons or nodes-- for instance, by creating our own data types that have one or more other values inside of them. 
- What C doesnt offer is to associate functionally with those structures as well.
- E.G. for a person object, it could be nice if there were a call function that would just automatically call that person or an email function that would just automatically email that person if we're keeping track of their email address as well.
- You could implement a call function and pass the person in as input.
- object-oriented programming allows you to associate more tightly and encapsulate related functionality, just like we've been encapsulating related data.
- Instead of having what are called structs in C, you have what are called **objects** in Python and certain other languages as well.
- Those objects are typically defined-- what's called a **class**.
- A Class is really just like a blueprint or a template out of which multiple objects can be made.
- We could consult the documentation for the functions that come with the str object.
- Whenever functionality is associated with a specific data type, it's encapsulated inside-- it's still a function, but you technically call it a **method**.
- Among the methods, that comes with strs, is a little something called **lower**.
- To simplify the list "Y", "y" etc., we can say:
```
s = input("Do you agree? ")

if s in ["Y", "y" etc...]:
    print("Agreed.")
elif s in ["N", "n"]:
    print("Not agreed.")
```
- If you know that input as a function already returns a string, you don't need to tuck it in a variable before you call that string's lower method. 
- You can just chain them together in this way. 
```
s = input("Do you agree? ").lower()

if t in ["y", "yes"]:
    print("Agreed.")
elif t in ["n", "no"]:
    print("Not agreed.")
```
- .lower() puts all users input to lowercase. Similar to tolower()

## Copy.py
- In C, to copy one string into another, the copy function looked like this:
```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    // Check to make sure s is not NULL incase were out of memory.
    if (s == NULL)
    {
        return 1;
    }

    // Use malloc to get more memory for the copy. 
    char *t = malloc(strlen(s) + 1);
    // Check to make sure s is not NULL incase were out of memory.
    if (t == NULL)
    {
        return 1;
    }

    // Copy the string from one to the other using strcpy.
    strcpy(t, s);

    // Make sure string is long enough.
    if (strlen(t) > 0)
    {
        // Uppercase the first letter in it.
        t[0] = toupper(t[0]);
    }

    // Print them out.
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Free the string.
    free(t);
    return 0;
}
```
- In python, we do this:
```
s = input("s: ")

t = s.capitalize()

print(f"s: {s}")
print(f"t: {y}")
```

## Loops
- Uppercase.c:
```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
```
- In python we still have loops, but we do it differently:
```
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}

TO

i = 0
while i < 3:
    print("meow")
    i += 1
```
- i += 1, is the same as i++.
- A for loop looks like this in C and Python:
```
for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}

TO

for i in [0, 1, 2]:
    print("meow")
```
- Alternatively you can use a function in python called range which gives you a range of values.
```
for i in range(3):
    print("meow")
```
- the range function hands you out one value at a time more efficiently than the hardcoded list, which puts them all in memory at once.
- it knows how to give you, indeed, just one value at a time.
- Were using the variable i, but not actually using i anywhere. 
- By convention, change the i to just an underscore character, which is a valid character for a variable. 
- It is a visual idicator that it is a for loop but the variable does not matter.
- It is also reasonable to use i because it means integer.
- But a conventional is _.
```
for _ in range(3):
    print("meow")
```
- How can we use these loops in actual code?
uppercase.py:
```
before = input("Before: ")
print("After: ", end="")
for c in before:
    print(c.uppercase(), end="")
print()
```
- We implemented a variable called before, set it equal to the return value of the input function with quote unquote "before" as the prompt.
- Then a placeholder of quote unquote "After" colon space, space, so they lined up in terms of numbers of letters, close quote, comma.
- Then end equals quote unquote because I don't want a new line to move the word below the word After.
- instead of using this convoluted for loop and the semicolons that in and this constant checking of a conditional, I can actually just do this:
- For every character called c in the Before string, go ahead and print out that character uppercase.
- But don't print out a new line yet until we get to the very end, go ahead and print a new line-- by printing nothing.
- So passing nothing in gives me one new line.

http://www.fiverr.com/s/YR5WR8K