# Tries
- We've been inching closer and closer that holy grail of data structures, one that we can :
1. insert into, 
2. delete from, 
3. look up in constant time.
- Have we found it here when we're talking about tries? 

#### Arrays
- So for arrays:
    - The key is the element index.
        - Array location 0 or array 1 and so on. 
    - And the value is the data that exists at that location. 
        - So what is stored in array 0? 
        - What is stored in array 1 versus just 0 and 1, which would be the keys.

#### Hash tables
- With a hash table it's sort of the same idea:
    - We have this hash function that generates hash codes. 
        - The key is the hash code of the data. 
    - The value, particularly we talked about chaining in the video on hash tables, is that linked list of data that hashes to that hashcode. 

- What about another approach to this method where the key is guaranteed to be unique, unlike a hash table, where we could end up with two pieces of data having the same hashcode. 
- Then we have to deal with that by either probing or more preferably chaining to fix that problem. 

- So now we can guarantee that our key will be unique. 
- And what if our value was just something as easy as true and false that tells us whether or not that piece of information exists in the structure? 
- A Boolean could be as simple as a bit. 
    - Realistically it's probably a byte more likely than a bit. But that's a lot smaller than storing maybe a 50-character string, for example. 

## Tries
- So tries, similar to hash tables, which combine arrays and linked list, tries combine arrays, structures, and pointers together to store data
- Now we use the data as a roadmap to navigate this data structure. 
    - If we can follow the roadmap, if we can follow the data from beginning to end, we'll know whether that data exist in the trie. 
    - If we can't follow the map from meaning to end at all, the data can't exist. 
- Again, the keys here are guaranteed to be unique. 
- Unlike a hash table, we'll never have to deal with collisions here. 
- No two pieces of data have exactly the same roadmap unless that data is identical. 

### Example
- If we insert John, then we search for John. 
- That's two identical pieces of data, right, we're looking through. 
- But otherwise, any two pieces of data are guaranteed to have unique roadmaps through this data structure. 

- We'll do this by trying to create a new data structure, mapping the following key value pairs.
- In this case, We will store the string, to be the name of a university. 
- And the key is going to be the year when that university was founded which are going to be four digits. 
- We'll use those four digits to navigate through this data structure. 
- At the end of the path, we'll see the name of the university that corresponds to that key, those four digits. 

1. Lets map key-value paids where the keys are four-digit years (YYYY) and the values are names of universities founded during those years.
2. In a trie, the paths from a central root node to a leaf node (where the school names would be), would be labeled with digits of the year.
3. Each node on the path from root to leaf could have 10 pointers emanating from it, one for each digit.

**Analogy**
- The basic idea behind a trie is we have a central route. 
- So think about it like a tree. 
- And this is similar in spelling and in concept to a tree. 
- Generally when we think about trees in the real world, they have a root that's in the ground and they grow upward and they have branches and they have leaves. 
- The idea of a trie is exactly the same, except that root is anchored somewhere in the sky and the leaves are at the bottom. 
- So it's kind of like taking a tree and just flipping it upside down. But there are still branches. And those would be our pathways, those will be our connections from the root to the leaves. 
- In this case, those paths, those branches are labeled with digits that tell us which way to go from where we are. 
- If we see a 0, we go down this branch, if we see a 1, we go down this branch, and so and so on. 
- That means that at every junction point and every node in the middle and every branch, there are 10 possible places that we can go. 
- So there are 10 pointers from every location. 

## inserting an element into the trie
- To insert an element into the trie, we need to build the correct path from the root to the leaf. 
Here's what every step along the way might look like:
```
typedef struct _trie
{
    char university[20];
    struct _trie* paths[10];
}
trie;
```

- We define a new data structure for a new node called a trie;. 

- Inside of that data structure there are two pieces. 
1. We're going to store the name of a university.
    - char university[20];
2. And we're going to store an array of pointers to other nodes of the same type. 
    - struct _trie* paths[10];

- This is that sort of concept of everywhere we are, we have 10 possible places we can go. 
- If we see a 0, we go down this branch, If we see a 1, this branch, and so on. 
- If we say 9, we go down this branch. 
- So at every junction point, we can go 10 possible places. 
- So every node has to contain 10 pointers to other nodes, to 10 other nodes. 
- The data we're storing is just the name of the university which we have 20 of.

### building a trie
- Insert a couple of items into our trie. 
- So at the very top, this is our root node. 
- This is going to be something you're going to globally declare. 
- And you're going to globally maintain a pointer to this node always. 
```
tries = [root node]
[][][][][][][][][][][]
```
- You're going to say, root equals, and you're going to malloc yourself trie node. 
- And you're never going to touch root again. 
- Every time you want to start navigating through, you set another pointer equal to root, such as trav, which is the example I use in many of my videos here on stacks and queues and link lists and so on. 
- You set another pointer called trav for traversal. 
- And you use trav to navigate through the data structure. 
- So let's see how this might look:
- So right now, what does a node look like? 
- Well, just as our data structure declaration indicated, we have a string, which in this case is empty.  
- And an array of 10 pointers. 
- And right now, we only have 1 node in this trie. 
- There's nothing else in it. 
- So all 10 of those pointers point to null.

**Insert Harvard**
- Let's insert the University of Harvard into this trie, which was founded in the year 1636. 
- We want to use the key, 1636, to tell us where we're going to store Harvard in the trie.

- We start at the root. And we have these 10 places we can go.

Where do we want to go if the key is 1636? There's really two options.
1. We can build the key from right to left and start with 6. 
2. Or we could build the key from left to right and start with 1. 

- It's probably more intuitive as a human being to understand we'll just go left to right.
- 1 path is currently null. If I want to proceed down that path to insert this element into the trie, I have to malloc a new node, have 1 point there. 
```
[][1][][][][][][][][][]
```
- 1 no longer points to null, it points to a new array of the new node. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][][][][][]
```
- We want to go down the 6.
- There is 10 locations I can choose.
- We go to 6 and build another node. And I've reached another junction point. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][]
[][][][][][][][][][][]
```
- Again, I have 10 choices for where I can go. 
- I've moved from 1 to 6. 
- So now I probably want to go to 3. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][]
[][][][3][][][][][][][]
```
- After 3, there's nowhere I can go. 
- So I have to clear the way and build myself a new space. 
- And then from 3, where do I want to go? 
- I want to go down 6. 
- And, again, I had to clear the way to do it.
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][]
[][][][3][][][][][][][]
[][][][][][][6][][][][]

```
- So now I've used my key to insert create nodes and start to build this trie. 
- I've started at the root. 
- I've gone down 1636. 
- And now I'm at the bottom there on that node.
- My key is done, its exhausted every position in my key so I can't go any further. 
- So at this point, we are looking at Harvard at the last location. 
- If we start at the root and we go down 1 and then 6 and then 3 and then 6, where are we? Well if we look down and we see Harvard, then we know that Harvard was founded in 1636 based on the way we're implementing this data structure. 


**Two more insertions:**
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][]
[][][][3][][][][][][][]
[][][][][][][6][][][][]
[Harvard]

```

**Insert Yale**
- Let's insert Yale founded in 1701 into this trie.
- So we'll start at the root, as we always do. 
- And we set a traversal pointer. 
    - We're going to use that to move through. 
- The first thing we want to do is go down the 1 path. 
- That's the first digit of our key. 
- Fortunately, though, we don't have to do any work this time. 
- The 1 path has already been cleared previously when I was inserting Harvard at 1636. 
- So I can safely move down 1 and just go there. 

- Now I want to go to 7. 
- I cleared the way at 6. I know I can safely proceed down the 6 path. 
- But I need to proceed on the 7 path.
- Well, just like before, I just need to clear the gate, get out of the way, and build a new node from the 7 path. Just like this.
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][] | [][][][][][][][7][][]
[][][][3][][][][][][][]
[][][][][][][6][][][][]
[Harvard]

``` 
- So now I've moved 1 and then 7. And now notice were at this new subbranch.
- There's no paths forward from here. So I have to make one myself. 
- So I malloc a new node and have 0 point there. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][] | [][][][][][][][7][][]
[][][][3][][][][][][][] | [0][][][][][][][][][]
[][][][][][][6][][][][]
[Harvard]

``` 
- And then one more time, I malloc a new node and have one point there. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][] | [][][][][][][][7][][]
[][][][3][][][][][][][] | [0][][][][][][][][][]
[][][][][][][6][][][][] | [][1][][][][][][][][]
[Harvard] [Yale]

``` 
- Again, I've exhausted my key, 1701. 
- So I look down and I see Yale, the name of this node. 
- If I ever need to see if Yale is in this trie, I start at the root, I go down 1701, and look down. 
- And if I see Yale, then I know Yale exists in this trie. 

**Insert Dartmouth**
- Let's do one more. Let's insert Dartmouth founded in 1769 into this trie.
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][] | [][][][][][][][7][][]
[][][][3][][][][][][][] | [0][][][][][][][][][]
[][][][][][][6][][][][] | [][1][][][][][][][][]
[Harvard] [Yale]
``` 
- Start at the root again. 
- My first digit of my key is 1, I can safely move down that path. - The next digit of my key is 7, I can safely move down that path.
- My next is 6. 
- 6 is currently locked off. If I want to go down that path, I have to build it myself. 
- So I'll malloc a new node and have 6 point there. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][] | [][][][][][][][7][][]
[][][][3][][][][][][][] | [0][][][][][][][][][] | [][][][][][6][][][]
[][][][][][][6][][][][] | [][1][][][][][][][][]
[Harvard] [Yale]
``` 
- So I then malloc a new node so that from that node-- path number 9.
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][] | [][][][][][][][7][][]
[][][][3][][][][][][][] | [0][][][][][][][][][] | [][][][][][6][][][]
[][][][][][][6][][][][] | [][1][][][][][][][][] | [][][][][][][][][9]
[Harvard] [Yale]
``` 
- If I travel 1769, and I look down. There's nothing currently there. 
- We have to write Dartmouth. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][] | [][][][][][][][7][][]
[][][][3][][][][][][][] | [0][][][][][][][][][] | [][][][][][6][][][]
[][][][][][][6][][][][] | [][1][][][][][][][][] | [][][][][][][][][9]
[Harvard] [Yale] [Darthmouth]
``` 
- And I've inserted Dartmouth into the trie. 
- So that's inserting things into the trie. 

## Searching for an element in the trie.
- How do we search for things in the trie? 
- Well, it's pretty much the same idea. 
- Now we just use the digits of the key to see if we can navigate from the root to where we want to go in the trie. 
- If we hit a dead end at any point, then we know that that element can't exists or else that path would have already been cleared. 
- If we make it all the way to the end, all we need to do is look down and see if that's the element we're looking for. 
- If it is, success. If it's not, fail. 

***Search for Harvard**
- So let's search for Harvard in this trie. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][] | [][][][][][][][7][][]
[][][][3][][][][][][][] | [0][][][][][][][][][] | [][][][][][6][][][]
[][][][][][][6][][][][] | [][1][][][][][][][][] | [][][][][][][][][9]
[Harvard] [Yale] [Darthmouth]
``` 
- We start at the root. 
- We're going to create a traversal pointer to do our moves for us. 
- From the root we know that the first place we need to go is 1, can we do that? 
- Yes, we can, so we can go there. 

- The next place we need to go is 6. Does the 6 path exist from here? Yes, We can go down the 6 path.
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][]
[][][][3][][][][][][][] | [0][][][][][][][][][] | [][][][][][6][][][]
[][][][][][][6][][][][] | [][1][][][][][][][][] | [][][][][][][][][9]
[Harvard] [Yale] [Darthmouth]
``` 
- Can we go down the 3 path from here? Yes, that exists too. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][]
[][][][3][][][][][][][]
[][][][][][][6][][][][] | [][1][][][][][][][][] | [][][][][][][][][9]
[Harvard] [Yale] [Darthmouth]
``` 
- And can we get on the 6 path from here? Yes, we can. 
```
tries = [root node]
[][1][][][][][][][][][]
[][][][][][][6][][][][]
[][][][3][][][][][][][]
[][][][][][][6][][][][]
[Harvard] 
``` 
- We haven't quite answered the question yet. 
- There's still one more step, which is now we need to look down and see if that's actually-- if we're looking for Harvard, is that what we find after we exhaust the key? 
- In the example we're using here, the years are always four digits. 
- But you might be using the example where you are storing a dictionary of words. 

- And so instead of having 10 pointers for my location, you might have 26. 
- One for each letter of the alphabet. 
- And there are some words like bat, which is a subset of batch, for example. And so even if you get to the end of the key and you look down, you might not see what you're looking for. 
- So you always have to traverse the entire path and then if you were successfully able to traverse the entire path, look down and do one final confirmation. 
- Is that what I'm looking for? Well, I look down after starting at the top and going 1636. I look down. I see Harvard. So, yes, I succeeded.
- What if what I'm looking for isn't in the trie, though. What if I'm looking for Princeton, which was founded in 1746. And so 1746 becomes my key to navigate through the trie. Well, I start at the root. And the first place I want to goes down the 1 path. Can I do it? Yes, I can. 

Can I go down the 7 path from there? Yeah, I can. That exists too. But can I go down the 4 path from here? That's like asking the question, can I proceed down that little square that I've highlighted in yellow? There's nothing there. Right. 

There's no way forward down the 4 path. If Princeton was in this trie, that 4 would have been cleared for us already. And so at this point we've reached a dead end. We can't go any further. And so we can say, definitively, no. Princeton does not exist in this trie. 

So what does this all mean? Right. There's a lot going on here. There's pointers all over the place. And, as you can see just from the diagram, there's a lot of nodes that are kind of flying around. But notice every time we wanted to check whether something was in the trie, we only had to make 4 moves. 

Every time we wanted to insert something in the trie, we have to make 4 moves, possibly mallocing some stuff along the way. But as we saw when we inserted Dartmouth into the trie, sometimes some of the path might already be cleared for us. And so as our trie gets bigger and bigger, we have do less work every time to insert new things because we've already built a lot of the intermediate branches along the way. If we only ever have to look at 4 things, 4 is just a constant. We really are kind of approaching constant time insertion and constant time lookup. The tradeoff, of course, being that this trie, as you can probably tell, is huge. Each one of these nodes takes up a lot of space. 

But that's the tradeoff. If we want really quick insertion, really quick deletion, and really quick lookup, we have to have a lot of data flying around. We have to set aside a lot of space and memory for that data structure to exist. 

- We might have found that holy grail of data structures with quick insertion, deletion, and lookup. 
- And maybe this will be an appropriate data structure to use for whatever information we're trying to store. 