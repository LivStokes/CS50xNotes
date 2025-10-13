# Algorithms

Algorithm designs.
Which one is the speediest.
Implementing an algorithm efficiently, focusing on design.

[] [] [] [] [] [] [] -> locked doors (array) of numbers. Checking for 50.

## Linear Search:
Going one by one in order from left to right.
For each door from left to right
    If 50 is behind door
        Return true
Return false

Only returning false once im done with that loop.
If poorly implemented this pseudocode like this:
For each door from left to right
    If 50 is behind door
        Return true
    Else
        Return false

If we do this and check the first locked door and its not 50, the program will stop.

## Binary Search
Split problem in 2, then in 2, then in 2 by going left or right each time.
Check middle of array first, if number is higher than 50 (100) then check the middle of the left side, if number is lower than 50 (25), check the middle of the right side.

Linear search:
For i from 0 to n-1
    If 50 is behind doors[i]
        Return true
Return false

Binary search:
If no doors left
    Return false
If 50 is behind middle door
    Return true
Else if 50 < middle door
    Search left half
Else if 50 > middle door
    Search right half

Making this algorithm more quantatative using array syntax:
If no foors left
    Return false
If 50 is behind doors[middle]
    Return true
Else if 50 < doors[middle]
    Search doors[0] throught doors[middle - 1]
Else if 50 > doors[middle]
    Search doors [middle + 1] through doors[n - 1]

Binary Search does not work if the data is random / unsorted. Therefore you need to sort the data first.

## Asymptotic Notation - running times 
The way a computer scientist describes the running time of an algorithm is by using mathematical notations to imply on the order of this many steps.
// ²₂
O(n) // Linear Search is worst case.
O(n²)
O(log n) // Binary Search is best case.
O(n log n)
O(1)
Ω = Big Omega tells you the best case performance of an algorithm.

### For linear search:
O(n) - Worst case, upper limit
Ω(1) - Best case, lower limit
### For binary search:
O(log n) - Worst case, upper limit
Ω(1) - Best case, lower limit
### For bubble sort:
O(n²) - Worst case, upper limit
Ω(n) - Best case, lower limit

### Θ capital Theta
The third and most balanced asymptotic notation

While O describes the worst case,
Ω describes the best case,
Θ (Theta) describes the average or tight bound — meaning the algorithm’s running time grows at the same rate in both best and worst cases.

## For ints:
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50}; // Creates array of size 7 and initiallises value from left to right.

    int n = get_int("Number: ");
    for (int i = 0; i < numbers[i - 1]; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0; // To signify it works
        }
        // Wrong because I need to take else out of the for loop or else it will stop the search.
        // else
        // {
        //     printf("Not found\n");
        // }
    }
    // This is also wrong because it will still print out Not found. So we must return a value.
    printf("Not found\n");
    return 1;
}

## For strings:
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++) // cant do i < s[strings - 1] because subscript is not an int.
    {
        if (strings[i] == s) // == is not how to compare strings. We need strcmp.
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

### strcmp prototype:
int strcmp(string s1, string s2);

returns:
- an int less than 0 if s1 comes before s2,
- 0 if s1 is the same as s1,
- an int greater than 0 if s1 comes after s2.

FIX:
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++) // cant do i < s[strings - 1] because subscript is not an int.
    {
        if (strcmp(strings[i], s) == 0) // Calling strcmp function, passing 2 strings as input, comparing them, if they are same char to char, return 0.
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

Phonebook example:
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"David", "John", "Yuliia"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750", "+1-617-495-1000"};

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0) // comparing i'th name as name i typed in.
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

Badly designed reasons:
- Magic number still there.
- Must have both strings alligned in order to get correct number to correct name.

## Data structures
If i wanted to create an array of people, it would be nice to have a data type called person.

How can we encapsulare this name and number in a bit of new syntax
string name;
string number;

Createing your own type, that is a structure specifically:
typedef struct
{
    string name;
    string number;
}
person;

This is to define a type, that is itself a structure inside of which is both a name and number which is both stirngs, and call that whole new structure person.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];

    people[0].name = "David";
    people[0].number = "+1-617-495-1000"; // the . operator
}

Once youve created a structure inside of the computers memory, if you want to go inside it and access the things that compose it, like name and number, you just use a dot.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];

    people[0].name = "David";
    people[0].number = "+1-617-495-1000"; // Use the . operator if you want to go inside it and access the things that compose it, like name and number.

    people[1].name = "John";
    people[1].number = "+1-949-468-2750";

    people[2].name = "Yuliia";
    people[2].number = "+1-617-495-1000";

    string name = get_string("Name: "); // Prompt for name
    for (int i = 0; i < 3; i++) // Looking thorugh te string
    {
        if (strcmp(people[i].name, name) == 0) // If return value of strcmp
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

- This is still using linear search.

## Data sorting

unsorted -> [] -> output
5436721890 -> [] -> 0123456789
We need an algorithm to sort it.

We can:
Smaller numbers to left, Bigger numbers to right.

### Selection Sorting: (Not very efficient)
Swap 5 and 0 to lessen the problem.
Swap 4 and 1 to lessen the problem.
Swap 3 and 2 to lessen the problem.
Etc.

[] [] [] [] [] [] []
[0] .............. [n-1]

How to implement in pseudocode:
For i from 0 to n-1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]

(n-1) + (n-2) + (n-3) +.... + 1
n(n-1)/2
(n²-n)/2
n²/2-n/2
O(n²) selection sort
O(n log n)
O(n)
O(log n)
O(1)

### Bubble sort:
Swap 5 and 4.
Swap 5 and 3.
Swap 6 and 5.
Swap 7 and 6.
Swap pairs ajecently from lower to bigger side by side.
Etc.

How to implement in pseudocode:
Repeat n times
    For i from 0 to n-2
        if numbers[i] and numbers[i+1] out of order
            Swap them
    if no swaps
        quit

(n-1)x(n-1)
n²-1n-1n+1
n²-2n+1
O(n²)

## Recursion

if no doors left
    return false
if number behind middle door
    return true
^ BASE CASES

else if number < middle door
    search left half
else if number > middle door
    search right half
^ RECURSIVE CASES

This algorithm is called recursive.
One that calls itself.
A function is recursive if it calls itself.
what if main called main? That is an example of recursion.

Base cases = specific cases e.g. if no doors left, return false, if number behind door, return true.
Recursive cases = where you dont get an answer yet.

Iterative version of code:
1 Pick up phone book
2 Open to middle of phone book
3 Look at page
4 If person is on page
5   Call person
6 Else if person is erlier in the book
7   Open to middle of left half of book
8   Go back to line 3
9 Else if person is later in book
10  Open to middle of right half of book
11  Go back to line 3
12 Else
13  Quit

Recursive version of code:
1 Pick up phone book
2 Open to middle of phone book
3 Look at page
4 If person is on page
5   Call person
6 Else if person is erlier in the book
7   Search left half of book
8 Else if person is later in book
9  Search right half of book
10 Else
11  Quit

Iteration is the more comfortable approach.

## Iteration vs Recursion mario example:

### Iteration
#include <stdio.h>
#include <cs50.h>

void draw(int n); // Prototype of function

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++) // Gives me rows
    {
        for (int j = 0; j < i + 1; j++) // Gives me number of bricks per row
        {
            printf("#");
        }
        printf("\n"); // Prints new line per row
    }
}

### Recursion
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int height)
{
    if (height <= 0)
    {
        return;
    }

    draw(height - 1);

    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}

## Merge Sort
If only one number
    Quit
Else
    Sort left half of numbers
    Sort right half of numbers
    Merge sorted halves

[] [] [] [] [] [] [] []
[1] [3] [4] [6]  [0] [2] [5] [7]
Points at first number in each half (1 and 0), then puts the lower number in the top empty space.
[0] [] [] [] [] [] [] []
[1] [3] [4] [6]  [] [2] [5] [7]

TO

[0] [1] [] [] [] [] [] []
[] [3] [4] [6]  [] [2] [5] [7]

TO

[0] [1] [2] [] [] [] [] []
[] [3] [4] [6]  [] [] [5] [7]

ETC.
If you want to improve running time, you have to spend resourses. 
Uses twice as much memory space.
This is 
n log²(on bottom) n

That is to say, merge sort, unlike selection/bubble sort, is in big O of n log n, which log n is smaller than n. so n times log n is  

## Sort race

Merge sort = Fastest
Selection sort = Second fastest
Bubble sort = Third fastest















