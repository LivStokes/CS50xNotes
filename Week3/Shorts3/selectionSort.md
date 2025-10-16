# Selection Sort
- Selection sort is an algorithm that sorts a set of elements.
- An algorithm is a step by step set of instructions for completing a task. 

## Basic idea
- In selection sort, the idea of the algorithm is to find the smallest unsorted element and add i to the end of the sorted list.
- Builds a sorted list, one element at a time.

## In pseudocode:
> Repeat until no unsorted elements remain:
    > Search the unsorted part of the data to find the smallest value.
    > Swap the smallest found value with the first element of the unsorted part.

### Worstcase scenario:
- We have to iterate over each of the n elements of the array (to find the smallest unsorted element) and we must repeat this process n times, since only one element gets sorted on each pass.
- O(n2).

### Bestcase scenario:
Exactly the same! Theres no way to guarantee the array is sorted until we go through this process for all the elements.
- We must go through the whole array to ensure it is all sorted.
- Ω(n2).