# Call Stacks
- The way functions are called and operated in C is called a call stack.

## How it works:
- When you call a function, the system sets aside space in memory for that function to do its necessary work.
- We frequently call such chuncks of memory stack frames or function frames.
- More than one functions stack frame may exist in memory at a given time. if main() calls move(), which then calls direction(), all three functions have open frames.
- But in general, only one of those frames will ever be active, only one function will be running at a given time even though all three of them have space set aside and are sort of hanging out, waiting to do something.

- These frames are arranged in a stack. The frame for te most recent called function is always on the top of the stack. -> This is called the active frame.
- When a new function is called, a new frame is pushed onto the top of the stack and becomes the active frame.
- When a function finishes its work, its frame is popped off of the stack, and the frame immediatly below it becomes the new, aactive, function on the top of the stack. This function picks up immediatly where it left off.

- This is why recursion works, because all of these frames are running, but only one of them is moving at a given time. The rest of them are all running but theyre on pause, waiting to become the new top of the stack again.

- If we call another function, the active frame goes on pause again, the function that was just called is put on top and so on and so on until all the function frames are finished.

### Example of recursion
- Using the factorial function to see if we can make this more clear.

> int fact(int n)
> {
>   if (n == 1)
>       return 1;
>   else
>       return n * fact(n-1);
> }
>
> int main(void)
> {
>   printf("%i\n", fact(5));
> }

- Start at beggining of main which calls another function printf.
- As soon as it does that, main is on pause and is waiting for printf() to do its work.
- Printf has to print out an integer but it has to print out factorial of 5. But it doesnt know factorial of 5, it has to make a function call.
- So then printf goes on pause and waits for factorial of 5 which then becomes the new active frame.
- Because n does not == 1, it returns n * fact(n-1).
- Then it calls a new function passing in 4 as the parameter instead.
- fact(5) goes on pause and a frame for factorial 4 becomes the new active frame.
- 4 != 1 so it returns n * fact(n-1).
- Another function call passing in 3 as the parameter instead.
- This process repeats until its fact(1).
- When it reaches fact(1), there are 7 function frames in the call stack.
- Factorial 2, 3, 4, 5, printf() and main are all on pause at the lines.
- After all the calls it asks is fact(1) == 1? In this case the answer is yes, it is going to return 1.
- When a function returns a value, that frame is done and goes away, meaning it gets popped back off of the call stack.
- Then the frame below it becomes the new active frame.

> [fact(1)] -> returns 1.
- Gets popped off the stack/destroyed and moves onto the next.
> [fact(2)] -> becomes new active frame. Gets unpaused and returns 2 * 1 = 2.
- Gets popped off the stack/destroyed and moves onto the next.
> [fact(3)] -> becomes new active frame. Gets unpaused and returns 3 * 2 = 6.
- Gets popped off the stack/destroyed and moves onto the next.
> [fact(4)] -> becomes new active frame. Gets unpaused and returns 4 * 6 = 24.
- Gets popped off the stack/destroyed and moves onto the next.
> [fact(5)] -> becomes new active frame. Gets unpaused and returns  5 * 24 = 120.
- Gets popped off the stack/destroyed and moves onto the next.
> [printf()] -> becomes new active frame. Prints out 120.
- Gets popped off the stack/destroyed and moves onto the next.
> [main()] -> all functions are finished so gets popped off the stack.

- Program is completed its job by printing out 120.


