Agenda :
- Variables and Operators
- Functions
- Loops
- Problem Set 1

# Variables and Operators
## Part 1 Variables and Types Input and Printing.

Example of the Phone Book:
looking for a contact or person, flipping pages, or going to middle and using a more efficient algorithm of finding that person.

How phone books comprise. What are the components of those?

Imagine that one of the variables in a phone book is called "calls". So maybe it is the number of calls that one friend called you.
Maybe they called 4 times. 
This can be imagined having this square or a little box that stores some value, in this case it is 4.

int calls = 4;
type, name, assignment operator, value;
Can be worded like,
Create an integer named calls that gets the value 4.

int x = 50;
Create an integer named x that gets the value 50.

int calls = 4;
calls = calls + 1;

Makes the calls = 5.

So say I didn't have that number of calls stored in the phone book just yet. I wanted to get it from the user.
How can we get input from the user?

int calls = get_int("Calls: ");
Prompt -> get_int -> calls
"Calls: " -> get_int -> 4

Function name = get_int
Function input = ("Calls: ");

%i %d are interchangeable.
Theyre both used for integers if we want to print them out.
%d is a little deprecated and weve veen using %i since. Default to %i.

How to print values:

int calls = 4;
printf("calls equals %i, calls);

%i is a format code, one of the options used for integers.

Types and format codes:
Numbers:
%i = int
%f = float

Text:
%c = char
%s = string

True/False:
%i = boolean


