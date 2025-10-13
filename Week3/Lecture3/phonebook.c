#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{Lec
    string name;
    string number;
} person;

int main(void)
{
    person people[3];

    people[0].name = "David";
    people[0].number = "+1-617-495-1000"; // Use the . operator if you want to go inside it and access the things that compose it, like name and number.

    people[1].name = "John";
    people[1].number = "+1-949-468-2750";

    people[2].name = "Yuliia";
    people[2].number = "+1-617-495-1000";

    string name = get_string("Name: "); // Prompt for name
    for (int i = 0; i < 3; i++) // Looking thorugh te string
    {
        if (strcmp(people[i].name, name) == 0) // If return value of strcmp
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}