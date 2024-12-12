template <typename T>
void swap(T *ptr_a, T *ptr_b) {
    T temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}


// python : a, b = b, a

class Person {
    private:
        int age;

    public:
        int get_compare_value() {
            return age;
        }
};

class Book {
    private:
        int pages;

    public:
        int get_compare_value() {
            return pages;
        }
};

class Comparable {
    public:
        virtual int get_compare_value() {
            return false;
        }
};

bool are_equals(Comparable *obj1, Comparable *obj2) {
    return obj1->get_compare_value() == obj2->get_compare_value();
};
