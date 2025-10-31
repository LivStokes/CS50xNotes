# Dynamid Memory Allocation
How do we get access to new memory while our program is running?
- In cases where we ask users to give us a number, and they generate a hundered linked list object, so 100+ of something and we dont know that. We cant predict this in advance.
- So we need to create new memory in our program while the program is already running.
## Dynamically allocated memory (heap) Statically allocated memory(stack).
- We need to use dynamic memory alocation in order to know how much memory were using.
- We can use pointers to get access to a block of dynamically allocated memory at runtime.
- Dynamically allocated memory comes from a pool of memory known as the heap.
- Anything you create dynamically while your program is running comes from the heap.
- Prior to this point, all memory we've been working with has been coming from a pool of memory known as the stack.
- Staticlly allocated memory comes from the stack.
```
text
-
initialized data
- 
uninitialized data
-
heap
...
...
stack
-
environment variables
```

- The stack and the heap are the same big chunk of memory.
- The stack we allocate from the bottom to the top.
- The stack memorys addresses will be a bit lower numbers.
- The heap we allocate from top to bottom.
- The heap memorys addresses will be a bit higher.
- It is really one giant pool of memory but we call it two different things depending on how its being used.
- The stack for statically declared memory grows up and the heap for dynamically allocated memory grows down.
- How do we get at this dynamically allocated memory? / How do we access memory on the heap?

## Malloc
- We need to use a new function called malloc.
- You can get malloc by #include <stdlib.h>.
- The only argument you need to pass to malloc is how many bytes of memory that you want.
- We get this dynamically-allocated memory by making a call to the C standard library function malloc(), by passing as its parameter the number of bytes requested.
- If you want an integer, you say malloc 4, if you want a character, you say malloc 1, if you want a double you say malloc 8 etc.
- What malloc will then do is try find some chunk of memory, the size that you asked for on the heap.
- So it'll go and try and find 8 contiguous bytes of memory (double) from the heap.
- After obtaining memory for you (if it can), malloc() will return a pointer to that memory.
- The only way we can access/use dynammically allocated memory is by dereferencing the pointer that we get back from malloc.
- What if malloc() cant give you memory? It'll hand you back NULL.
- First rule about dynamically allocatd memory is to always check for NULL after malloc.
How to statically declare an integer:
> int x; 
- this creates a variable called x on the stack.
How to dynamically allocate an integer:
> int *px = malloc(4); // 4 is because 4 bytes in an int. 
- Or we can use size of
> int *px = malloc(sizeof(int)); // Pass it a type and it returns how many bytes that type takes up on the system.
- This means malloc will find the size of the type of memory that are next to eachother on the heap.
- Malloc will return a pointer to that memory called px, then we can dereference that pointer.

### example of statically vs dynamically allocated memory
- We want to get an integer from the user.
> int x = get_int();
- We want to declare an array of that many floats on the **stack**.
> float stack_array[x];
- We want to declare an array on that many floats on the **heap**.
> float *heap_array = malloc(sizeof(x * float));
- If i want 50 floats, we need 50 times the size of a float.
- Malloc returns to us a giant block of memory that size, which we can then treat like any other array.

## Catches with dynamically allocated memory
- Dynamicallt allocated memory is not automaticallt returned to the system for later use when the function in which its created finishes execusion.
- Failing to return memory back to the system when youre finished with it results in a memory leak which can compromise your systems performance.
- When a function finishes running, all the memory that was created for purposes of that memory gets destroyed and released back into the system to be used somewhere else.
- When you finish working with dynamically allocated memory, you must **free()** it.
- If you dont free it, you get a memory leak which can slow downyour system.
- There are some browsers that are notorious for not freing memory which can cause your computer to slow down because that browser is basically hogging a bunch on memory and other programs on your computer cant use the memory because the browser has allocated it and said "its mine".
- Thats why if you leave a browser open for days it can slow down your computer.
- So the rule is when working with dynamically allocated memory is that you must free it.
- When you free() memory, what you passed to free is a pointer to any memory that you have dynamically allocated previously.
- Its bascially telling the system that im done, you can use this memory for whatever you like.

### Another example
- We want to malloc a 50 character long array called word, we dynamically allocate it.
> char *word = malloc(50 * sizeof(char));
- Then we do stuff with word, maybe we are in the middle of a function, changing its value, or assigning new characters, or were printing it out for example.
- Then when we decide we're done with it, we release it back into the system
> char *word = malloc(50 * sizeof(char));
// do stuff with word

// now were done working with that block
> free (word);

## Golden rules
- There are three basic rules.
1. Every block of memory that you malloc() must subsequently be free()d.
2. Only memory that you malloc() should be free()d.
3. Do not free() a block of memory more than once. This causes an inverse memory leak.

## Another example
- Visual example of whats happening as we do it.
1. Statically declare an integer called m.
> int m;
2. Statically declare a pointer called a.
> int *a;
> int *b = malloc(sizeof(int));
- We have something called b that im giving a name to. Were asking malloc to dynamically give me 1 int worth of space. 
- Not giving a name to what the int b is pointing to is how i know its not a statically declared integer.
- The only way i can refer to the unknown integer is by dereferencing the pointer called b.
- So b has a name and thats statically declared. But I dereference b in order to get to this dynamically allocated memory.
- first thing to do after this is to check that b is not NULL.
- Then we say 
> a = &m;
- This means a points to m.
> a = b;
- If we say this, we now have a and b pointing to the same location.
- So instead of pointing to m, a is now pointing to the dynamically allocated unnamed int.
- Now we can reference it multiple ways like *a or *b because both of those same statically declared variables point to the same location.
- Then we can say:
> m = 10;
- We can do this because 10 is statically declared, it is a box that has a name.
> *b = m + 2;
- m = 10, so 10 + 2 = 12
- When we say *b, we are dereferencing b.
- So what this does is putting 12 into where b points to which is the unnamed int location.
> free(b);
- This tells the system we are done working with this integer and it can take the bytes back and use it for something else.
- This unnamed int box no longer has 12 in it and so we cant use it anymore.
- If we say this:
> *a = 11;
- We will get unpredictable behaviour.
- Once we free memory, we are telling the system that we dont need it anymore, so if we try use it again, we will have bad things happen.