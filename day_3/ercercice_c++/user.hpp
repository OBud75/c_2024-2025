#include <memory>

class Password;

class User {
    private:
        int id;
        std::unique_ptr<Password> password;
        bool is_logged_in;

    public:
        explicit User(int id, Password &password);
        void save();
        int login(char *raw_password);
        static User &get(int id);
};
