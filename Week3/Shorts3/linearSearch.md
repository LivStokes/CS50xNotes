# Linear Search
- Is an algorithm used to find an element in an array.
- An algorithm recall is a step by step instruction to complete a task.
- The linear search algorithm works as follows: 
- iterate across the array from left to right looking for a specified element.

- In pseudocode:
- Repeat starting at the first element.
- If the first element is what youre looking for (the target), stop.
- Otherwise move to the next element.


- We can use the linear search algorithm to find targets in an array:
[11][23][8][14][30][9][6][17][22][28][25][15][7][10][19]
- Target: 9

- In pseudocode:
- Repeat, starting at the first element.
- If the frst element is what youre looking for (the target), stop.
- Otherwise, move to the nex element.

> 11, 23. 8. 14. 30, 9!

- We dont know if we didnt find a target until each element of the array has been looked at.
- Only once we have done that we can then conclude if the target has been reached of not.

## Worst case scenario:
We have to look through the entire array of n elements, either because the taget element is the last element of the arrat or doesnt exist in the aray at all.

- In the worst case we have to look in every single element, so it runs in 
    - O(n)

## Best case scenario:
- The target element is the fist element of the array, and so we can stop looking immediatly after we start. 

- In the best case the element is found immediatly, so it runs in 
    - Omega(1)