#include "exercices.h"
#include <stdio.h>

void eq_function() {
    Person person1 = {50};
    Person person2 = {0};
    int same_age = are_equals(
        &person1, &person2,
        (int (*)(void *, void *)) are_persons_equals
    );
    if (same_age == 1) {printf("Same age.\n");};
}
void linear_search() {
    Person person1 = {50};
    Person people[] = {{20}, {50}};
    int found = is_in_array(
        &person1, &people,
        sizeof(people) / sizeof(Person), sizeof(Person),
        (int (*)(void *, void *)) are_persons_equals
    );
    if (found == 1) {printf("P1 is in the array.\n");};
    Book book1 = {50};
    Book books[] = {{20}, {50}};
    int found = is_in_array(
        &book1, &books,
        sizeof(books) / sizeof(Book), sizeof(Book),
        (int (*)(void *, void *)) are_books_equals
    );
    if (found == 1) {printf("B1 is in the array.\n");};
}
void generic_swap() {
    Person person1 = {50};
    Person person2 = {25};
    swap(&person1, &person2, sizeof(Person));
    Book b1 = {50};
    Book b2 = {25};
    swap(&b1, &b2, sizeof(Book));
};

int main() {
    eq_function();
    linear_search();
    generic_swap();
    Person people[] = {{20}, {50}, {188}, {2}};
    sort(
        &people,
        sizeof(people) / sizeof(Person),
        sizeof(Person),
        is_greater,
        swap
    );
}
