#include "password.hpp"


int main() {
	auto password = std::make_unique<Password>("123456", false);
	assert(*password == "123456");
	std::cout << (*password == "123456") << std::endl;

	auto saved_password = password->str();
	auto password2 = std::make_unique<Password>(saved_password, true);
	assert(*password == *password2);
	return 0;
}
