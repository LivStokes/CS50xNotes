# Week3
## Algorithms
This week focuses on Algorithms, learning about various topics including:
- Linear search
- Binary search
- Bubble sort
- Selection sort
- Merge sort
- Asymptotic notation
- Recursion

## Shorts
The shorts were focused upon topics such as:
- Binary search
- Bubble sort
- Call stacks
- Linear search
- Merge sort
- Recursion
- Selection sort

## Project
This week had 3 projects:
1. Plurality
2. Runoff
3. Sort

### Plurality
- The Plurality problem requires implementing the simplest form of an election: every voter chooses one candidate, and the one with the most votes wins (even without a majority).
- The key concepts and techniques used involved:
- Custom Data Structures (structs). Defining and using the candidate struct to logically pair a candidate's name (string) with their votes (integer).
- String Comparison. Correct usage of the strcmp function from <string.h> within the vote function to validate and tally votes based on an exact name match.
- Command-Line Arguments. Handling and parsing argc and argv in main to dynamically initialize the list of candidates.
- Modular Programming. Implementing and calling custom functions (vote and print_winner) to decompose the election logic.

### Runoff
- The Runoff problem requires building a program to simulate an Instant Runoff Voting (IRV) election system. This system is a form of ranked-choice voting that resolves the shortcomings of simple plurality, where a winner might lack majority support. Voters rank candidates by preference. The election proceeds in rounds until one candidate achieves a majority (over 50%) of the active votes.
- The key concepts and techniques used involved:
- Complex Data Storage. A multi-dimensional array is needed to store the voters' ranked preferences, tracking the order they chose for all candidates. A struct is essential for each candidate to hold their name, vote count, and an elimination status (a boolean flag).
- Iterative Logic. The core is a loop that continues until a winner is found.
- This process involves advanced array manipulation and careful use of conditional logic to handle eliminations and vote redistribution correctly.

### Sort
- The sort problem is an excersize in analyzing the time complexity of sorting algorithms. Identifying the sorting algorithm for each program based on how its execution time changes with different input states (sorted vs. reversed).
- The key to solving this problem is understanding the Big O notation for the best-case (sorted input) and worst-case (reversed input) scenarios for each algorithm.
- Key consepts and techniques used:
- Observing Sensitivity to Input Order. By timing the execution on the two extreme input types (sorted vs. reversed), I measured how sensitive the algorithm's performance is to the initial order of the data.