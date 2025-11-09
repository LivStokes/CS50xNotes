# Doubly linked lists
- In Singly linked lists, we talked about how they do attend our ability to deal wit information where the number of elements or items in a list can grow or shink.
- They extend our ability to collect and organise data, but they siffer from a crucial limitaion:
- We can only ever move in one direction through a list.
- Consider the implication that would have for trying to delete a node.
- Doubly linked list, by contrast, allows us to mve forward and backward through te list, all by simply adding one extra pointer to our struct definition.
- If requred to delete single elements from a list, consider using a doubly linked list because doubly linked lists allows us to move forwards and backwards though a list.
- We can do this by adding an extra element to our structure definition for the doubly linked list node.
- The nodes for our doubly linked lists are going to be larger as they will take up more bytes of memory.
- There is not so many reasons to create doubly linked lists if you are not going to be deleting single elements.

## Structure of doubly linked list
```
typedef struct dllist
{
    VALUE val;
    struct dllist* prev; // This is the extra node for dllist.
    struct dllist* next;
}
dllnode;
```

- In order to work with lists effectivelt, there are a number of operations that we need to understand:
1. Create a linked list when it doesnt already exist.
2. Search thorugh a linked list to find an element.
3. Insert a new node into the linked list.
4. Delete a single element from a list.
5. Delete an entire list.

- With doubly linked lists, we can perform these almost the same way as a singly linked list, except 3 and 4.

**Inserting a new node into the linked list:**
> dllnode* insert(dllnode* head, VALUE val);
- Were passing in the head of the list here, and some arbitrary value.
- We want to get the new head of the list out of this funciton. That is why it returns a dllnode *.

**Steps involved:**
1. Dynamically allocate space for a new dllnode.
2. Check to make sure  we didnt run out of memory.
3. Populate and insert the node at the beginning of the linked list.
4. Fix the prev pointer of the old head of the lnked list.
5. Return a pointer to the new head of the linked list.

### Inserting a new node
> list = insert(list,12)
- Remember, we can never break the chain when rearranging the pointers.
- Even if we need to have redundant pointers temporarily, thats okay.
[15][9][13][10].
- To add 12 to the dllist, we must point 12 to 15.
[12][15][9][13][10].
- What comes before 12? NULL.
- Then we can have 15 point back to 12.
- Then we can move the head of the linked list back to 12.

## Deleting an old node
> void delete(dllnode* target);
- If we have some function that finds a node we want to delete and has given us a pointer to exactly the node we want to delete.
- All this function does is points to the node we want to delete, and deltes it.

**Steps involved:**
1. Fix the pointers of the surrounding nodes to skip over the target.
2. Free the target.

E.g. Deleting any node in the middle of the list.
- This list must have a legitimate pointer going forwards and backwards. (prev and next pointers).
- Delete(x). x = 13.
[12][15][9][13][10].
- First, we need to rearrange the outside pointers, 9's next, and skip over 13 and point to 10.
- We need to rearrange 10's previous to point to 9 instead of 13.
- We can then drop 13 without loosing the integrity of the list.

- Linked lists, of both singly and doubly linked varieties, support extremely efficient insertion and deletion of elements.
    - In fact, these operations can be done in constant time.
- Whats the downside? Remember how we had to find an element? We've lost the ability to randomly access list elements.
    - Accessing a desired element now take linear time.

- It always takes three or four operations to delete an x node (to free a node).
- It may require more than three operations to insert an x node.

- There are tradeoffs here with dllists where we cant search for a node, we cant say we want an element number of a linked list, the same way we can do that with an array and index into an arrays element.
- So to find an element in a linked list (if searching is important) may take  linear time.
- As the list gets longer, it might take one additional step for very element in the list to find what were looking for.

- dllist are not the last kind of structure combonation that we will talk about, taking the basic building blocks of C.
- We can do better than this, taking a data structure that we can search through in constant time too.