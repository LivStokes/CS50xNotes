# File Pointers
- A file is a structure that saves programes to your computers memory. This gives it consistent information.
- File pointers gives us the ability to read data from and write data to files. It is the primary means of storying persistent data, data that does not disappear when your program stops running.
- The abstraction of files that C provides is implemented in a data structure known as a FILE.
- When working with files, we will be using pointers to them, FILE*.
- The file manipulation funcitons all live in stdio.h.
- All of them accept FILE* as one of their parameters, except for the function fopen(), which is used to get a file pointer in the first place.
- Some of the most commmon file input/output (I/O) functions that we'll be working with are:
fopen(), fclose(), fgetc(), fputc(), fread(), fwrite().

## fopen()
- Opens a file and returns a file pointer to it.
- You can use this as an argument to any of the other file I/O functions.
- Always check the return value to make sure you dont get back NULL.
> FILE *ptr = fopen(<filename>, <operation>);
Example:
> FILE *ptr1 = fopen("file1.txt", "r");
r = reads information from file1.txt.
> FILE *ptr2 = fopen("file2.txt", "w");
w = write function to pass ptr2 as an argument to any function that writes information to a file. This overwrites an already existing file.
> FILE *ptr3 = fopen("file3.txt", "a");
a = append which is similar to writing, but does not overwrite, it will go to the end of the file and it will start writing from there.

## fclose()
- Closes the file pointed to by the given file pointer.
- Once it closes the file, we cant perform anymore file I/O functions, unless we reopen the file.
> fclose(<file pointer>);
> fclose(ptr1);

## fgetc()
(file get character)
- Reads and returns the next character from the file pointed to.
- The operation of the file pointer paassed in as a paramenter must be "r" for read, or you will suffer an error.
> char ch = fgetc(<file pointer>);
> char ch = fgetc(ptr1);

- The ability to get single characters from files, if wrapped in a loop, means we could read all the characters from a file anf print them to the screen, one by one, essentially.
```
char ch;
while((ch = fget(ptr)) != EOF)
    printf("%c", ch);
```
- We might put this in a file caled cat.c, after the Linux command "cat" which essentially does just this.

