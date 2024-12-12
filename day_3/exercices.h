typedef struct Person {
    int age;
} Person;
int are_persons_equals(Person *p1, Person *p2) {};

typedef struct Book {
    int pages;
} Book;
int are_books_equals(Book *b1, Book *b2) {};

int are_equals(
    void *obj1, void *obj2,
    int (*compare_fnc)(void *, void *)) {};

int is_greater(
    // return 1 if obj1 is greater than obj2
    void *obj1, void *obj2,
    int (*compare_fnc)(void *, void *)) {};

void swap(void *obj1, void *obj2, size_t size) {};

void sort(
    void *array[],
    int nb_of_elems_in_array,
    size_t elem_size,
    int (*compare_fnc)(void *, void *),
    int (*swap_fnc)(void *, void *, int)){};

int is_in_array(void *obj_to_find,
                void *array[],
                int nb_of_elems_in_array,
                size_t elem_size,
                int (*compare_fnc)(void *, void *)) {
    // Linear search algorythm
    // *p = pointeur vers le début de l'array
    // Tant que i < nb elements dans l'array
    //     if (compare_fcn(obj_to_find, *p))
    //        return 1
    //     Avancer le pointeur de elem_size
    //     i ++
}