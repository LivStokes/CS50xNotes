# Recursion
- Gives elegant code
- Solves interesting easy to visualise and short code.

- It is an implementation of an algorithm as being particularly "elegant" if it solves a proble in a way that is both interesting and easy to visualize.

- The technique of recursion is a very common way to implement such an "elegant" solution.

- The definition of a recursive function is one that, as part of its execution, invokes itself.

- Solves problems without excessivity and long loops.

## How recusrion can be defined
- The factorial function (n!) is defined over all positive integers.
- n! equals all of the positive integers less than or equal to n, multiplied together.
- Thinking in terms of programming, we'll define the mathematical function n! as fact(n).

- E.g. 5 factorial is 5 * 4 * 3 * 2 * 1.
fact(1) = 1
fact(2) = 2 * 1
fact(3) = 3 * 2 * 1
fact(4) = 4 * 3 * 2 * 1
fact(5) = 5 * 4 * 3 * 2 * 1
...
- This is basically saying:
fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * fact(4)
...
- This is basically saying:
fact(n) = n * fact(n-1)

- This generalization of the problem allows us to recursivly define the factorial function.
- This forms the basis for a recursive definition of the factorial funciton.

### Recursive function cases

- Every recursive function has two cases that could apply, given any input.

> The base case 
- When triggered will terminate the recursive process. Otherwise the cuntion that calls itself could go on forever.
- If no way to stop it, the function could be stuck in an infinite loop.
- Simple solution to a problem which stops recursive process from occurring.

> The recursive case
- Where the recursion will actually occur. The function calls itself. 
- Although not in the exact same wat it was called. It will be a slight variation that makes the problem its trying to solve a bit smaller.

## Examples
- Which of these is the base case?
fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * fact(4)
- fact(1) = 1.
- This means we want to stop the recursion when it gets to 1.

When defining our factorial function, heres a skeleton for how we might do that.
- We need to plug in those two cases - base case, and recursive case.

int fact(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }
    // recursive case
    else
    {
        return n * fact(n-1);
    }
}

- For the sake of having more cleaner and more elegant code, if we have single-line loops or single-line conditional branches, we can get rid of all the curly braces around them.
- It has the same exact funcrionality.
- Taking away curly braces because theres only one line inside of those conditional branches.

int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}

- We make the problem smaller.
- This is the solution to calculating the factorial of a number. Its only 4 lines of code.
- In general, recursive functions replace loops in non-recursive functions.

## Recursive vs Iterative

### Recursive
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}

### Iterative
int fact2(int n)
{
    int product = 1;
    while(n > 0)
    {
        product *= n;
        n--;
    }
    return product;
}

- It is possible to have more than one base case, or more than one recursive case, depending on what your function is trying to do.
- This is more likely when the program might recurse or terminate in different wats, depending on the input being passed in.
- In general but not always, recursive functions replace loops in non-recursive functions.

## Multiple base cases
- An example of something with more base cases is the fibonacci number sequence:
- The first element is 0.
- The second element is 1.
- The nth element is the sum of the (n-1)th and (n-2)th elements.
E.g. 
- Third element would be 0 plus 1 = 1.
- Fourth element would be second element, 1, plus the third element, 1 = 2.
So... this is where we have 2 base cases,
- If n = 1 then return 0.
- If n = 2 then return 1.
- Otherwise return fibonacci of n - 1 plus fibonacci of n - 2.

## Multiple recursive cases
- The collatz conjecture.
- This applies to positive integers and speculates that it is always possible to get "back to 1" if you follow these steps:
- if n is 1, stop.
- Otherwise, if n is even, repeat this process on n/2.
- Otherwise, if n is odd, repeat this process on 3n + 1. (3 * n + 1)

### Excersize
- Write a recursive function collatz(n) that calculates how many steps it takes to get to 1 if you start from n and recurse as indicated above.

- Return the number of steps it takes for n to reach 1.

int collatz(int n)
{
    if (n == 1) // base case.
        return 0;
    else if ((n % 2) == 0) // test if n is even. 
        return 1 + collatz(n/2); // for even n, compute one step (the 1 +) then call collatz recursively on n/2. The returned value is the remaining number of steps; you add 1 for the current step.
    else
        return 1 + collatz(3*n + 1);
}

- if n = 1, then collatz(n) = 0, steps 1.
- if n = 2, then collatz(n) = 1, steps 2 -> 1.
- if n = 3, then collatz(n) = 7, steps 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1.
- if n = 4, then collatz(n) = 2, steps 4 -> 2 -> 1.
- etc.

