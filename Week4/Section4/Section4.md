# Memory
- In week 1 we talked about phonebooks.
> int calls = 4;
Varbiable = int calls. Type = int. Name = calls. Value = 3.
- Imagine it as a box = calls [4].
- Each variable has an address = calls [4] 0x1A.
- Using this address, we can now create a pointer.
> int *p = 0x1A.
- p [0x1A].
- variable p will also have an address = p [0x1A] 0xF0. 
> &calls; = address of calls is 0x1A.
> &p; = address of p is 0xF0.
- How do p and calls combine?
- *p; "go to the value at address stored in p". p [0x1A] calls [4] 0x1A.
- type * is a pointer that stores the address of a type.
- char * is a string.
- *x takes a pointer x and goes to the address stored in that pointer.
- &x takes x and gets its address.

## Pointers
### Example 1
Visualising the pointer.
> int x = 4;
> int *p = &x;
> printf("%i\n", *p);
- This can be imagined like:
```
x
[4]
0x123

p
[0x123]
```
Terminal: 4.

### Example 2
Changing the value of pointer.
> int x = 4;
> int *p = &x;
> printf("%i\n", *p);
> *p = 2;
- This can be imagined like:
```
x
[2]
0x123

p
[0x123]
```
Terminal: 4.

### Example 3
Playing around with the pointer.
> int x = 4;
> int *p = &x;
> printf("%i\n", *p);
> *p = 2;
> printf("%i\n", *p - 2);
- This can be imagined like:
```
x
[2]
0x123

p
[0x123]
```
Terminal: 40.

### Example 4
Playing around with the pointer.
> int x = 4;
> int *p = &x;
> printf("%i\n", *p);
> *p = 2;
> printf("%i\n", *p - 2);
> printf("%i\n", x);
- This can be imagined like:
```
x
[2]
0x123

p
[0x123]
```
Terminal: 402.

## File I/O
**fopen**
- opens a file for future reading/writing.

**fclose**
- closes a file.
- Must be closed after fopen.

#### Example
```
hi.txt
[hi]
0x456
```
How to read/write into this file?
> FILE *input = fopen("hi.txt", "r");
“Declare a pointer named input to a FILE object, open the file hi.txt in read mode, and store the resulting file pointer in input.”
1. type = FILE
- Data type that holds infomation on open file
2. name of variable = input *
- Input is a pointer to a FILE structure. It will point to a memory location that stores file-related info once the file is opened.
3. value = fopen("hi.txt", "r");
- fopen opens a file, taking 2 arguments.
- hi.txt = name of the file to open
- r = read the file

**fread**
- reads data from a file into a buffer.

**fwrite**
- writes data from a buffer to a file.

**Buffer**
- A buffer is a chunk of memory that can temporarily store some data from the file.
### Fread()
> fread(buffer, 1, 4, input);
“Read 4 bytes from the file input into the memory area pointed to by buffer.”
- fread() returns the number of elements successfully read (not bytes).
- buffer (ptr) = Destination pointer > Data read from the file will be stored starting here.
- 1	(size) = Size of each element > Each element is 1 byte in size. If unsure of size you can use sizeof() function
- 4 (count) = Number of elements want to read > It will read 4 such bytes (total of 4 bytes).
- input (stream) = File stream > File pointer location to read from.
- So it will grab 4 bytes from input file (hi.txt) and store it in the buffer variable.
- Because we know we want to read 4 bytes, we can preallocate that memory and have the buffer be ready to accept those bytes.

**This is how we can visualise it**
Function?
- fread.
To where?
- Into buffer.
How many blocks and what size?
- 4 blocks of size 1.
From where?
- From the input file.

**Why are we using buffer in the first place?**
- Instead of taking input and allocating it straight to output, we use buffer as a temporary variable. Often we dont know where the data ends, so to ensure were only using a few bytes at a time until we reach the end, we use buffer.

### fwrite()
> fwrite(buffer, 1, 4, output);
“Write 4 bytes from buffer into the file output.”
- fwrite() returns the number of elements successfully written (not bytes).
- buffer = Source pointer > Data will be written from this memory location.
- 1 = Size of each element > Each element is 1 byte.
- 4 = Number of elements > It will write 4 bytes total.
- output = File stream > File to which the data will be written.
- We are basically copying elements from the buffer to the output file.

**This is how we can visualise it**
- Flipping it compared to fread.
Function?
- fwrite.
From where?
- From buffer.
How many blocks and what size?
- 4 blocks of size 1.
To where?
- From the output file.

#### File reading excersize
Create a program, pdf.c, that checks whether a file, passed in as a command-line argument, is a PDF. All PDFs will begin with a four byte sequence: 0x25, 0x50, 0x44, 0x46.
- For example ./pdf test.pdf should print "yes", while ./pdf test.jpg should print "no".
- All PDFs begin with a 4 byte sequence.

```
#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[]) // By defining this line we can accept CLA.
{
    // check for usage, must be 2 CLA
    if (argc != 2) // If there are more or less than 2 command line arguments, fail the program. Otherwise continue.
    {
        printf("Please provide only one filename.\n");
        return 1; // Exit error. incorrect usage.
    }

    // open file
    FILE *input = fopen(argv[1], "r"); // We want to get the first CLA from user and read the file given to grab the information.

    // create buffer for file
    uint8_t buffer[4]; // buffer is the variable name, [4] is defining that we will have 4 cells in our array, uint8_t is a size of byte which is an unsigned int. Making sure we have non negative values. Making sure it is exactly one byte.

    // create an array of signature bytes
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46}; // Creating another array to store signature bytes to help identify if it is a PDF. It is the 4 bytes that are containted in the beginning of each PDF, so by comparing what it will actually read from the file, we will be able to identify that.

    // read first 4 bytes from the file
    fread(buffer, sizeof(uint8_t), 4, input); Can use sizeof instead of 1.

    // check the first 4 bytes again signature bytes.
    for (int i = 0; i < 4; i++) // Create a loop comparing 1 byte at a time
    {
        if (signature[i] != buffer[i]) // indexing through signature, if it is not equal to buffer, go through loop.
        {
            printf("Not a PDF.\n"); // Quit if it doesnt match up.
            return 0; // Exit success. Programm ran successfully, but file is not PDF.
        }
    }

    // success!
    printf("IT is a PDF\n");

    // close the file
    fclose(input);

    return 0; // Exit successful. Tells programm were done.
}
```

