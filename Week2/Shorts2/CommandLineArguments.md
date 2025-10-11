## Command-line arguments

through int main(void) collects user inputs through in-program prompts.
If we want the user to provide data to our program before the program starts running, we need a new form.

To collect command line arguments from the user, we need to declare main as follows:
int main(int argc, string argv[])

These two special arguments enable you to know what data the user provided at the command line and how much data they provided.

argc = argument count.
Stores the number of command-line arguments the user typed when the program was executed.
./greedy = argc 1
./greedy 1024 cs50 = argc 3

argv = argument vector.
This array of strings stores, one string per element, the actual text the user typed at the command line when the program was executed.
The first element of argv is always found at argv[0].
The last element of argv is always found at argv[argc-1].
Everything in argv is stored as a string (individual characters).
Use A to I to convery ascii to integers.