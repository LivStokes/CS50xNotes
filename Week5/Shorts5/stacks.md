# Stacks
- At this point, we should be familiar with arrays and linked lists. There are the two primary data structures that we've talked about for keeping sets of data of similar data types organized.
- Now were going to talk about variations on arrays and linked lists - STACKS.
- Specificaly, we're going to talk about a data structure called a stack.
- Recall from previous discussions about pointers and memory, that the stack is also a name for a segment of memory where statically declared memory - memory that we name nam, variables that we name etc, and function frames which we also call stack frames exist.
- So this is a stack data structure not a stack segment of memory.

## What is a stack?
- So it's pretty much just a special kind of structure that maintains data in an organized way.
- There's two very common ways to implement stacks using two data structures that we're already familiar with, **arrays and linked lists**.
- What makes a stack special is the way in which we put information into the stack, and the way we remove information from the stack.
- In particular with stacks the rule is only the most recently added element can be removed.
- In either case, the important rule is that when data is added to the stack, it sits on top, and so if an element needs to be removed, the most recently added element is the only element that can legally be removed.
- Because of this we commonly refer to a stack as a LIFO structure, last in, first out. LIFO, last in, first out.

## LIFO
- Because of this restriction on how information can be added to and removed from a stack, there's really only two things we can do with a stack.
1. Push: Add a new element to the top of the stack.
    - If the stack doesn't exist and we're creating it from scratch, creating the stack in the first place would be pushing.
2. Pop: Remove the most recently added element from the top of the stack.

We're going to look at both implementations, both array based and linked list based.

## Array based
- Here's the basic idea of what the array based stack data structure would look like.
```
typedef struct _stack
{
    VALUE array[CAPACITY];
    int top;
}
stack;
```
- We have a typed definition here. 
- Inside of that we have two members or fields of the structure. 
> VALUE array[CAPACITY];
- We have an array. And again I'm using the arbitrary data type value. 
- So this could be any data type, int char or some other data type you previously created. 
- So we have an array of size capacity. 
- Capacity being a pound defined constant, perhaps somewhere else in our file. 
- So notice already with this particular implementation we are bounding ourselves as was typically the case with arrays, which we cannot dynamically resize, where there's a certain number of elements maximum that we can put in our stack.
- In this case it's capacity elements.

> int top;
- We also keep track of the top of the stack.
- What element is the most recently added to the stack? 
- And so we keep track of that in a variable called top.

> stack;
- And all of this gets wrapped up together into a new data type called a stack. 

### Stacks (Data Structure)
- Once we've created this new data type we can treat it like any other data type.
- We can declare stack s, just like we could do int x, or char y. And when we say stack s, well what happens is we get a set of memory set aside for us.
- In this case capacity I've apparently decided is 10 because I've got a single variable of type stack which contains two fields recall. 
- An array, in this case is going to be an array of integers as is the case in most of my examples. 
- And another integer variable capable of storing the top, the most recently added element to the stack. 
- So one single stack of what we just defined looks like this.
> stack s;
``` 
[][][][][][][][][][]
[]
s
```
- It's a box containing an array of 10 what will be integers in this case and another integer variable there in green to indicate the top of the stack.
- To set the top of the stack we just say s.top. 
> s.top = 0;
- That's how we access a field of a structure recall. 
- s.top equals 0 effectively does this to our stack. 
``` 
[][][][][][][][][][]
[0]
s
```
- So again we have two operations that we can perform now. 
- We can push and we can pop. 

#### Push
- Let's start with push. 
- Again, pushing is adding a new element to the top of the stack. 

##### Array-based implementation
Push: Add a new element to the top of the stack.
- In the general case, push() needs to:
1. Accept a pointer to the stack.
- Why would we want to accept a pointer to the stack? 
- Recall from previous videos on variable scope and pointers, what would happen if we just sent stack, s rather in as a parameter? 
- What would actually be passed in there? 
- Remember we're creating a copy when we pass it to a function unless we use pointers. 
- And so this function push needs to accept a pointer to the stack so that we're actually changing the stack we intend to change. 
2. Accept data of type VALUE to be added to the stack.
- In this case, again, an integer that we're going to add to the top of stack. 
3. Add that data to the stack at the top of the stack.
4. Change the location of the top of the stack.

> void push(stack* s, VALUE data);
- In this case our push is going to take two arguments, a pointer to a stack and a data element of type value, integer in this case. 

#### Array-based implementation:
```
stack s;
s.top = 0;
push(&s, 28);

[][][][][][][][][][]
[0]
s
```
- We declared s, we said s.top equals 0. 
- Now let's push the number 28 onto the stack.
- Currently the top of the stack is 0. And so what's basically going to happen is we're going to stick the number 28 into array location 0.
```
[28][][][][][][][][][]
[0]
s
```
- And then we need to change what the top of the stack will be. 
- So that the next time we push an element in, we're going to store it in array location, probably not 0 as we don't want to overwrite what we just put there 
- So we'll just move the top to 1.
```
[28][][][][][][][][][]
[1]
s
```
- If we want to put another element onto the stack, say we want to push 33, well now we're just going to take 33 and put it at array location number 1, and then change the top of our stack to be array location number two.
```
[28][33][][][][][][][][]
[2]
s
```
- We'll push 19 off of the stacks. 
- We'll put 19 in array location 2 and change the top of our stack to be array location 3 so if the next time we need to make a push we're good to go. 
```
[28][33][19][][][][][][][]
[3]
s
```

### Pop
- So popping is the sort of counterpart to pushing. It's how we remove data from the stack.
- Pop: Remove the most recent element from the top of the stack.

In the general case, pop() needs to:
1. Accept a pointer to the stack.
- Again in the general case. In some other case you might have declared the stack globally, in which case you don't need to pass it in because it already has access to it as a global variable.
2. Change the location of the top of the stack.
- Counter part to push, so decrement the top of the stack in pop.
3. Return the value that was removed from the stack.

- If we're adding elements, we want to get elements out later on, we want to store them so we don't just delete them from the stack and then do nothing with them.
- Generally if we're pushing and popping here we want to store this information in a meaningful way and so it doesn't make sense to just discard it.
- So this function should return a value to us.

#### Declaration for pop
```
VALUE pop(stack* s);

[28][33][19][][][][][][][]
[3]
s
```
- This function returns data of type value.
- And it accepts a pointer to a stack.
- So what is pop going to do? Let's say we want to now pop an element off of s.
```
int x = pop(&s);

[28][33][19][][][][][][][]
[3]
s
```
- Stacks are last in, first out, LIFO data structures.
Which element is going to be removed from the stack?
- 19 was the last element we added to the stack when we were pushing elements on, and so it's going to the first element that gets removed.
- It's as if we said 28, and then we put 33 on top of it, and we put 19 on top of that. The only element we can take off is 19.
```
int x = pop(&s);    
    [19]x

[28][33][][][][][][][][]
[2]
s
```
- Now in the diagram here what I've done is sort of deleted 19 from the array. 
- That's not actually what we're going to do. 
- We're just going to kind of pretend it isn't there. 
- It's still there in that memory location, but we're just going to ignore it by changing the top of our stack from being 3 to 2. 
- So if we were to now push another element onto the stack, it would over write 19. 
- Let's not go through the trouble of deleting 19 from the stack. 
- We can just pretend it isn't there. 
- For purposes of the stack, it's gone if we change the top to be 2 instead of 3.

Lets do it again:
```
int x = pop(&s);    
    [33]x

[28][33][19][][][][][][][]
[1]
s
```
- We're going to store 33 in x and we're going to change the top of the stack to 1.
- So that if we were now to push an element into the stack:
```
push(&s, 40);

[28][40][19][][][][][][][]
[2]
s
```
- What's going to happen is we're going overwrite array location number 1.
- So that 33 that was sort of left behind that we just pretended isn't there anymore, we're just going to clobber it and put 40 there instead.
- Since we made a push, we're going to increment the top of the stack from 1 to 2 so that if we now add another element it'll go into array location number two. 

## Linked list based
```
typedef struct _stack
{
    VALUE val;
    struct _stack *next;
}
stack;
```
- Linked lists are another way to implement stacks.
- This definition is pretty much exactly the same as a singly linked list.
- The only restriction here is we're not allowed to insert or delete randomly from the singly linked list which we could previously do.
- We can only insert and delete from the front or the top of the linked list.
- That's really the only difference though. This is otherwise a singly linked list.
- The rule here is to always maintain a pointer to the head of the linked list.
- For singly linked list you only need a pointer to the head in order to have that chain be able to refer to every other element in the linked list.
- But it's particularly important with a stack.
- And so generally you're going to actually want this pointer to be a global variable.

### Push
- To push, dynamically allocate a new node, set its next pointer to point to the current head of the list, then move the head pointer to the newly created list.
- In a linked list that means we're going to have to create a new node that we're going to add into the linked list, and then follow the careful steps that we've outlined previously in singly linked lists to add it to the chain without breaking the chain and losing or orphaning any elements of the linked list.

#### As a diagram:
```
list = push(list, 12);

[15][9][13][10]
[][][][]
```
- So here's our linked list. It concurrently contains four elements. 
- And more perfectly here's our stack containing four elements.
- And let's say we now want to push a new item onto this stack with a value of 12.
- Well first we're going to malloc space, dynamically allocate space for a new node.
```
list = push(list, 12);

[][15][9][13][10]
[][][][][]
```
- And of course immediately after we make a call to malloc we always make sure to check for null, because if we got null back there was some sort of problem.
- We don't want to dereference that null pointer or you will suffer a seg fault.
- We're going to put 12 into the data field of that node.
```
list = push(list, 12);

[12][15][9][13][10]
[][][][][]
```
- Which of our pointers moves next so we don't break the chain?
- Set news next pointer to point to the old head of the list or what will soon be the old head of the list.
- Now that all of our elements are chained together, we can just move list to point to the same place that new does.
- And we have now effectively pushed a new element onto the front of the stack. 

### Pop
- To pop we just want to delete that first element.
- Traverse the linked list to its second element (if it exists), free the head of the list, then move the head pointer to the (former) second element.
- So basically what we have to do here, well we have to find the second element. Eventually that will become the new head after we delete the first one.
- So we just need to start from the beginning, move one forward.
- Once we've got a hold on one forward of where we currently are we can delete the first one safely and then we can just move the head to point to what was the second term and then now is the first after that node has been deleted. 

#### As a diagram:
```
pop(list);
[12][15][9][13][10]
[][][][][]
```
- First were going to create a new pointer that's going to point to the same spot as the head (box below 12) called trav.
- We're going to move it one position forward by saying trav equals trav next for example, which would advance the trav pointer one position forward (box below 15).
- Now that we've got a hold on the first element through the pointer called list, and the second element through a pointer called trav, we can safely delete that first element from the stack without losing the rest of the chain because we have a way to refer to the second element forward by way of the pointer called trav. 
- Free the node [12], located by pointer list.
- And then move list to point to the same place that trav does, and we're sort of back where we started before we pushed 12 on in the first place.
```
pop(list);
[15][9][13][10]
[][][][]
```
- The reason we would use stacks is to maintain data in such a way that the most recently added element is the first thing we want to get back.