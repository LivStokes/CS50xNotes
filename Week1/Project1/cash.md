customer gives you $1.00 (100 cents).
candy that costs $0.50 (50 cents). 
You’ll need to pay them their “change,” (leftover).
When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out.
In a file called cash.c in a folder called cash, 
Implement a program in C that prints the minimum coins needed to make the given amount of change, in cents, 

as in the below:
quarters (25¢), 
dimes (10¢), 
nickels (5¢), and 
pennies (1¢).

The problem to be solved is to decide which coins and how many of each to hand to the customer.
E.g. 
if some customer is owed 41¢
biggest bite is 25$
42 - 25 = 16
so next biggest is 10$
16 - 10 = 6
next biggest is 5$
6 - 5 = 1
next biggest is 1.
So in total we need, 25$, 10$, 5$, 1$.
Which concludes to 4 coins in total.

Prompt the user for change owed, in cents.
Calculate how many quarters you should give customer. Subtract the value of those quarters from cents.
Calculate how many dimes you should give customer. Subtract the value of those dimes from remaining cents.
Calculate how many nickels you should give customer. Subtract the value of those nickels from remaining cents.
Calculate how many pennies you should give customer. Subtract the value of those pennies from remaining cents.
Sum the number of quarters, dimes, nickels, and pennies used.
Print that sum.
