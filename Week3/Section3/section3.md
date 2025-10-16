# Algorithms

## Searching
Example - 
[odyssey] [macbeth] [eclipse] [hamlet] [inferno] [journey] [dune] 

7 books on table
Looking for book journey.

- Linear search - Could look at them one by one.

- Binary search - Sort books alphabetically, divide by half, go left or right depending on target and middle, divide and half, go left or right depending on midde, repeat until find book.

> Runtime Analysis looking for book

- Linear Search:
Worstcase - 7 / N / O(N)
Bestcase - 1 / Ω(1)

- Binary Search:
Worstcase - log2(7) / log2(N) / O(log2(N))
Bestcase - 1 / Ω(1)


## Sorting
- Merge Sort 
Worstcase - O(Nlog(N))
Bestcase - Ω(Nlog(N))

- Selection Sort
Worstcase - O(N2)
Bestcase - Ω(N2)

- Bubble Sort
Worstcase -O(N2)
Bestcase - Ω(N)

## Structs

typedef struct // typedef pertains to C syntax
{
    string name; // Specifications / customised elements of datastructure.
    int votes;
}
candidates; // How choosing to name datastructure.

How to make a variable of type candidate:
- candidate president;

How to define attributed:
- president.name = "Alice";
- president.votes = 10;


## Recursion
