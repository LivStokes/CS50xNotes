# Arrays
Arrays are a fundamental data structure.
Use arrays to hold values of the same type at continiguous memory locations.
Arrays are blocks of contiguous space in memorywhich has been partitioned into samll, identically-sized blocks of space called elements.
Each element of the array can store a certain amount of data.
Arrays can store elements of the same sata type such as int or char.
Can be accessed directly by an index number.

In C, elements of an array are indexed starting from 0.
If an array consists of n elements, the first element is located at index 0, the last element is located at index (n-1).
C is lenient as it wont prevent you from going out of bounds of your array.

## Array declarations
type name[size];
- Type = The type is what kind of variable each element of the array will be.
- Name = The name is what you want to call your array.
- Size = The size is how many elements you would like your array to contain.

When declaring and initializing an array simultaneously, there is  aspecial syntax that may cbe useful to fill up the array with its starting values.

// instantiation syntax
bool truthtable[3] = { false, true, false };
bool truthtable[] = { false, true, false }; // Computer is smart enough to see that there is 3 variables.

// individual elements syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;

Arrays can consist of more than a single dimension, you can have as many size specifiers as you wish:
bool battleship[10][10];
You can think of this as either a 10x10 grid of cells.
In memory this is a 100-element one-dimentional array.
Multi-dimentional arrays are great abstractions to help visualize game boards or other complex representations.

We can treat individual elements of arrays as variables, we cannot treat entire arrays themselves as variables.
We cannot assign one array to another using the assignment operator.
Instead - use a loop to copy over the elements at one at a time.






