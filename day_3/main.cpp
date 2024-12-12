#include <iostream>
#include <memory>

typedef struct Person {
    int age;
} Person;

void persons() {
    Person person = {};
    Person &p2 = person;
    person.age = 10;
    std::cout << p2.age << std::endl;
    p2.age = 14;
    std::cout << person.age << std::endl;
    Person *p3 = &person;
    p3->age = 900;
    p3 = 0;
}

Person *make_person() {
    auto p = Person {};
    p.age = 10;
    Person *p_ptr = &p;
    // p_ptr pointer vers p vivant à l'adress 1
    return std::move(p_ptr);
};

int main() {
    char c = 'z';
    char *p = &c;
    char &r = c;
    auto unique_person = std::make_unique<Person>;
    auto shared_person = std::make_shared<Person>;
    auto &shared_person_2 = shared_person;
    // toto pointer vers p
    Person *toto = make_person();
};
