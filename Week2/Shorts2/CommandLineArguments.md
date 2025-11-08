## Command-line arguments
- Through int main(void) collects user inputs through in-program prompts.
- If we want the user to provide data to our program before the program starts running, we need a new form.
- To collect command line arguments from the user, we need to declare main as follows:
> int main(int argc, string argv[])
- These two special arguments enable you to know what data the user provided at the command line and how much data they provided.

## argc = argument count.
- The first parameter, argc (argument count) is an integer that indicates how many arguments were entered on the command line when the program was started.
- If you pass two arguments, argc will be 3 (program name + 2 arguments).
- Stores the number of command-line arguments the user typed when the program was executed.
- ./greedy = argc 1
- ./greedy 1024 cs50 = argc 3

## argv = argument vector.
- The second parameter, argv (argument vector), is an array of pointers to arrays of character objects.
- This array of strings stores, one string per element, the actual text the user typed at the command line when the program was executed.
- The first element of argv is always found at argv[0].
- The last element of argv is always found at argv[argc-1].
- Everything in argv is stored as a string (individual characters).
- Use A to I to convert ascii to integers.

## Properties of Command Line Arguments in C
1. They are passed to the main() function.
2. They are parameters/arguments supplied to the program when it is invoked.
3. They are used to control programs from outside instead of hard coding those values inside the code.
4. argv[argc] is a NULL pointer.
5. argv[0] holds the name of the program.
6. argv[1] points to the first command line argument and argv[argc-1] points to the last argument.
- You pass all the command line arguments separated by a space, but if the argument itself has a space, then you can pass such arguments by putting them inside double quotes "" or single quotes ''. 