# Insertion sort Algorithm
- Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list.
- You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

## Method
1. Start with the second element of the array as the first element is assumed to be sorted.
2. Compare the second element with the first element, if the secont element is smaller then swap them.
3. Move to the third element, compare it with the first two elements, and put it in its correct position.
4. Repeat until the entire array is sorted.

## Illustration
```
Initially
[23][1][10][5][2]->[23][1][10][5][2]

First Pass
[23][1][10][5][2] ->[1][23][10][5][2]

Second pass
[1][23][10][5][2]->[1][10][23][5][2]

Third Pass
[1][10][23][5][2]->[1][5][10][23][2]

Fourth Pass
[1][5][10][23][2]->[1][2][5][10][23]
```

## So...
- arr = {23, 1, 10, 5, 2}

Initial:
- The current element is 23.
- The first element in the array is assumed to be sorted.
- The sorted part until 0th index is : [23].

First Pass:
- Compare 1 with 23  (current element with the sorted part). 
- Since 1 is smaller, insert 1 before 23. 
- The sorted part until 1st index is: [1, 23] .

Second Pass:
- Compare 10 with 1 and 23 (current element with the sorted part). 
- Since 10 is greater than 1 and smaller than 23, insert 10 between  1 and 23. 
- The sorted part until 2nd index is:  [1, 10, 23].
 
Third Pass: 
- Compare 5 with 1, 10, and 23 (current element with the sorted part). 
- Since 5 is greater than 1 and smaller than 10, insert 5 between  1 and 10 
- The sorted part until 3rd index is: [1, 5, 10, 23].

Fourth Pass: 
- Compare 2 with 1, 5, 10, and 23 (current element with the sorted part). 
- Since 2 is greater than 1 and smaller than 5 insert 2 between 1 and  5. 
- The sorted part until 4th index is: [1, 2, 5, 10, 23].

Final Array: 
- The sorted array is:  [1, 2, 5, 10, 23].

## Time Complexity
- Best Case:
    - O(n)
- Average Case:
    - O(n2)
- Worst case: 
    - O(n2)

## Space Complexity
- Auxiliary Space: O(1).
- Insertion sort requires O(1) additional space, making it a space-efficient sorting algorithm.

## Advantages and Disadvantages of Insertion Sort

### Advantages
- Simple and easy to implement.
- Stable sorting algorithm.
- Efficient for small lists and nearly sorted lists.
- Space-efficient as it is an in-place algorithm.
- Adoptive. the number of inversions is directly proportional to number of swaps. For example, no swapping happens for a sorted array and it takes O(n) time only.

### Disadvantages
- Inefficient for large lists.
- Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases.

## Applications of Insertion Sort
Insertion sort is commonly used in situations where:
- The list is small or nearly sorted.
- Simplicity and stability are important.
- Used as a subroutine in Bucket Sort
- Can be useful when array is already almost sorted (very few inversions)
- Since Insertion sort is suitable for small sized arrays, it is used in Hybrid Sorting algorithms along with other efficient algorithms like Quick Sort and Merge Sort. When the subarray size becomes small, we switch to insertion sort in these recursive algorithms. For example IntroSort and TimSort use insertions sort.

```
#include <stdio.h>

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
```