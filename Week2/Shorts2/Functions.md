# Functions
So far, all the programs we’ve been writing in the course have been written inside of main().

That hasn’t been a problem yet, but it could be if our programs start to become unwieldy.

C and nearly all languages developed since allow us to write functions, sometimes also known as procedures, methods, or subroutines.

What is a function?
A black box with a set of 0+ inputs and 1 output.

Why call it a black box?
If we aren’t writing the functions ourselves, we don’t need to know the underlying implementation.

That’s part of the contract of using functions. The behavior is typically predictable based on that name. That’s why most functions have clear, obvious(ish) names, and are well-documented.

- Organization
Functions help break up a complicated problem into more manageable subparts.
- Simplification
Smaller components tend to be easier to design, implement, and debug.
- Reusability
Functions can be recycled; you only need to write them once, but can use them as often as you need!

## Function Declarations
The first step to creating a function is to declare it. This gives the compiler a heads-up that a user-written function appears in the code.

Function declarations should always go atop your code, before you begin writing main().

There is a standard form that every function declaration follows.

return-type name(argument-list);

The return-type is what kind of variable the function will output.

The name is what you want to call your function.
The argument-list is the comma-separated set of inputs to your function, each of which has a type and a name.

A function to add two integers.
The sum of two integers is going to be an integer as well.
Given what this function does, make sure to give it an appropriate name.
There are two inputs to this function, and we need to give a name to each of them for purposes of the function. There’s nothing important about these inputs as far as we know, so giving them simple names is okay.

- A function to multiply two floating point numbers :
float mult_two_reals(float x, float y);

The product of two floating point numbers is also a floating point number.
Let’s be sure to give this a relevant name.
Again, the names of these particular inputs don’t seem to be important, so we can call them anything simple.