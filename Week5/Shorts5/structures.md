# Structures
- With structures, it gives us the ability to define our own data types for our own projects.
- Structures provide a way to unify several variables of different types into a single, new variable type, which can be assigned its own type name.
- We use structures (structs) to groud together elements of a variety of data types that have a logical connection.
- Example : student, could use variables of type int for the number of studens, type char, for name fof students.
- A structure is like a super-variable.
```
struct car // introduces concept of structure using struct. Define type name with another word e.g. car.
{ // variables inside super variable.
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine size;
};
```
- Usually define structs at the top of our program near #include and #defines.
- We may also find them in a seperate .h file if using this type of definition in several different files.
- Now thatwe have created this new type, we can use it.
- We can create variables of that type using the familiar syntax. 
> e.g. struct car y; is a variable called y of the type struct car.
- We can also access the various fields (also known as members) of the structure using the dot operator (.).
```
// variable declaration
struct car mycar; // type = struct car. Variable name = mycar.

// field accessing
mycar.year = 2011;
strcpy(mycar.plate, "CS50"); // copys string into the variable mycar.
mycar.odometer = 50505;
```
- Structures, like variables of all other data types, do not need to be created on the stack. We can dynamically allocate structures at run time if our program requres it.
> E.g. If we dont know at the beginning of our program, that were going to need a certain number of these things, we can declare this on the fly dynamically using pointers.
- In order to access the fields of our structures in that situation, we dont just use the dot operator, but also we first need to dereference the pointer to the structure, and then we can access its fields.
- Instead of statically declaring a struct car called mycar, we dynamically allocate a struct car called mycar.
```
// variable declaration
struct car *mycar = malloc(sizeof(struct car));
```
- Sizeof is not just built in, it can also figure out on the fly exactly how much space is required for a struct car.
- This means we dont have to go through and figure out how much bytes we need, the computer does it for us.
- So, struct car *mycar = malloc(sizeof(struct car));, dynamically allocates on the heap one chunk of memory large enough to hold a single struct car within it.
- Then we can access the fields by first dereferencing the pointer, then using the dot operator to access the fields.
```
// variable declaration
struct car *mycar = malloc(sizeof(struct car));

// field accessing
(*mycar).year = 2011;
strcpy((*mycar).plate, "CS50");
(*mycar).odometer = 50505;
```
- This syntax although works, is cumbersome.
- We can do this an easier way:
- The arrow operator (->) makes this process easier. 
- It does two things back to back:
1. dereferences the pointer on the left side of the operator.
2. accesses the field on the right side of the operator.
```
// variable declaration
struct car *mycar = malloc(sizeof(struct car));

// field accessing
mycar->year = 2011;
strcpy(mycar->plate, "CS50");
mycar->odometer = 50505;
```
- The arrow operator is great to have a shorthand for accessing the field of a structure to which you only have a pointer.
- This will be used ALOT, therefore BEFRIEND it.