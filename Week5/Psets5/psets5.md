// Data structure that lets us represent the connection between people and their parents. As else what allees they have in their blood type.
// There are 2 people in the structs array. 

typedef struct person // creating a structure of a person
{
    struct person *parents[2]; // Every person has an array of two parents. Each of those parents are a pointer to another person.
    char alleles[2]; // there is every person representing which two alleles A, B, O this particular person has. Because each person has two alleles, this person is an array of size 2 to represent both of those alleles.
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

Alleles are different versions of the same gene, with variations in their DNA sequence.