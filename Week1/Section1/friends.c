#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Name
    string name = get_string("What is your name? ");

    // Age
    int age = get_int("What is your age? ");

    // Hometown
    string hometown = get_string("What is your hometown? ");


    // Phone Number
    string number = get_string("What is your number? ");

    printf("My new frineds name is %s, %i, they are from %s and their phone number is %s\n", name, age, hometown, number);
}


