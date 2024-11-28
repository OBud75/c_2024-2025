#include "password.hpp"

Password::Password(std::string &password, bool is_encrypted=false) : _raw_value(password) {}

void Password::encrypt(const std::string &password) {}

std::string Password::str() {
        return _encrypted_value;
}

bool Password::operator==(const std::string &str) const {
    return str == _encrypted_value;
}

bool Password::operator==(const Password &other) const {

}

std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p._encrypted_value;
    return os;
}
