# Variable scope
- Scope is a characteristic of a variable that defines from which functions that variable may be accessed.
## 2 primary scopes in C:
1. Local Variables
Can only be accessed within the functions in which they are created.
2. Global Variables
Can only be accessed by any function in the program.

- In this course, only be using local variables.
```
int main(void)
{
    int result = triple(5);
}

int triple(int x)
{
    return x * 3;
}
```
- Here, x is local to the function triple(). No other function can refer to that variable, not even main(). 
- Result is local to main().
- Global functions is where a variable is declared outside of all functions, any function may refer to it.
```
#include <stdio.h>

float global = 0.5050;

int main(void)
{
    triple();
    printf(%f\n", global);
}

void triple(void)
{
    global *= 3;
}
```
- Can have dangerous, theyre flexible in being able to pass information around so that every function can use it. 
- If one function changes the value of a variable,before expectt it to be changed.

Why does this matter?
- Local variables are passed by value in function calls.
- When a variable is passed by value, the callee (function that is recieving the variable that gets passed as an input) recieves a copy of the passed variable, not the variable itself.
- That means that the variable in the caller is unchanged unless overwritten.

No effect on foo (not changed):
```
int main(void)
{
    int foo = 4;
    triple(foo);
}

int triple(int x)
{
    return x *= 3;
}
```
Has effect (overwrites foo)
```
int main(void)
{
    int foo = 4;
    foo = triple(foo); // Overwriting foo (triple gets its own copy of foo.)
}

int triple(int x)
{
    return x *= 3;
}
```
// NEEDS COMPLETION
