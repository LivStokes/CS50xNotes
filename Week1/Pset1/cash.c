#include <cs50.h>
#include <stdio.h>
#include <math.h>

int coinCalculation(float change);

int main(void)
{
    float change;

    // Prompt for users change owed.
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    // The result of the calculation is stored in the local 'coins' variable.
    int coins = coinCalculation(change);

    // Prints total number of coins as an integer.
    printf("%i\n", coins);
}

int coinCalculation(float change)
{

    // Converts change to cents.
    int cents = round(change);
    // round() from the math.h library, rounds the value to the nearest integer.

    // Declaration of coins values.
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;

    int coins = 0;

    // Coins calculation per coin.
    coins += cents / quarters;
    cents = cents % quarters;

    coins += cents / dimes;
    cents = cents % dimes;

    coins += cents / nickels;
    cents = cents % nickels;

    coins += cents / pennies;
    cents = cents % pennies;

    // Return the final count to main.
    return coins;
}
