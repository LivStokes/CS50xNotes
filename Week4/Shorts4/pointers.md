# Pointers
- Useful for passing data back and forth between functions, that we're otherwise unable to do.
- They provide alternative ways to pass data between functions.
- Up until this point, we have passed all data by value, with one exception.
- When we pass data by value, we only pass a copy of that data.
- One exception to this rule of passing by value, which we will come back to.

- If we use pointers instead of using variables, we can pass the variable around between functions in a different way. We have the power to pass the actual variable itself.
- That means that a change is made in one function can impact what happens in a different function.

### Example:
- When we try swap the value of two variables in a function, like swapping x and y, we pass them through a function called swap. Inside the function swap, the variables do exchange values, one becomes two, two becomes one, but we dont actually change anything in the original function in the caller because were only working with copies of them.
- With pointers we can actually ass x and y to a function, that function can do something with them, and those variable values can actually change. This is an example of our ability to work with data.

## How computer memory works
- There are types of different file storage location from 250 gigabytes to a couple of terabytes.
- When your computer shuts off and you turn it back on, your files are still there even when you reboot your system.
- Every file on your computer lives on your disk drive, be it a hard disk drive (HDD) or a solid-state drive (SSD). 
- Disk drives are just storage space; we cant directly work there. Manipulation and use of data can only take place in a RAM, so we have to move data there.
- RAM might contain less memory such as 512 megabytes to 16 or more gigabytes.
- This is where all the more volatile data exists. (Where we can change things).
- When we turn out computer off, akk of the data in the RAM is destroyed. Which is why we need to have hard disk for the more permenant location of it.
- So ultimatly, we work inside of RAM.
- Memory is basically a huge array of 8-bit wide bytes.

## Data types Size (in bytes) in RAM
- When we move things into memory it takes up a certain amount of space, all the data types that we've been working with take up different amounts of space in RAM.
- So everytime we create an integer variable, four bytes of memory are set aside in RAM so you can work with that integer. (Declaring, Changing, Assigning).
> int = 4 bytes
> char = 1 byte.
> float = 4 bytes.
> double = 8 bytes.
> long long = 8 bytes.
> string = ???.





