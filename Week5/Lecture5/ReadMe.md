# Data structures
- A way of structuring data in the computers memory.
- For example we looked at arrays, which is a simple data structure. Where each element in the array has to be of the same data type, going back to back to back. The catch is we have to decide in advance how big the array is going to be.

## Stacks and Queues.
- The world is filled with abstract data types whereby these ways of structuring information, but that dont depend on the underlying implementation details. That is to say you can implement certain features in life, in code, but theres different ways to implement them in lower level wether arrays or other data structures.
- Data structures are concrete, involving variables, pointers, function.
- Abstract data types are more broadly descriptive.

### Queues
- There are **queues**.
- In the real world its like lining up for a cinema, its an ordering.
- In the virtual world we have it as well such as when printing a bunch of things of things to a printer, those documents are stored in a que so they print in that precise order.
- It is an example of a FIFO data type - First In First Out.

Two functions of FIFO:
> enqueue.
> dequeue.

How to make this in code:
- We want a queue of 50 people in total, making it a const int. We can create our own structure, using typedef, that includes amount of people [CAPACITY], in an array called people, each one is of type person. we can encapsulate data types inside of datatypes, even if youve made both yourself. Inside of the new struct named queue, we have int size. Capactity and size are very distinct here. Capacity is and always will be 50. Size is going to be the current number of people or things in the queue. We have to keep track of both otherwise we could have 50 garbage values in memory.
```
const int CAPACITY = 50;

typedef struct
{
    person people[CAPACITY];
    int size;
} queue;
```
### Stacks
- There are also **stacks**.
- It is an example of a LIFO data type - Last In First Out.

Two functions of LIFO:
> push.
> pop.

```
const int CAPACITY = 50;

typedef struct
{
    person people[CAPACITY];
    int size;
} stack;
```

## Resizing Arrays
- A pointer is to kind of stitich together a computers memory with any structure we want.
- Arrays had this key property that everything was contiguous, back to back.
- For instance if we wanted to store 3 ints in memory they would be back to back [1][2][3]. The catch with the rzor call is we would have to determine how big the thing is going to be.
- We could decide in advance how big an array size is but later we realize we want another size, we could run into an issue. 
- To insert another value, instead of jumping to a free location and putting it there in constant time, we have to incure linear time to copy the original array into a slightly bigger array and then add that new value, which is waisting time.
- There is always a trade off in code.
- We could structure our data more intellegently.
- We can treat the memory like a canvas.
- In such, we can connect the locations in memory that are available so we no longer need to care if our data is back to back in memory.
- All we need for this is some familiar syntax:
1. struct
2. .
3. *
4. -> (new). This is the exact same thing as using a period and a star together.
- Using these, we can build anything we want structurally.
- How can we go about implementing an alternative to arrasys that allow us to grow or shrink them without having to remove everything that already exists in memory around.
**array**

```
#include <stdio.h>

int main(void)
{
    int list[3];

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}
```
This prints out 1 2 3 in terminal.
**malloc**
- What would be involved if we are using arrays alone to grow and shrink this array.
- We want to add a 4th array?
- We can use malloc for this.
```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // If an array is just a sequence of values contiguous in memory, and malloc is just a function that gives you a chunk of contiguous memory, we can use malloc to give us this memory and treat the first part of it as space for an int, second for space for another int, and third for a space for another int.
    if (list == NULL) // If no memory available for list, return NULL.
    {
        return 1; // error, exits program.
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes, need more space to allocate more space for 4th int.
    int *tmp = malloc(4 * sizeof(int)); // reallocate a new array thats a little bigger.
    if (tmp == NULL) // checking that nothing goes wrong.
    {
        free(list); // if no valid return, must free.
        return 1;
    }

    // copy everything from old array into the new array.
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i]; // put into the tmp array at location i, what ever is in the original array at location i. Similar to string copy.
    }
    // if i want to add a 4th number to this array:
    tmp[3] = 4;

    free(list); // free malloc of original array.

    list = tmp; // keep new chunk of memory. this renames new chunk of memory.

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Time passes
    free(list); // free the new list.
    return 0;
}
```
**realloc**
- Another way of condensing this is by the use of realloc()
- Realloc takes 2 arguments.
```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // If an array is just a sequence of values contiguous in memory, and malloc is just a function that gives you a chunk of contiguous memory, we can use malloc to give us this memory and treat the first part of it as space for an int, second for space for another int, and third for a space for another int.
    if (list == NULL) // If no memory available for list, return NULL.
    {
        return 1; // error, exits program.
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes, need more space to allocate more space for 4th int.
    int *tmp = realloc(list, 4 * sizeof(int)); // instead or allocating new array of size 4, we can realloc to reallocate for me. If there is more memory back to back, it will give more memory to the right of that memory instead of a whole new memory.
    // In order for realloc to work, we need to tell it the address of the original chunk of memory.
    // Malloc takes two arguments, realloc takes 2, the first being the address.
    if (tmp == NULL) // checking that nothing goes wrong.
    {
        free(list); // if no valid return, must free.
        return 1;
    }

    // if i want to add a 4th number to this array:
    tmp[3] = 4;

    free(list); // free malloc of original array.

    list = tmp; // keep new chunk of memory. this renames new chunk of memory.

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Time passes
    free(list); // free the new list.
    return 0;
}
```

## Linked Lists
- A list where youre using pointers to link things together in the computers memory.
E.g. 
- 1 is stored at 0x123.
- We want to store another value of 2.
- The space 0x124, 0x125, 0x126 is being used.
- So we plop 2 down at 0x456.
- We want to store another value of 3.
- So we plop 3 down at 0x789.
- These three ints are not contiguous in memory.
- If we can connect them by pointing one to the other, we can stitch together a data structure in the computers memory.
- For every int in the list, we can also allocate a pointer, so each one can point to another location.
- 1[0x123] can point to 0x456, 2[0x456] can point to 0x789, as 3[0x789] is the last in the list, we need a sentinel value, NUL, 0x0.
- We have therefore stitched up the values in memory.
- We can think of pointers as just pointing from one location to another.
- We can abstract this way and get rid of all of that, and use basic arrows instead.
- How do we keep track of a linked list of numbers, is to store numbers themselves wherever theres space in memory. We use extra pointers associated with each of those numbers to link us from one to the other.
- The linked list itself, has to spend one final pointer that keeps track of where the start of or the so-called head of the list begins in memory.
- The problem solved is that we no longer need to have things contiguous, back to back in memory.
- This means we can make much more efficient use of memory because we dont need a huge chunk of memory to be availaible all contiguously in memory.
- There is a downside to this:
- It uses twice as much space. But gaining flexibility. Therefore it is a tradeoff.

### Simplest code
```
typedef struct
{
    char *name;
    char *number;
} person;
```
- This allowed us using struct and typedef together, to create a new structure in memory that encapsulated information we cared about, like a persons name and number.

**node**
- A new term of art is called nodes.
- This is a container for data in memory.
- node is common in graphs and other types of structures.
- It is like a generic rectangle that stores some stuff for us.
- What can we put inside of this data structure in C to implement the concept of a rectangle with both a number and a pointer to another number.

- we can say:
```
typedef struct
{
    int number; // inside every node rectangle aka node will be an int called number. 
    node *next; // stores a pointer called next that points to another node. node * is the same idea as char *, but instead of pointing to the address of a character, this variable next is going to point to the address of another node.
} node;
```
- Although, we cant use the word node in node *next because it only technically exists once we get to the final line of code.
- So we must add the word node to the typedef struct
```
typedef struct node // this changes, so need to change in function
{
    int number;
    struct node *next; // change this to struct node *next.
} node;
```
- This creates a definition for those rectangles.
- How can we use these?

```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // If an array is just a sequence of values contiguous in memory, and malloc is just a function that gives you a chunk of contiguous memory, we can use malloc to give us this memory and treat the first part of it as space for an int, second for space for another int, and third for a space for another int.
    if (list == NULL) // If no memory available for list, return NULL.
    {
        return 1; // error, exits program.
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes, need more space to allocate more space for 4th int.
    int *tmp = realloc(list, 4 * sizeof(int)); // instead or allocating new array of size 4, we can realloc to reallocate for me. If there is more memory back to back, it will give more memory to the right of that memory instead of a whole new memory.
    // In order for realloc to work, we need to tell it the address of the original chunk of memory.
    // Malloc takes two arguments, realloc takes 2, the first being the address.
    if (tmp == NULL) // checking that nothing goes wrong.
    {
        free(list); // if no valid return, must free.
        return 1;
    }

    // if i want to add a 4th number to this array:
    tmp[3] = 4;

    free(list); // free malloc of original array.

    list = tmp; // keep new chunk of memory. this renames new chunk of memory.

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Time passes
    free(list); // free the new list.
    return 0;
}
```
This can be arranged to:
```
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

// creating a linked list
int main(void)
{
    node *list = NULL; // we created pointer of type node * called list and initialize it to NULL because there is no list of numbers yet, so there is no garbage value. This means we have created the pointer at far left.

    for (int i = 0; i < 3; i++)
    { // We want to use malloc to create a node and put a number there, and do it again for another node and put a number in there, and a third time and put a number in there, and then somehow stitch these together.
        node *n = malloc(sizeof(node));  // create pointer called n, send to return value of malloc, where we have enough memory to fit a node. malloc returns address of a chunk of memory. Hence we must assign it to a pointer. This chunk of memory represents a node. We want a memory for a node, not a string.
        if (n == NULL) // memory check
        {
            return 1; // signifies error
        }
        // (*n).number = get_int("Number: ");// *n goes to the address of the chunk of memory. We want to access the number field so we say *n.number. Because of order of operations, we need to make it clear that we want to go to the adderss first (*n), then go inside that chunk of memory and set the number to wahtever user types.
        //(*n).next = NULL; // changing next field to be some safe value that i know about like NULL.
        n->number = get_int("Number: ");
        n->next = list; // take new node, follow its arrow, and change it to its next field to be whatever the list is currently pointing at.

        list = n; // this connects the list together.
    }
    node *ptr = list; // this creates another variable to point at the start of the list
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; // setting ptr to the next in a while loop.
    }
}
```
- instead of (*n).number = get_int("Number: ");, we can use n->number = 1;
- What we have done here leads to the discussion of the running time speed:
- To search a linked list is O(n).
- Start at head of list, search from left to right if sorted or not.
- With the process of insertion, adding a node, adding a node, adding a node, this would be O(1).
- This is because the beggining of the list is perfectly accessible to me, no matter how long it gets, the start is always infront of me with that list variable. 
- O(1) means constant time.
- So... we have a variable list, we insert the number 1, which took 1 step.
- We insert the 2, which has no dependency on how long the list already is, because were prepending it to the list.
- And then the number 3, were prepending it to the list.
- So even if the list gets longer and longer, theres no reason for us to search it from left to right.
- Therefore, the upside of this algorithm of prepending elements is that we can achieve O(n) for searching, and O(1) for inserting.
- The catch is that things end up backwards if we care about the order in which we insert them.
- We created a LIFO structure instead of a FIFO structure.
- How do we work around this? Instead of prepending we can append.
- Once we build the list with the first node, we put it down, then the second node, then the third node.
- We can maintain sorted order.
```
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

// creating a linked list
int main(void)
{
    node *list = NULL; // we created pointer of type node * called list and initialize it to NULL because there is no list of numbers yet, so there is no garbage value. This means we have created the pointer at far left.

    for (int i = 0; i < 3; i++)
    { // We want to use malloc to create a node and put a number there, and do it again for another node and put a number in there, and a third time and put a number in there, and then somehow stitch these together.
        node *n = malloc(sizeof(node));  // create pointer called n, send to return value of malloc, where we have enough memory to fit a node. malloc returns address of a chunk of memory. Hence we must assign it to a pointer. This chunk of memory represents a node. We want a memory for a node, not a string.
        if (n == NULL) // memory check
        {
            return 1; // signifies error
        }

        n->number = get_int("Number: ");
        n->next = NULL;

        // If list is empty, do this special case.
        if (list == NULL)
        {
            list = n;
        }
        // if list has numbers already, do this other case.
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) // creates a pointer set to list. Keeps going through loop so long as ptr is not NULL, set ptr = ptr->nxt which moves my list fan to point to the next node.
            {
                // if at end of list
                if (ptr->next == NULL) // if thing im pointing to next is NULL, nothing more to go.
                {
                    ptr->next = n; // change that NULL value to be the address of the new node.
                    break; // break out of the loop because im done.
                }
            }
        }
    }
    node *ptr = list; // this creates another variable to point at the start of the list
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; // setting ptr to the next in a while loop.
    }
     // Same code as while loop
    /*
    for (node *ptr = list; ptr != NuLL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
    return 0;
    */
}
```
- We have to free the memory that we have been allocating.
- So ultimatly the final list code will be:
```
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        n->number = get_int("Number: ");
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }
    for (node *ptr = list; ptr != NuLL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next; // this undos 1 of my mallocs each time it goes through the loop.
        free(ptr); // freeing ptr node
        ptr = next; // updating it.
    }
    return 0;
}
```
- This has built a link list that is appending nodes to the list.
- Preserving first in first out property.
- This was how you stitch things in memory.

**RECAP**
- We could implement the underlying implementation details for the following alternative structures.
- Arrays give us contiguousness whcih means we ca do binary search, especially if the data is sorted. But it might not be big enough for future data. 
- This is where we introduce linked lists where they are dynamic which means we can make use of memory creatively.
- The catch with linked lists is that were using extra space, and the code got more complicated.

## Trees
- Common data structure is a tree.
- This is like an upside down tree structure.
- There is a Tree that is a 2D data structure. 
- We use a second axis, using a **binary search tree.**
- This binary search tree is a 2D structure that we can perform binary search on.
- We paid a price with linked lists, you can not do binary search on them.
- Why cant we perform binary search on linked lists? Because there are this long string like data structure that you cant just go backwords on, and theres no mechanism for jumping to the middle. The only way of getting to the middle is to traverse the whole thing.
- The best were going to do for most those operations is O(n).

### Binary search tree
> [1][2][3][4][5][6][7].
- Heres an array with 7 "doors", that are 1D.
- We hilight the middle = [4].
- the middle of the middle = [2], [6].
- and the middle of the middle of the middle = [1], [3], [5], [7].
- This is an array at the moment, so we have the ability to do binary search, but we dont have the ability to grow or shirnk this structure.
- We can redraw this array by using some pointers.
- The |0| has no value but to create a graph like structure.
> 0|0|0|4|0|0|0|
> 0|2|0|0|0|6|0|
> 1|0|3|0|5|0|7|
- Here we have a family tree like structure, if we think of 4 as the root, then the children of the root, then the grandchildren of that root.
- If we draw lines between the numbers (not 0's), it becomes more clear. 
- The arrows imply that each of these nodes containing a number, also contains 2 pointers.
- This is where we get our 2D.
- One for left child, one for right child.
- This gives us the ability to build things 2D in memory.
- The implication of having built this up:
- How much time does it take to search this data structure now?
- We can do binary search even if pointers are involved, as long as we keep track of the root of the trees.
- If we want to search for 5, we start at root, see which number is bigger left or right, then follow in that algorithm till we reach the goal.
- We can implement binary search by not doing arithmetic, like in the case of arrays, but we can follow the arrows so long as we have built the data structure in this way.
Here is how we might implement a data structure in memory:
```
typedef struct node
{
    int number;
    struct node *next;
} node;
```
- This is how we defined a node for a linked list.
- We can redefine the notion of a node as being no longer a number and a single pointer to a next field.
- We can reuse the notion of a node as just a container for data, and instead build a node for a binary search tree.
- A node in a binary search tree, should have one pointer called left, and one pointer called right, which is going to point to other such nodes.
```
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;
```
- This is how we build usingthe same building blocks as a more complicated 2D structure, but gain back the ability for binary search.
- This can give us O(log n) runningtime. (best onpar with O(1)).
- Whats the downside? We have waisted more memory because we have no one but two more pointers for every node. 
- A good thing about 2D data structures like the binary search tree,
- Binary search tree means that we can do binary search on it. Why? It means that every nodes keft child is less than the root. And every nodes right child, is greater than the root. 
- This is a recursive definition. Why? Because we can apply it to any nodes in the tree.
- Anytime we have recursive structure like the mario bricks, so can we use recursion in code, such as:
```
bool search(node *tree, int number)
{

}
```
- Think of this as the implementation of binary search but on a 2D tree structure rather than an array.
- If we pass in a pointer to the tree itself, the root. And we give a number that were looking for, here is how we can search the 2D binary tree (that someone has already built).
```
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number) // if number is less than the current nodes own number (e.g. first number in the tree, 4)
    {
        return search(tree->left, number); // then search the left subtree for that same number.
    }
    else if (number > tree->number) // if number is greater than the current node
    {
        return search(tree->right, number); // search the right subtree for that same number.
    }
    else if (number == tree->number)
    {
        return true;
    }
}
```
- With binary search trees, we now have the ability to gain back binary search, but also we gain a new problem.
- If the user gives me in the worst case scenario root of 1, then 2, then 3. Then the tree becomes a linked list as it will all just be going to the right.
- Even if the binary search tree is nicely balanced, do allow you to do binary search and achieve O(log2 n), on running time, we have to put in some effort to ensure that it does in fact stay balanced.
- So the worst case inserting into a binary search tree could actually be linear (O(n), O(log n)), because it just gets longer with one perverse branch, unless youre smart about it. There is a solution on mainintaing balanced trees.
- In general with binary search trees, if we do make that optimization, and we maintain balance, it does not devolve to O(n), but we ensure it stays in O(log n) for not only searching, but insertion and deletion, so long as we dont blindly stick it in, but rejigger things as needed to keep them nicely balanced.

## Dictionary
- Another data structure is a dictionary, which associates words with definitions.
- Two collumns chart whereby we have a word on the left and definition on the right.
- This is a useful data structure to have access beyond lists, beyond arrays, beyond trees.
- It gives the ability in code to associate words with definitions.
- instead of words and definitions, we say key and values.
- Keys are often strings, e.g. someones name or a word.
- Values are often also strings, or numbers, or structs.
- There is a way to implement the idea of a dictionary, otherwise known as an abstract data type that just has keys and values.
- But we can implement it with a data structure, an actual data structure that gives us constant time.

## Hashing and hash tables
- Hashing relates to whats known as a hash function.
- A hash function, like any function, takes input and produces output. The idea is that it allows us to decide where some value goes in memory.
- To bucketize something is to put an input into a location.
- Buckitization helps take an infinite, or very large domain, and map it to a smaller range of value.
- Hashing takes as input some values, and spits out as output some other value.
- The key is going from a large or infinite domain, to a well defined finite range of values.
- We can build something called hash tables.
- This is like the offspring of an array and linked list together.

#### Example
- 26 array boxes vertically sorted from a-z.
- When inputting names, but first letter of name into the sorted array.
- We can then find a name in constant time. 
- What happens if there are two names of the same characters? This causes collision.
- We could link the names together using a linked list which can dynamically grow and shrink.
- This method will always produce O(n).
- This is more theorethical.
- If were more clever, and we want to get closer to realtime.
```
typedef struct
{
    char *name;
    char *number;
    struct node *next;
} node;

// If you want a hash table of 26
node *table[26];
```
- We can increase the number of buckets to identify the fisrt x characters in the name.
```
#include <ctype.h>
unsigned int hash(const char *word);
{
    return toupper(word[0]) - 'A';
} 
```
- toupper converts owecase alphabet to uppercase letters.
- Then subtract 'A', which is ascii 65.
- This function returns a number from 0 to 25.
- This gets me a larger hash table.
- Downside of having a bigger hashtable is:
- Reserving much more space up front, and waists space.
**Definitions**
- An int is signed by default, meaning it can represent both positive and negative values. An unsigned is an integer that can never be negative.
- char* is a mutable pointer to a mutable character/string. const char* is a mutable pointer to an immutable character/string. You cannot change the contents of the location(s) this pointer points to. 
- Mutable objects can be modified in place, while immutable objects cannot be changed once created.
**End of Definitions**
- The appeal of a hash table is if you have 26 or 17000 buckets, lets call it k. Will ultimatly be O(n/k) which is O(n).
- We can insure in ideal hash function that we will not have collisions.

## Tries
- Known as retrieval.
- Data structure for retrieving data.
- Alternative data structure which we can implement dictionaries, key value pairs.
- We can implement a dictionary with an array, a linked list, hash table, now a trie as well. But we get different running times based on the various structures.
- A trie is a tree of arrays.
- We are mashing together things we have already talked about and seeing what weird data structure we come up with.
- In this case, it will give us true constant time. But with a downside.
- Each of the arrays in the trie represents a letter of the alphabet, a through z, which is 26 boxes horizontally.
- The way we use arrays in a trie is to have an array of pointers, if the persons name starts with a, you can use one of those pointers to point at another node, which is another array for the second letter, and then a third array for the third letter, and so on. 
- So we use arrays for each letters in the input strings.
- So for toad, T starts at 20 which changes the NULL value to be a pointer to another array, the second array will be used to represent the second letter, O. This letter maps to another array, A. This letter points to a final and fourth array, D. The last value is a sentinal value, which sort of says X marks the spot, to end the string.
- In other words, each of the arrays is an array of 26 pointers/ structures. Somehow it can indicate that a name will end where it does.
- If we want to insert TOM, we can use the first 3 arrays that have already been used. Using T and O from TOAD and then ending at M in the third array.
- This creates a large array. But the time speed has no dependency on how many names are already in the structure.
- The implication of this structure to add, search, delete a name is constant time.
- How can we implement this?
```
typedef struct node // redefine a node
{
    struct node *children[26]; // contains array of 26 pointers which points to a node.
    char *number; // we want the trie to store peoples names implicitly and numbers explicitly.
} node;
```
- This method is the holy grail, constant time.
- What is the tradeoff?
- Memory space usage is huge.