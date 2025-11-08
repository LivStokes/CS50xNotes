# Functions
- So far, all the programs we’ve been writing in the course have been written inside of main().
- That hasn’t been a problem yet, but it could be if our programs start to become unwieldy.
- C and nearly all languages developed since allow us to write functions, sometimes also known as procedures, methods, or subroutines.

What is a function?
- A black box with a set of 0+ inputs and 1 output.

Why call it a black box?
- If we aren’t writing the functions ourselves, we don’t need to know the underlying implementation.

- That’s part of the contract of using functions. - The behavior is typically predictable based on that name. 
- That’s why most functions have clear, obvious(ish) names, and are well-documented.

Organization:
- Functions help break up a complicated problem into more manageable subparts.

Simplification:
- Smaller components tend to be easier to design, implement, and debug.

Reusability:
- Functions can be recycled; you only need to write them once, but can use them as often as you need!

## Function Declarations
T- he first step to creating a function is to declare it. 
- This gives the compiler a heads-up that a user-written function appears in the code.
- Function declarations should always go atop your code, before you begin writing main().
- There is a standard form that every function declaration follows.
> return-type name(argument-list);
- The return-type is what kind of variable the function will output.
- The name is what you want to call your function.
- The argument-list is the comma-separated set of inputs to your function, each of which has a type and a name.

A function to add two integers:
> int add_two_ints(int a, int b);

- The sum of two integers is going to be an integer as well.
- Given what this function does, make sure to give it an appropriate name.
- There are two inputs to this function, and we need to give a name to each of them for purposes of the function. 
- There’s nothing important about these inputs as far as we know, so giving them simple names is okay.

A function to multiply two floating point numbers:
>float mult_two_reals(float x, float y);

- The product of two floating point numbers is also a floating point number.
- Let’s be sure to give this a relevant name.
- Again, the names of these particular inputs don’t seem to be important, so we can call them anything simple.

```
float mult_two_reals(float x, float y); 
// Function declaration (;).

float mult_two_reals(float x, float y) 
// Function definition.
{
    float product = x * y;
    return product; // Passing output out.
}

int add_two_ints(int a, int b);

int add_two_ints(int a, int b)
{
    int sum; // Declare variable
    sum = a + b; // Calculate the sum
    return sum; // Give result back
}
```

## Function Calls
- To call a function, pass it through appropriate arguments and assign its return value to something of the correct type.
```
#inclulde <cs50.h>
#include <stdio.h>

int add_two_ints(int a, int b);

int main(void)
{
    // Ask user for input
    printf("Give me an integer: ");
    int x = GetInt();
    printf("Give me another integer: ");
    int y = GetInt();

    // Add the two numbers together via a function call
    int x = add_two_ints(x, y);

    // Output the result
    printf("The sum of %i and %i is %i\n", x, y, z);
}

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}
```

## Function Miscellany
- Functions can sometimes take no inputs (void)
- Functions can sometimes have no outputs (void return type)

- E.g. Declare a write function called valid_triangle that takes three real numbers representing the lengths of the three sides of a triangle as its arguments, and then outputs either true or false, depending on wether those three lengths are capable of making a triangle.
- A triangle may only have sides with positive length.
- The sum of the lengths of any two sides of the triangle must be greater than the length of the third side.
```
bool valid_triangle(float x, float y, float z)
{
    // Check for all positive sides
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }

    // Check that sum of any two sides greater than the third
    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }

    // If we passed both tests, its good!
    return true;
}
```  