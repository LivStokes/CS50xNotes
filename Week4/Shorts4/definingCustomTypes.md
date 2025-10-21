# Defining Custom types
- We have the ability to define out own data types with structs.
- If we use structures, sometimes using those data types can be cumborsome because we have to use the struct keyword when were working with them.
E.g. Struct car, struct person.
- To work with ints and chars, we can use typedef.
- typedef provides a way to create a shorthand or rewritten name for data types.
- The basic idea is to first define a type in the normal way, then alias it to something else.
> typedef <oldname> <newname>;
- So we could typedef for example, the already existing datatype of unsigned char as byte.
> typedef unsigned char byte;
- Then, from now on after we've made this type definition which is usually going to be at the top of our .c files, or in a .h file seperatly, We can just use byte everywhere we would have used unsigned char which is alot shorter to type.
- In Cs50 they do this:
> typedef char * string;
They abstracted away the idea of pointers, and the fact that a string is really a pointer to the first character of an array of characters, because its just so confusing to get your head around that, but thats what they do.
- That line of code actually exists in cs50.h
> typedef char * string;.
- Typedef becomes great when combined with structures.
- Structures have a two-word type name, and so they can be annoying to create variables of that type or malloc of struct something, lines can get long.
- we can use typedef to come up with something a lot shorter.
E.g.
```
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};

typedef struct car car_t;
```
- So we define a car in struct car.
- Inside curly braces is the fied definitions.
- Then we typedef struct car car_t
- This means that everytime we would hae used struct car, we can use car_t.

- Alternatively, because structures are so commonly used in typedef, we can define the type in between the start and the end.
```
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
} car car_t;
```
- When we use this in code, 
```
// variable declaration
struct car mycar;

// field accessing
mycar.year = 2011;
strcpy(mycar.plate, "CS50");
mycar.odometer = 50505;
```
But instead now we can use 
```
// variable declaration 
car_t mycar;
```