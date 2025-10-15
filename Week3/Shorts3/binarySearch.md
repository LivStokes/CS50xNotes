# Binary Search

- In binary search, the idea of the algorithm is to divide and conquer, reducing the search area by half each time, trying to find a targer number.

- In order to leverage this power however, our array must first be sorted, else we cannot make assumptions about the arrays contents.

## Pseudocode steps:
Repeat until the (sub)array is size 0:
- Calculate the middle point of the current (sub)array.

- If the target is at the middle, stop.

- Otherwise, if the target is is less than whats at the middle, repeat. changing the end point to be just to the left of the middle.

- Otherwise, if the target is greater than whats at the middle, repeat, changing the start point to be just the right of the middle.

[11][23][8][14][30][9][6][17][22][28][25][15][7][10][19]

- Cant do this test in an unsorted array, as we are not guarenteeing that the certain elements or values arent being accidently disgarded when we decide to ignore half of the array.

- Step one = sort array.
- Step two = binary search.

If target is 16, we strt binary search by going to the middle which is 7(15), 16 is bigger than 15 so we search to the right with new starting point 8(17). 
17 is greater than our target and therefore we start to the left 7(15).
If start and end point cross, we can say that the target does not exist in the array.

## Worst-case scenario
We have to divide a list of n elements in half repeatedlt to find the target element, either because the targer element will be found a the end of the last divistion or doesnt exist in the array at all.
- O(log n)

## Best-case scenario
The target element is at the midpoint of the full array, and so we can stop looking immediatly after we start.
- Ω(1)


