#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%.50f\n", (float) x / y);
    // %f → means “print a floating-point number” (decimal number).
    // .50 → means “show 50 digits after the decimal point.”
    // (float) → explicitly casts x to a float type, so the division is not integer division.
    // / → divides x by y.
}