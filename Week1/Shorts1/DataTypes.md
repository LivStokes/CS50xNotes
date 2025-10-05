# Data Types
Need to specify every data type we use.
5 primary types encountered in C.

- int
The int data type is used for variables that will store integers.

Integers always take up 4 bytes of memory (32 bits). This means the range of values they can store is necessarily limited to 32 bits worth of information.

Ranges from -2power31 - 2power31-1
Half negative half positive.

- unsigned int
unsigned is a qualifier that can be applied to certain types (including int), which effectively doubles the positive range of variables of that type, at the cost of disallowing any negative values.

- char
Char data type used for variables that will store single characters.

Characters always take up to 1 byte of memory (8 bits). This means the range of values they can store is necessarily limited to 8 bits worth of information.

ASCII is a mapping of characters like A, B, C etc, to numeric values in the positive side of the range.

A = 65
a = 97


- float
The float data type is used for variables that will store floating-point values, also known as real numbers. - takes up 4 bytes memory (32 bits)

Range of float is complicated - suffice to say with 32 bits of precision, some of which might be used for an integer part but limited to how precicse we can be.

- double
used for variables that will store floating-point values, also known as real numbers.

The difference is that doubles are double precision. They always take up 8 bytes of memory (64 bits). With an additional 32 bits of precision relative to a float, doubles allow us to be specify much more precise real numbers.

- void
is a type, not a data type.
Functions can hvae a void return type, which means they dont return a value.
The parameter list of a function can also be void meaning the function takes no parameters.
Void is like a placeholder for "nothing".

Other data types:

- bool
used for variables that will store a boolean value. Capable of storing one of two values, true and false.

-string
Used for variables that store a series of characters, which programmers typically call a string.
Strings include things such as words, sentences, paragraphs and so on.

structs - structures
tyoedefs - defined types
These afford great flexibility in creating data types that you need for your programs.

How to create, manipulate, and otherwise work with variables using these data types.

Creating a variable:
To bring a variable into existence. you need to specify the dara type of the variable and give it a name:
int number;
char letter;
If you wish to create multiple of the same type, you specify the type name once, and then list as many variables of that type as you want:
int height, width;
float sqrt2, sqrt3, pi;
Only declare variables when you need them.






