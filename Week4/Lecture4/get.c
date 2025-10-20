// #include <cs50.h>
// #include <stdio.h>

// int main(void)
// {
//     int n;
//     printf("n: ");
//     scanf("%i", &n);
//     printf("n: %i\n", n);
// }

#include <stdio.h>

int main(void)
{
    char *s; // Contains a garbage value.
    printf("s: ");
    scanf("%s", s); // Dangerous because it wont know where the string will end.
    printf("s: %s\n", s);
}
