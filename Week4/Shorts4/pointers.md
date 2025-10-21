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

- Memory is a big array of byte-sized cells.
- Every element is one byte wide.
- Just like an array, every element an address.
- Every element of an array has an index, and we can use that index to do so-called random access on the array.
- Arrays are not only useful for storage of information, but also for so-called random access.
- We dont have to start at the beginning of an array, iterate through every single element thereof, to find what we're looking for.
- We can just say, I want to get the 15th element or the 100th element.
- We can pass that number and get the value we're looking for.
- Similarly, each location in memory has an address.

### Visual in memory
Think of memory outlayed like this from 0-19.
[][][][][][][][][][][][][][][][][][][][].
- H stored at 4, 65 stored at 8-11.
[][][][][H][][][][.65.][][][][][][][][].
- In memory, when storing a char H, and an int 65, it actually translates to binary.
- What is being stored is the binary representation of a char H and int 65:
> Char H: 01001000.
> Int 65: 0000000000000000,0000000001000001.
- This isnt entirely true either, because of something called an endianness, which we're not getting into.
- If we want to include a string Lloyd, it will be placed as follows in the spaces 12-17.
[][][][][H][][][][.65.][L][l][o][y][d][\0][][].
- When talking about memory addresses we do so using hexadecimal notations so it wont be in the decimal 0-19, but rather 0x0-0x19.

## Back to pointers
* most important thing to remember:
- Pointers are nothing more than just addresses.
- Pointers are addresses to locations in memory where variables live.
- When declaring an int K for example, we are setting aside memory, like a box of memory.
> k = [].
- If we say k = 5, we are storing the value 5 into that box.
> k = [5].
- If we say int *pk, we create another box of memory.
> pk = [].
- If we say int *pk = &k, we are storing an address of k.
> pk = [0x80C74820].
- So we are sticking where k lives in memory, its address, the address of its bytes.
- That value is what we are going to put inside the box pk.
- Because these are pointers, and because looking at a string like 0x80C74820 is not very meaningful, when we visualize pointers, we actually do so as pointers. So...
- Pk gives us the information we need to find k in memory.
> k = [5] <--- pk = [0x80C74820].
- So basically pk has an arrow in it pointing to the location in memory where k lives.
- This is important because once we know where k lives, we can start to work with the data inside of that memory location.

## So what is a pointer?
- A pointer is a data item whose value is a memory address, so at [0x80C74820] (the location in memory).
- The type of a pointer describes the kind of data youll find at that location of the memory address. (int *)
- If we follow the arrow, it will lead us to a location where we will find the box int k = [5].
- Pointers allow us to pass data structures and/or variables between functions (actual variables and not copies of them).
- If we know exactly where in memory to find a variable, we dont need to make a copy of it, we can just go to that location and work with that variable.
- Pointers make a computer environment more like the real world.

### Heres an analogy
If I have a notebook and its full of notes, and I want to update it. I want you to update it, you are a function that updates notes. What happens is you will take my notebook, you'll go to the copy store, you'll make a Xerox (copy of document made by xerographic printer) copy of every page of the notebook, you'll leave my notebook back on my desk when youre done, you'll cross out things in my notebook that are out of date or wrong, and then you'll pass back to me the stack of Xerox pages that is a replica of my notebook with the changes you have made to it. At that point, it is up to me as the calling function, as the caller, to decide to take your notes and integrate them back into my notebook.
- Theres alot of steps involved here. It would be better if I could just give you my notebook and you take things and literally cross them out and update my notes in my notebook and give me my notebook back (rather than make a copy).
- This is what pointers allow us to do.

## How pointers work in C
### NULL pointer
- Simplest pointer available to us is the NULL pointer.
- This pointer point to nothing (a fact which can actually come in handy).
- Whenever you create a pointer and you dont set its value immediately, you should always set the pointer value to NULL.
- You can check whether a pointer is NULL using the eqality operator (==).

### Extraction pointer
- Another way to create a pointer is to simply extract the address of an already existing variable. We can do this with the address extraction operator (&).
- If x is an int-type variable, then &x is a pointer to an int whose value is the address of x.
- If arr is an array of doubles, then &arr[i] is a pointer to a double whose valuse is the address of the ith element of arr. 
- An arrays name, then is actually just a pointer to its first element - youve been working with pointers all alone.
- Everytime we use an array, we're workin with pointers.

#### Example on variable scope
- Near the end of the video, we were presented with an example where we have a function called set int and a function called set array. The challange was to determine wether or not, or what the values that we printed out at the end of the function, at the end of the main program. We know that when you call to set int effectively does nothing. But the call to set array does. The reason is that an arrays name is really just a pointer. Theres a special square bracket syntax that make things a lot nicer to work with making the idea of a pointer a lot less intimidating.
- Arrays are just pointers which is wy when we made a change to the array, when we passed an array as a parameter to a function or as an argument to a function, the contents of the array actually changed in both the callee and in the caller. Which for every other kind of variable we saw was not the case.
- So the name of an array is actually just a pointer to the first element of that array.

### Why care about where something lives?
- If we know where something lives that means we can go there and change it.
- The main purpose of a pointer is to allow us to modify or inspect the location to which it points.
- We do this by dereferencing the pointer.
- We go to the reference and we change the value there.
- If we have a pointer called pc and it points to a character, then we can say *pc, *pc is the name of what we will find if we go to the address pc. What we will find there is a character and *pc is how we refer to the data at that location.
- If we have a pointer to char called pc, then *pc is the data that lives at the memory address stored inside the variable pc.
- So if we say *pc = D, that means that whatever was at memory address pc, whatever character was previously there, is now D, if we say *pc = D.

### Again with pointers
- Previously we've seen * as being part of the data type.
- Used in this context, * is known as the dereference operator.
- It goes to the reference and accesses the data at that memory location, allowing you to manipulate it at will.
- This is just like visiting your neighbour. Having their address isnt enough, you need to go to their address and only then can you interact with them.
- Pointer * is used in both contexts, as part of the type name, something else that we have not done yet, and the dereference operator.
- As the dereference operator, it goes to the reference, it accesses the data at the location of the pointer, and allows you to manipulate it at will.

#### NULL pointers
- What happens if we try to dereference a pointer whose value is NULL?
> Segmentation fault.
- If set value of pointer is not set to something meaningful, we should set it to NULL.
- Segmentation fault is actually a good behaviour. It defends against accidental dangerous manipulation of unknown pointers.
- Sometimes you need to create a pointer now, but you don’t yet know what it should point to.
For example:
```
int *data = NULL;

if (condition)
{
    data = malloc(sizeof(int));  // allocate later
    *data = 42;
}
```
- Here you need to declare the pointer first — but you only assign a real address under certain conditions.
- Setting it to NULL ensures it’s in a safe and known state until then.

### Overall syntax of the situation
int *p;
- The value of p is an address.
- We can dereference p with the * operator.
- If we do, what we'll find at that location is an int.
- *'s are part of both the type name and the variable name.
int *px, py, pz;
- What we get is a pointer to an integer called px, and two integers py, and pz.
- This is not good.
- to create multiple pointers on the same line, of the same type:
int *pa, *pb, *pc;
- Its best to declare pointers on indicidual lines.

## Concept of how large is a string.
- There is no data type called string.
- String is a data type that was created for #include <.cs50.h>.
- String is just an alias for something called a char *, a pointer to a character.
- Pointers are just addresses.
- So what is the size in bytes of a string?
> 4 or 8 depending on the system.
- If using cs50 ide, char * is the size of a char * is 8, it's a 64-bit system.
- Every address in memory is 64 bits long.
- If using cs50 appliance or using any 32-bit machine, 32 bit machine means that every address in memory is 32 bits long and so is 4 bytes.
- Therefore depending on your system, a char * is either 4 or 8 bytes.
- Any data types, and a pointer to any data type, since all pointers are just addresses, are 4 or 8 bytes.

## Revisit diagram from the start
*pk = &k.
> k = [5] <--- pk = [0x80C74820].
- What happens if we say *pk = 35;?
- The * is the dereference operator, when it is used  we go to the address pointed to by pk and we change what we find.
- So *pk = 35 effectively does this to the picture
> k = [35] <--- pk = [0x80C74820].
- This is syntactically identical to of having said k = 35.
- If I say int m;, I create a new variable called m (creating a new box).
> m = [].
- If i say m = 4, I put an integer into that box.
> m = [4].
- If i say pk = &m, how does this diagram change?
- The & is the address of a variable name.
- We are saying pk gets the address of m.
- So what hapens to the diagram is that pk no longer points to k, but points to m.
k = [35].
m = [35] <---- pk = [0x80C74820].
