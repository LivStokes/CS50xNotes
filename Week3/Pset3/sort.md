From lecture3, we saw a few algorithms for sorting a sequence:
- selection sort
Selection sort iterates through the unsorted portions of a list, selecting the smallest element each time and moving it to its correct location.

- bubble sort
Bubble sort compares pairs of adjacent values one at a time and swaps them if they are in the incorrect order. This continues until the list is sorted.

- merge sort
Merge sort recursively divides the list into two repeatedly and then merges the smaller lists back into a larger one in the correct order.

In this problem, you’ll analyze three (compiled!) sorting programs to determine which algorithms they use.
Record your answers, along with an explanation for each program, by filling in the blanks marked TODO.

Provided to you are three already-compiled C programs, sort1, sort2, and sort3, as well as several .txt files for input and another file, answers.txt, in which to write your answers.

Each of sort1, sort2, and sort3 implements a different sorting algorithm: selection sort, bubble sort, or merge sort.

Your task is to determine which sorting algorithm is used by each file. 

sort1 uses: Bubble sort

How do you know?: sort1 reversed list took 5.198s; sort1 sorted list took 0.330s.

sort2 uses: Merge sort

How do you know?: sort2 reversed list took 0.343s; sort2 sorted list took 0.328s.

sort3 uses: Selection sort

How do you know?: sort3 reversed list took 2.964s; sort3 sorted list took 2.881s.
