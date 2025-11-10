# Data Structures
- we've covered a lot of different data structures
1. Arrays
2. linked lists
3. hash tables
4. tries
5. stacks
6. queues 
- We'll also learn a little about trees and heaps, but really these all just end up being variations on a theme. 

There really are these kind of four basic ideas that everything else can boil down to. 
1. Arrays
2. linked lists
3. hash tables
4. tries

- There are variations on them, but this is pretty much going to summarize everything. 
- How do these all measure up? 
- Let's weigh the pros against the cons, and consider which data structure might be the right data structure for your particular situation, whatever kind of data you're storing. 
- You don't necessarily always need to use the super fast insertion, deletion, and lookup of a trie if you really don't care about inserting and deleting too much. 
- If you need just quickly random access, maybe an array is better. 

## Arrays
- Insertion is bad - lots of shifting to fit an element in the middle.
    - Insertion at the end of an array is OK, if we're building an array as we go. 
    - But if we need to insert elements into the middle, think back to insertion sort, there's a lot of shifting to fit an element in there. 
    - And so if we're going to insert anywhere but the end of an array, that's probably not so great.

- Deletion is bad - lots of shifting after removing an element.
    - Unless we're deleting from the end of an array, is probably also not so great if we don't want to leave empty gaps, which usually we don't. 
    - We want to remove an element, and then sort of make it snug again. 
    - And so deleting elements from an array, also not so great. 

- Lookup is great - random access, constant time.
    - We just say seven, and we go to array relocation seven.
    - We say 20, with go to array relocation 20. - We don't have to iterate across. That's pretty good.

- Sorting is easy. 
    - Every time we talked about a sorting algorithm, such as selection sort, insertion sort, bubble sort, merge sort, we always used arrays to do it, because arrays are pretty easy to sort, relative to the data structures we've seen so far. 

- Size is small. 
    - There's not a lot of extra space. 
    - You just set aside exactly as much as you need to hold your data, and that's pretty much it. 
    - So they're pretty small and efficient in that way. 

- No flexibility - stuck with a fixed size
    - We have to declare exactly how big we want our array to be, and we only get one shot at it. 
    - We can't grow and shrink it. 
    - If we need to grow or shrink it, we need to declare an entirely new array, copy all of the elements of the first array into the second array. 
    - And if we miscalculated that time, we need to do it again.

## Linked lists 
- Insertion is easy. 
    - We just tack onto the front. 

- Deletion is easy - once youve found the element. 
    - We have to find the elements. 
    - That involve some searching. 
    - Once you've found the element you're looking for, you change a pointer, possibly two if you have a linked list-- a doubly linked list, rather-- and then you can just free the node. 
    - You don't have to shift everything around. You just change two pointers, so that's pretty quick.

- Lookup is bad - have to rely on linear search.
    - In order for us to find an element in a linked list, whether singly or doubly linked, we have to linear search it. 
    - We have to start at the beginning and move the end, or start at the end move to the beginning. 
    - We don't have random access anymore. 
    - So if we're doing a lot of searching, maybe a linked list isn't quite so good for us.

- Sorting is difficult - unless youre willing to compromise on super fast insertion and instead sort as you construct.
    - The only way you can really sort a linked list is to sort it as you construct it. 
    - But if you sort it as you construct it, you're no longer making quick insertions anymore. 
    - You're not just tacking things onto the front. 
    - You have to find the right spot to put it, and then your insertion becomes just about as bad as inserting into an array. 
    - So linked lists are not so great for sorting data. 

- Size is small - not as small as arrays.
    - Doubly linked list slightly larger than singly linked lists, which are slightly larger than arrays, but it's not a huge amount of wasted space. 
    - So if space is at a premium, but not a really intense premium, this might be the right way to go. 

## Hash tables
- Insertion is easy.
    - It's a two-step process. 
    - First we need to run our data through a hash function to get a hash code.
    - And then we insert the element into the hash table at that hash code location. 

- Deletion is easy – once you find the element.
    - You have to find it first, but then when you delete it, you just need to exchange a couple of pointers, if you're using separate chaining. 
    - If you're using probing, or if you're not using chaining at all in your hash table, deletion is actually really easy. 
    - All you need to do is hash the data, and then go to that location. 
    - And assuming you don't have any collisions, you'll be able to delete very quickly. 

- Lookup is on average better than with linked lists because you have the benefit of a real-world constant factor.
    - If you're using chaining, you still have a linked list, which means you still have the search detriment a linked list. 
    - But because you're taking your linked list and splitting it over 100 or 1,000 or n elements in your hash table, you're linked lists are all one nth the size. 
    - They're all substantially smaller. 
    - You have n linked lists instead of one linked list of size n. 
    - And so this real-world constant factor, which we generally don't talk about in time complexity, it does actually make a difference here. 
    - Lookup is still linear search if you're using chaining, but the length of the list you're searching through is very short by comparison.

- Sorting is bad.
    - Not an ideal data structure if sorting is the goal – just use an array.
- Can run the gamut of size.
    - It's hard to say whether a hash table is small or big, because it really depends on how large your hash table is. 
    - If you're only going to be storing five elements in your hash table, and you have a hash table with 10,000 elements in it, you're wasting a lot of space. 
    - Contrast being you can also have very compact hash tables, but the smaller your hash table gets, the longer each of those linked lists gets. 
    - And so there's really no way to define exactly the size of a hash table, but it's probably safe to say it's generally going to be bigger than a linked list storing the same data, but smaller than a trie. 

## Tries
- Insertion is complex – a lot of dynamic memory allocation, but gets easier as you go.
    - There's a lot of dynamic memory allocation, especially at the beginning, as you're starting to build. 
    - But it's constant time. 
    - It's only the human element here that makes it tricky. Having to encounter null pointer, malloc space, go there, possibly malloc space from there again. 
    - The sort of intimidation factor of pointers in dynamic memory allocation is the hurdle to clear. 
    - But once you've cleared it, insertion actually comes quite simple, and it certainly is constant time.

- Deletion is easy – just free a node.
    - All you need to do is navigate down a couple of pointers and free the node, so that's pretty good.

- Lookup is fast – not quite as fast as an array, but almost.
    - It's only based on the length of your data. 
    - So if all of your data is five character strings, for example, you're storing five character strings in your trie, it only takes five steps to find what you're looking for. 
    - Five is just a constant factor, so again, insertion, deletion, and lookup here are all constant time, effectively. 

- Already sorted – sorts as you build in almost all situations.
    - By virtue of how we're inserting elements, by going letter by letter of the key, or digit by digit of the key, typically, your trie ends up being kind of sorted as you build it. 
    - It doesn't really makes sense to think about sorting in the same way we think about it with arrays, or linked lists, or hash tables. 
    - But in some sense, your trie is sorted as you go. 

- Rapidly becomes huge, even with very little data present, not great if space is at a premium.
    - From every junction point, you might have-- if your key consists of digits, you have 10 other places you can go, which means that every node contains information about the data you want to store at that node, plus 10 pointers. 
    - Which, on CS50 IDE, is 80 bytes. So it's at least 80 bytes for every node that you create, and that's not even counting data.
    - If your nodes are letters instead of digits, now you have 26 pointers from every location. 
    - And 26 times 8 is probably 200 bytes, or something like that. 
    - And you have capital and lowercase-- you can see where I'm going with this.
    - Your nodes can get really big, and so the trie itself, overall, can get really big, too. 
    - So if space is at a high premium on your system, a trie might not be the right way to go, even though its other benefits come into play.