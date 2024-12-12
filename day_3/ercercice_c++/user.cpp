#include "user.hpp"

User::User(int id, Password &password):
    id(id), password(&password) {
        is_logged_in = false;
    };

void User::save() {
    // In a file (or DB)
    // id | password (hashed)
};

int User::login(char *raw_password) {
    // Compare raw_password with password in DB
    // for user with id this.id
    is_logged_in = true; // If passwords match
};

User& User::get(int id) {
    // Read file
    // if id of row == id:
    // get raw data
    // password = Password(raw[password], is_encrypted=true)
    // return User(raw[id], password)
};
