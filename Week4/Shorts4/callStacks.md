# Call Stacks
- When looking back to recursion, we wonder how does a function know to wait for another function? How does it pass its data to some other thing thats running at the same time?
- The way they operate is using something called the call stack.
- The call stack works by calling a function, which a big chunk of memory gets set aside somehwere in the system for that function to do its work.
- We call such chunks of memory **stack frames** or **function frames**.
- more than one functions stack frame may exist in memory at a given time.
- If main() calls more(), which then calls direction(), all three of these functions have open frameworks. BUT only one of those frames will be active at the given time.
- These frames are arranged in a stack. The frame for the most recently called function is always on the top of the stack.
- When a new function is called, a new frame is pushed onto the top of the stack and becomes the active frame.
- When a function finishes its work, its frame is popped off of the stack, and the frame immediatly below becomes the new, active, function on the top of the stack. This function picks up immediatly where it left off.


## Example using the factorial function 
```
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}

int main(void)
{
    printf("%i\n", fact(5));
}
```
1. Main function is called.
- It calls the printf function.
- Main goes on pause.
2. Printf function is called.
- It calls the fact() function.
- Printf goes on pause.
- Checks if n != 1.
- Prints fact(5)
3. Fact(5) frame is calling a new function.
- Checks if n != 1.
- Fact(4) gets printed.
- Continiues until fact(1).
4. When fact(1) is called, there are 7 function frames in the call stack.
> [fact(1)] 
> [fact(2)]
> [fact(3)]
> [fact(4)]
> [fact(5)]
> [printf()]
> [main()]
- When function returns the value that function is done and it gets popped back off the call stack and the function below it becomes the new active frame.

# Look At callStacks From Shorts 3!