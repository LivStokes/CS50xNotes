# Singly-Linked Lists
## Collection
- So far we have had one kind of data structure for representing collections of like values, such as an array of ints, or chars etc.
- Structs are also a data structure for collecting information, but not for collecting like values, it usually mixes different data types together inside of a single box - gives us containers for holding variables of different data types. 
- Arrays are great for element lookup, but unless we want to insert at the very end of the array, inserting elements is quite costly - remember insertion sort?
![alt text](image.png)
- Insertion sort required alot of work by picking up elements, and shifting them out of the way to fit something into the middle of the array.
- Arrays also suffer from a great inflexibility - what happens if we need a larger array than we thought?
- Through clever use of pointers, dynamic memory allocation, and structs, we can put the pieces together to develop a new kind of data structure that gives us the ability to grow and shrink a collection of like values to fit our needs.
- We call this combonation of elements, when used in this way, a linked list.
- A singly linked list is comprised of nodes, nodes being an abstract term - something we call a kind of structure.
- This node has two members, or two fields:
1. Data of some data type (int, char, float, typedef...)
2. A pointer to another node of the same type.
- In this way, a set of nodes together can be thought of as forming a chain of elements that we can follow from beginning to end.
- If we try to viuaize this, we can see it as a chain of nodes that are connected together, the first node containing data, a pointer to the second node which contains data, pointing to the third node which contains data, Hense why we call it a linked list.
- This special node structure can look like this:
```
typedef struct sllist // 
{
    VALUE val; // VALUE is arbitrary for int, char, float etc.
    struct sllist* next; // pointer to another node of the same type.
}
sllnode;
```
- This is a self referential structure so we must have a temporary name for the structure.
- The end of the code we want a specific name being sllnode, which is the new name part of the type definition.
- But we cant use sllnode in the middle because we havent created a typesllnode until we hit the end of the code.
- Up until that point we must create another way to refer to this data type.
- This is a self referential data type.
- Its a data type of a structure that contains data, and a pointer to another structure of the same data type.
- So we need to be able to refer to this data type at least temporarily.
- Giving it a temporary name of struct sllist allows us to say we want a pointer to another struct sllist, a struct sllist*, and then after completion of the definition, we can call this type an sllnode.
- Thats why there is a temporary name, struct sllist, but a permenant name, sllnode.
- Sometimes we might see definitions of structure, for example that arent self referential, that dont have a specifier name. It would just say typedef struct {} then define it inside the {}.
- If struct is self deferential such as the example, we need to specify a temporary type name.
- Now that we have done this, we can refer to the nodes/units as sslnode for purposes of the rest of the lecture.
- This taught us to create a linked list node, and define it.

## Operations
- To start using linked list nodes, we need to collect information.
- In order to work with linked lists effectively, there are a number of operations that we need to understand:
1. Create a linked list when it doesnt already exist.
2. Search through a linked list to find an element.
3. Insert a new node into the linked list for it to be able to grow.
4. Delete a single element from a linked list for it to be able to shrink.
5. Delete an entire linked list at the end of our programs in one fail swoop. Because were dynamically allocating memory, to build these lists, we want to free all of that memory.

### How to visualize this in pseudocode:
- Create a linked list
> sllnode* create(VALUE val); // passing in one argument of arbitrary data type. Returning a pointer to a singly linked list node.

Steps involved:
1. Dynamically allocate space for a new sllnode. Need to malloc space for it.
2. Check to make sure we didnt run out of memory. After malloc we need to make sure our pointer does not give back NULL. If we try dereference a NULL pointer, we will suffer a segfault.
3. Initialize the nodes val field.
4. Initialize the nodes next field.
5. Return a pointer to the newly created sllnode.

> sllnode* new = create(6);
1. Dynamically allocate space for a new sllnode. This requires malloc.
2. Check to make sure we didnt run out of memory. That its not NULL.
3. Initialize the nodes val field. Example 6.
4. Initialize the nodes next field. Example NULL.
5. Return a pointer to the newly created sllnode. Example "new" pointing at 6, and return "new".

### Search through a linked list to find an element.
- Lets say we already have a large chain, we want to find something in it and we want a function that will return true or false depending on wether a value exists in that list. 
- The function prototype may look like this:
> bool find(sllnode* head, VALUE val); 
- The first argument is a pointer to the first element of the linked list. 
- Once you create a list, you always want to keep track of the first element of the list, so we can refer to all the other elements by following the chain without having to keep pointers intact to every single element. We only need to keep track of the first one if they are all chained together.
- The second were passing is arbitrarily whatever data type were looking for that is inside one od the nodes in the list.

### Steps involved:
1. Create a traversal pointer pointing to the list head. // its better to create a second one that we use to move.
2. If the current nodes val field is what were looing for, report success.
3. If not, set the traversal pointer to the next pointer in the list and go back to step b.
4. If youve reached the end of the list, report failure.

### Example of a singly linked list:
> bool exists = find(list, 6);
- create a pointer to the head of the list called 'list'. This could be pointing to 2.
- Create a traverse pointer, called trav, pointing to the same thing. (We dont need malloc for additional space as the space already exists. All were doing is creating another pointer to it.)
- If 2 is not what were looking for, then we say trav equals trav next, pointing to the next node in the list. This could be pointing to 3.
- If 3 is not what were looking for, then trav continues to go through until evenually  getting to 6 which is what were looking for based on the function call. So were done.
- What if the element were looking for is not in the list?
- We dont have to preserve lists in any particular order. Were not keeping track of what number element were looking at. 
- This is a trade that we have with linked list verses arrays. We dont have random access anymore. We cat say we want to go to the 0th element, or the 6th element of the linked list, which we can do in an array. This is because there is no index associated with them.
- Therefore it doesnt matter if we preserve our list in order.
- Trav will go through the whole linked list and if it doesnt find what its looking for until it reaches NULL, it will return fasle.

## Insert Node
- Previously, we built a linked list out of nowhere. Byt we probably want to build a chain and not create a bunch of distinct lists. 
- So we want one list that has a bunch of nodes in it, not a bunch of lists with a single node.
- We cant keep using the create function that we used earlier, now we use the insert function into a list that already exists.
- How to insert a new node into the linked list?
> sllnode* insert(sllnode* head, VALUE val);
- In this case, we pass in two arguments, the pointer to the head of that linked list that we want to add to, and whatever value we want to add to the list.
- Eventually this function will return a pointer to the new head of the linked list.

### Steps involved:
1. Dynamically allocate space for a new sllnode.
2. Check to make sure we didnt run out of memory, beacuse were using malloc.
3. Populate and insert the node at the beginning of the linked list. 
4. Return a pointer to the new head of the linked list.
- The reason we want to insert it at the beginning is because we can do it immediatly. We have a pointer at the beginning. 
- If we want to insert at the end, we have to start at the beginning, traverse all the way to the end, and then tack it on. So that means inserting at the end of the list, would become an O(n) operation, going back to the discussion of computational complexity.
- As the list gets bigger and bigger, it becomes  more difficult to tack something on at the end. But its always easy to tack something at the beginning.
- Once were done and inserted the new node, we want to return out pointer to the new head of a linked list, which will be a pointer to the node we just created.

### How to "visualise"
> list = insert(list, 12);
[15][9][13][10]
- List consists four elements.
- A node containing 15, which points to a node containing 9, which points to a node containing 13, which points to a node containing 10, which has the NULL pointer as its next pointer(end of list).
- If we want to insert a new node with the value 12 at the beginning of this list, what do we do?
- First we malloc space for the node, and then we put 12 in there.
- Which pointer should we move first? Should the 12 node be the new head of the linked list, since it now exists, or should we connect it to the list first?
- Should we make 12 point to the old head of the list? Or should we say that the list now begins at 12?
- This is one of the trickiest things with linked lists, order matters!
- We dont want to orphan the rest of the list by pointing the list directly to the new node 12.
- We set 12 next pointer to the old head of the list first, then we can move the list over.
- We want to make sure everything is chained together before we move the pointer.
- So connect 12 to the list, then say the list starts at 12.
[12][15][9][13][10]


## Deleting an entire list
- If we want to destroy a whole list at once?
- We are mallocing all of this space, so we need to free it when were done.
> void destroy(sllnode* head);

### Steps involved:
1. If youve reached a NULL pointer, stop.
2. Delete the rest of the list.
3. Free the current node.

[12][15][9][13][10]

- How to delete the rest of the list?
- Delete the list starting from 15 in the example above, this will go thorugh the stack frames and delete until the NULL pointer.
- Then free the current nodes, from right to left.

**In order to work with linked lists effectivelt, there are a number of operations that we need to understand:**
1. Create a linked list when it doesnt already exist/
2. Search through a linked list to find an element.
3. Insert a new node into the linked list.
4. Delete a single element from a linked list.
5. Delete an entire linked list.

- It is hard to delete a single element from a linked list because it risks breaking the chain. And so thats where double linked lists come in...