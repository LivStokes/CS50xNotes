In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.

A 1
B 3
C 3
D 2
E 1
F 4
G 2
H 4
I 1
J 8
K 5
L 1
M 3
N 1
O 1
P 3
Q 10
R 1
S 1
T 1
U 1
V 4
W 4
X 8
Y 4
Z 10

For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. Summing these, we get that “CODE” is worth 7 points.

In a file called scrabble.c in a folder called scrabble, implement a program in C that determines the winner of a short Scrabble-like game. Your program should prompt for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).

Demo

Advice
Click the below toggles to read some advice!

Write some code that you know will compile
Write some pseudocode before writing more code
Some problems in problem sets, like this one, might contain spoilers (like the next one) that ultimately walk you through the entire solution. While you are permitted to use this code, we really do strongly encourage you to try things out yourself first! The other problems in the problem set won’t have this sort of walkthrough, and typically the problem that contains the “full spoiler” is a warm-up version of the bigger problem you’ll later need to tackle.

Convert the pseudocode to code
How to Test
Your program should behave per the examples below.

$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
$ ./scrabble
Player 1: red
Player 2: wheelbarrow
Player 2 wins!
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!
Correctness
In your terminal, execute the below to check your work’s correctness.

check50 cs50/problems/2025/x/scrabble
Style
Execute the below to evaluate the style of your code using style50.

style50 scrabble.c
How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2025/x/scrabble