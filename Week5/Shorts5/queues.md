# Queues
- Queues are a similar concept to stacks with a slight twist.
- It is another kind of data structure that we can use to maintain data in an organized way.
- Similar to a stack, it can be implemented as an **array** or a **linked list**. 
- Unlike a stack, the rules that we use to determine when things get added and removed from a queue are a little bit different.
- Unlike a stack, which is a LIFO structure, last in, first out, a queue is a FIFO structure, FIFO, first in, first out.

Anaology = If you've ever been in line at an amusement park or at a bank, there's sort of a fairness implementing structure. The first person in line at the bank is the first person who gets to speak to the teller.

- So again a queue is first in, first out, versus a stack which last in, first out.
- Similar to a stack, we have two operations that we can perform on queues. 
1. enqueue, which is to add a new element to the end of the queue.
2. dequeue, which is to remove the oldest element from the front of the queue.
- So we're going to add elements onto the end of the queue, and we're going to remove elements from the front of the queue.
- Again, with the stack, we were adding elements to the top of the stack and removing elements from the top of the stack. 

## Enqueue
- So with enqueue, it's adding to the end, removing from the front. So the oldest thing in there is always the next thing to come out if we try and dequeue something. 
- We can have array-based implementations and linked-list based implementations. 
- We'll start again with array-based implementations.

### Array based implementations
```
typedef struct _queue
{
    VALUE array[CAPACITY]
    int front;
    int size;
}
queue;
```
- We have another array there of data type value, so it can hold arbitrary data types. 
- We're again going to use integers in this example. 
- Because we're using an array, we necessarily have that limitation that C kind of enforces on us, which is we don't have any dynamism in our ability to grow and shrink the array.
- We have to decide at the beginning what is the maximum number of things that we can put into this queue, and in this case, capacity would be some pound defined constant in our code. 
- And for the purposes of this, capacity is going to be 10.
- We need to keep track of the front of the queue so we know which element we want to dequeue, and we also need to keep track of something else-- the number of elements that we have in our queue.
- Notice we're not keeping track of the end of the queue, just the size of the queue.
We will find out why soon..

- Once we have completed this type definition, we have a new data type called queue, which we can now declare variables of that data type.

**We have called this queue called q.**
```
queue q;

[][][][][][][][][][]
[]
[]
q
```
- So here is our queue. It is a structure. 
- It contains three members or three fields, an array of size CAPACITY. 
- In this case, CAPACITY is 10. 
- And this array is going to hold integers.
- The middle box is the front of our queue, the next element to be removed.
- The bottom box is the size of the queue, how many elements are currently existing in the queue.

- So if we say 
> q.front = 0;
and 
> q.size = 0
- we're putting 0s into those fields.
```
queue q;
q.front = 0;
q.size = 0;

[][][][][][][][][][]
[0]
[0]
q
```
- And at this point, we're pretty much ready to begin working with our queue. 

In general case, enqueue() needs to:
1. Accept a pointer to the queue.
    - The first operation we can perform is to enqueue something (to add a new element to the end of the queue).
    - if we had declared our queue globally, we wouldn't need to do this necessarily, but in general, we need to accept pointers to data structures like this, because otherwise, we're passing by value-- we're passing in copies of the queue, and so we're not actually changing the queue that we intend to change. 
2. Accept data of type VALUE to be added to the queue.
3. Add that data to the queue at the end of the queue.
4. Change the size of the queue.

**General form function declaration for what enqueue might look like:**
```
void enqueue(queue* q, VALUE data);
[][][][][][][][][][]
[0]
[0]
q
```

**Enqueue the number 28 into tht queue:**
- Front of our queue and size of queue is 0.
- We want to change the q array to 28.
- Now we need to change array size and front.
- With front, we dont want to change this because this is the oldest element.
- With size, we want to change this to 1.
- A general idea of where the next element is going to go in a queue, we add front and size.
```
enqueue(&q, 28);
[28][][][][][][][][][]
[0]
[1]
q
```

**Now lets enqueue 33;**
- So 33 is going to go into array location front 0 + size 1, array location 2.
- Then set the size of location to 2.
- So 33 is going to go into array location front 0 + size 1, array location 2.
- Then set the size of location to 2.
- Were not changing the front of our queue, because 28 is still the oldest element, and when we eventually get dequeueing, removing elements, from the queue, we want to know where the oldest element is.
- So keep front set to 0.
```
enqueue(&q, 33);
[28][33][][][][][][][][]
[0]
[2]
q
```

**Now lets enqueue 19;**
- This puts 19 is array location 2
- Now the size of our queue is 3, 3 elements in the queue.

```
enqueue(&q, 19);
[28][33][19][][][][][][][]
[0]
[3]
q
```
- If we were to enqueue another element it would go into q array 3, and the size out increase to 4. Etc.

## Dequeue
### Array-based implementation
- Dequeue: Remove the most recent element from the front of the queue.
In the general case, dequeue() needs to:
1. Accept a pointer to the queue.
2. Change the location of the front of the queue.
3. Decrease  the size of the queue.
4. Return the value that was removed from the queue.

- Similary to pop which is sort of the analog of this for stacks, dequeue needs to accept a pointer to the queue, unless its globally declared.
- Now we want to change the location of the front of the queue. This is where it sort of comes into play, that front variabe, because once we remove an element, we want to move it to the next oldest element.
- Then we want to decrease the size of the queue.
- Then return the value that was removed from the queue, again not discarding it, we presumably are extracting it from the queue - because we care about it. 
- So we want this function to return a data element of type value. In this example, this is type integer.

#### Example
**To dequeue/ remove element**
```
int x = dequeue(&q);

[28][33][19][][][][][][][]
[0]
[3]
q
```
- If we say int x = &q, '&q' which is a pointer to this q data structure. What element will be dequeued?
- In this case, because it is a first in, first out data structure, FIFO.
- The first thing we put into this queue was 28.
- So take 28 out of the queue.
- Similarly to what we do in a stack, we dont actually delete 28 from the queue itself, but rather hide it/ pretend it doesnt exist.
- So it will stay there in memory but were just going to ignore it by moving the other two fields of our q data.
- We change our front to be 1 because that is now the front of our list.
- And now we want to change the size of our queue to be 2.
```
int x = dequeue(&q);

[0][33][19][][][][][][][]
[1]
[2]
q
```

- When we want to add elements to the queue, we want to put it into array location which is the sum of front and size.
- So in this case, were still putting it, the next element in the queue, into array location 3.

**Lets remove another element from the queue:**
- In this case the current oldest element is array location 1, which is wat front tells us.
- x becomes 33 and then we forget it exists.
- Then we say the new oldest element in the queue is at array location 2, so set the front to 2.
```
int x = dequeue(&q);

[0][0][19][][][][][][][]
[2]
[1]
q
```

**enqueue element to the queue**
- Say we want to add 40 to this queue. Where does it go?
- We put it in q front + q size.
- That means that it goes in front 2 + size 1 = array q 3.
- The front of the queue stays at 2 because 19 is the oldest element of the queue
- We change size of queue to now be 2.
```
enqueue(&q, 40);

[0][0][19][40][][][][][][]
[2]
[2]
q
```
- The 0, 0, where 28 and 33 used to be are technically open spaces, and so we may eventually, with the rule of adding front and size, need to mod by the size of capacity.
- This is so we can wrap around.
- So if we get to element number 10, if were replacing it in element number 10, we'd actually put it in array location 0.
- If we added them up together and we got to number 11, we would be where we would have to put it, which doesnt exist in this array and going out of bounds.
- Then we mod by 10 and put it in array location 1.
- So thats how queues work.
- They will always go from left to right and possibly wrap around.
- You know that theyre full if size becomes equal to capacity; if q.size == [CAPACITY]; 

### Linked list based
```
typedef struct _queue
{
    VALUE val;
    struct _queue *prev;
    struct _queue *next;
}
queue;
```
- This data structure type looks familiar - it is a doubly linked list.
- It is possible to implement a queue as a singly linked list, but in terms of visualisation, it may help to view it as a dllist.
- Make sure to always maintain pointers to the head and tail of the linked list.

**To enqueue**
1. Dynamically allocate a new node;
2. Set its next pointer to NULL, set its prev pointer to the tail;
3. Set the tail pointer to the new node.
4. Move the tail poiner to the newly created node.
- Because were adding to the end and removing from the beginning, we need to maintain pointers to head and tail of the list.
- If we add a new element what do we do?
- We malloc or dynamically allocate our new node for ourselves.
- And then, just like when we add any element to a doubly linked list we, those last three steps here are about moving the pointers in the correct way so that the element gets added to the chain without breaking the chain or making some sort of mistake or having some sort of accident happen whereby we accidentally orphan some elements of our queue.

What this might look like:
```
head - [][][][] - tail
[12][15][9][13]
[][][][]
```
- We want to add the element 10 to the end of this queue. 
- So the oldest element here is represented by head. - That's the first thing we put into this hypothetical queue here. 
- And tail, 13, is the most recently added element. And so if we want to enqueue 10 into this queue, we want to put it after 13. 
- And so we're going to dynamically allocate space for a new node and check for null to make sure we don't have a memory failure. 
- Then we're going to place 10 into that node, and now we need to be careful about how we organize pointers so we don't break the chain. 
```
enqueue(tail, 10);

head - [NULL][][][] - tail [] - new
[12][15][9][13][10]
[][][][NULL][]
```
- We can set 10's previous field to point back to the old tail.
- Since '10 will be the new tail at some point by the time all of these chains are connected, nothing's going to come after 10 right now.
- set 10's next pointer to NULL.
- After we've connected 10 backwards to the chain, we can take the old tail of the queue, 13, and make it point to 10.
- And now, at this point, we have enqueued the number 10 into this queue. 
- All we need to do now is just move the tail to point to 10 instead of to 13.
```
enqueue(tail, 10);

head - [NULL][][][][] - tail, new
[12][15][9][13][10]
[][][][][NULL]
``` 

**To dequeue**
- Dequeuing is actually very similar to popping from a stack that is implemented as a linked list if you've seen the stacks video.
- All we need to do is start at the beginning, find the second element, free the first element, and then move the head to point to the second element.

Steps involved:
1. 
traverse the linked lost to its second element(if it exists);
2. Free the head of the list;
3. Move the head pointer to the (former) second element;
4. Move that nodes prev pointer point to NULL.

**Visualisation**
- So here's our queue again. 12 is the oldest element in our queue, the head. 10 is the newest element in our queue, our tail. 
```
dequeue(head);

head - [NULL][][][][] - tail
[12][15][9][13][10]
[][][][][NULL]
``` 
- When we want to deque an eement, we want to remove the oldest element.
- What do we do?
```
dequeue(head);

head - [NULL][][][][] - tail
[12][15][9][13][10]
trav - [][][][][NULL]
``` 
- Set a traversal pointer that starts at the head, and we move it so that it points to the second element of this queue-- something by saying trav equals trav arrow next, for example, would move trav there to point to 15, which, after we dequeue 12, or after we remove 12, will become the then-oldest element. 
```
dequeue(head);

head - [NULL][][][][] - tail
[12][15][9][13][10]
[] trav - [][][][NULL]
``` 
- Now we've got a hold on the first element via the pointer head and the second element via the pointer trav. 
- We can now free head
```
dequeue(head);

head - [-][][][][] - tail
[-][15][9][13][10]
[-] trav - [][][][NULL]
``` 
- And then we can say nothing comes before 15 anymore. 
- So we can change 15's previous pointer to point to null, and we just move the head over. 
```
dequeue(head);

[-] head - [NULL][][][] - tail
[-][15][9][13][10]
[-] trav - [][][][NULL]
``` 
- And there we go. Now we have successfully dequeued 12, and now we have another queue of 4 elements. 
- That's pretty much all there is to queues, both array-based and linked-list based.