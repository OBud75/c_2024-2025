#include <iostream>
#include <string>

using namespace std;

int *get_back_value_ptr(int *str) {
    printf("get_back_value_ptr: %p\n", str);
    return str;
}
int *get_back_value_ref(int &str) {
    printf("get_back_value_ref: %p\n", &str);
    return &str;
}
int *get_back_ref_rvalue(int &&str) {
    printf("get_back_ref_rvalue: %p\n", &str);
    return &str;
}

int get_right_value() {
    auto s = 25;
    printf("rvalue prête à être détruite: %p\n", &s);
    return s;
}

int *get_right_value_address() {
    auto s = 25;
    printf("rvalue prête à être détruite: %p\n", &s);
    return std::move(&s);
}

int main() {
    auto left_value_copy = get_right_value();
    get_back_value_ptr(&left_value_copy);
    get_back_value_ref(left_value_copy);
    get_back_ref_rvalue(move(left_value_copy));
    printf("\n");

    auto left_value_originale = get_right_value_address();
    get_back_value_ptr(left_value_originale);
    get_back_value_ref(*left_value_originale);
    get_back_ref_rvalue(move(*left_value_originale));
    return 0;
}
