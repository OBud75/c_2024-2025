template <typename T>
void swap(T *ptr_a, T *ptr_b) {
    T temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}


// python : a, b = b, a