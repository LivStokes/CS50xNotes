# Bubble Sort
- Bubble sort is the idea of the algorithm to move higher valued elements generally towards the right and lower value elements generally towards the left.

## In pseudocode: 
Set swap counter to a non-zero value
Repeat until the swap counter is 0:
    Reset swap counter to 0.
    Look at each adjacent pair.
        If two adjacent elements are not in order, swap them and add one to the swap counter.

[5][2][1][3][6][4]

First sawp 5 and 2
.
[2][5][1][3][6][4]

Then check swap 5 and 1.

[2][1][5][3][6][4]

Then swap 5 and 3.

[2][1][3][5][6][4]

Keep repeating until finished.

- This algorithm builds array from right to left.

### Worstcase senario
- Array is reverse order; we have to "bubble" each of the n elements all the way across the array, and since we can only fully bubble one element into a position per pass we must do this n times.
- O(n2)

### Bestcase scenario
- The array is already perfectly sorted, and we make no swaps on the first pass.
- Ω(n)