# Merge sort
- Common attributes of all types of sorts is they all have worsecase runtime of n squared.
- Can we do better than that? yes - merge sort.
- In merge sort, the idea of the algorithm is to sort smaller arrays and then combine those arrays together (merge them) in sorted order.
- Merge sort leverages something called recursion.
- It is the most complicated of the four different types of sorts that has been covered.

## In pseudocode
- Sort the left half of the array (assuming n > 1)
- Sort the right half of the array (assuming n > 1)
- Merge the two halves together.

[5][2][1][3][6][4].

### Left side of array
- First we focus on left half of array.
[5][2][1].
- Then focus on left half of the subarray.
[5].
- Because its only one, it is concidered sorted.
- Then move onto the right side.
[2][1].
- Sort left half of subarray.
[2].
- Sort right half of subarray.
[1].
- Decide which of the [2][1] is smaller or bigger.
- Merge them.
[1][2].
- Now we have to merge two halves of [5] [1][2].
- Compare 5 and 1, 1 is smaller so it is now first element. 
- Compare 5 and 2, 2 is smaller so it is now the second element.
[1][2][5].

### Right side of array
- Now we sort the right half of the array.
[3][6][4].
- Then focus on left half of the subarray.
[3].
- Because its only one, it is concidered sorted.
- Then move onto the right side.
[6][4].
- Sort left half of subarray.
[6].
- Sort right half of subarray.
[4].
- Decide which of the [6][4] is smaller or bigger.
- Merge them.
[4][6].
- Now we have to merge two halves of [3] [4][6].
- Compare 3 and 4, 3 is smaller so it is now first element. 
- Because 4 has nothing to compare to on the left side, everything goes in.
[3][4][6].

- We have gone through two pseudocode steps. Sorting left half of array and right half of array.
- Now we merge.
[1][2][5] [3][4][6].
- Compare left and right.
- 1 is lower than 3.
- 2 is lower than 3.
- 5 is higher than 3.
[1][2][3] [5][4][6].
- 5 is higher than 4.
[1][2][3][4][5][6].
- 5 is lower than 6.

### Worsecase scenario
- We have to split n elements up and then recombine them, effectively doubling the sorted subarrays as we build them up. ( combining sorted 1-element arrays into 2-element arrays, combining sorted 2-element arrays into 4-element arrays...).
- O(n log n) which is faster than n squared.

### Bestcase scenario
- The array is already perfectly sorted. But we still have to split and recombine it back together with this algorithm.
- Ω(n log n).
- In best case, it can be slower than bubble sort where array happens to be perfectly sorted.
