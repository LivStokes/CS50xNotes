# Bubble Sort
- Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.
- It is the idea of the algorithm to move higher valued elements generally towards the right and lower value elements generally towards the left.
- This algorithm is not suitable for large data sets as its average and worst-case time complexity are quite high.

## In pseudocode: 
- Set swap counter to a non-zero value
- Repeat until the swap counter is 0:
- Reset swap counter to 0.
- Look at each adjacent pair.
- If two adjacent elements are not in order, swap them and add one to the swap counter.
```
Initial array
[5][2][1][3][6][4]

First swap 5 and 2
[2][5][1][3][6][4]

Then check swap 5 and 1.
[2][1][5][3][6][4]

Then swap 5 and 3.
[2][1][3][5][6][4]

Keep repeating until finished.
```
- This algorithm builds array from right to left.

### Worstcase senario
- Array is reverse order; we have to "bubble" each of the n elements all the way across the array, and since we can only fully bubble one element into a position per pass we must do this n times.
- O(n2)

### Bestcase scenario
- The array is already perfectly sorted, and we make no swaps on the first pass.
- Ω(n)

## Example in C code
```
void ft_sort_int_tab(int *tab, int size)
{
    int i;
    int temp;

    while (size > 1)
    {
        i = 0;
        while (i < size - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
            }
            i++;
        }
        size--;
    }
}

int main(void)
{
    int tab[] = {5, 2, 9, 1, 7, 3};
    int size = sizeof(tab) / sizeof(tab[0]);

    printf("Before sort: ");
    for (int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");

    ft_sort_int_tab(tab, size);

    printf("After sort:  ");
    for (int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");

    return 0;
}
```

## How it works:
- while (size > 1) 
    - We only need to sort if there are at least 2 elements.
    - Each loop of this while is one full pass through the array.
    - After each pass, the largest element among the unsorted part moves to the end, so we reduce size by 1.

- i = 0;
    - Before each pass, we start comparing from the beginning of the array.

- while (i < size - 1)
    - During a pass, we compare adjacent elements:
    - Compare tab[i] and tab[i + 1]
    - Stop at size - 1 because we look one element ahead (i + 1).

- if (tab[i] > tab[i + 1])
    - If the left element is greater, they are out of order.

Swap:
- temp = tab[i];
- tab[i] = tab[i + 1];
- tab[i + 1] = temp;
    - We swap the two so that the smaller one moves left and the bigger one moves right.
    - This is the key action:
    - Big elements bubble toward the end.

- i++;
    - Move to the next pair.

- size--;
    - After one full pass:
    - The largest element is guaranteed to be in its correct position at the end.
    - No need to compare it again.
    - So we reduce the “unsorted” part of the array.
    - This continues until size becomes 1 — which means everything is sorted.

### Summary
On each pass:
1. Start from the left.
2. Compare neighboring elements.
3. Swap them if they’re in the wrong order.
4. Keep going until you reach the end of the unsorted section.
5. After each pass, the largest remaining element is placed at the end.
6. Shrink the unsorted section and repeat.
- This continues until the whole array is sorted.