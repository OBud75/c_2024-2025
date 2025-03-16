#include "user.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

User::User(int id, Password &password) : id(id), password(&password)
{
    is_logged_in = false;
};

void User::save()
{
    std::ofstream file("users.txt", std::ios::app);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open users.txt for writing");
    }

    file << id << " | " << password->str() << "\n";
    file.close();
}

int User::login(const char *raw_password)
{
    std::ifstream file("users.txt");
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open users.txt for reading");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        int file_id;
        std::string encrypted_password;
        char delim;

        stream >> file_id >> delim >> encrypted_password;
        if (file_id == id)
        {
            std::cout << "Matching user ID found. Checking password...\n";
            Password stored_password(encrypted_password, true);
            Password input_password(raw_password, false);
            if (stored_password == input_password.str())
            {
                std::cout << "Password is correct. Login successful.\n";
                is_logged_in = true;
                return 1;
            }
        }
    }

    file.close();
    return 0;
}

User &User::get(int id)
{
    std::ifstream file("users.txt");
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open users.txt for reading");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        int file_id;
        std::string encrypted_password;
        char delim;

        stream >> file_id >> delim >> encrypted_password;
        if (file_id == id)
        {
            Password *password = new Password(encrypted_password, true);
            file.close();
            return *new User(file_id, *password);
        }
    }

    file.close();
    throw std::runtime_error("User not found");
    // C'est ca !
    // Sans new, on crée un objet sur la pile (stack)
    // et on retourne une copie de cet objet
    // l'objet original est détruit à la fin de la fonction
    // donc retourner un pointeur vers celui ci mène à un comportement indéfini

    // Avec new, on crée un objet sur le tas (heap)
    // et on retourne un pointeur vers cet objet
    // l'objet ne sera détruit que si on appelle delete sur le pointeur.

    // Ca rejoint l'idée du lifetime des objets qu'on retrouve en Rust.
    // Pour aller plus loin si C++ et le fonctionnement de la mémoire vous interesse,
    // regardez plus en profondeur les pointeurs uniques, partagés et faibles.
    // Aussi, la fonction std::move qui permet de retourner un objet "original" sans copie.
}



// Si on veut aller un peu plus loin dans les tests:
// tests fonctionnels:
// tester la fonction save à part:
// On créé un utilisateur, on le sauvegarde,
// puis on le récupère mais sans passer par la fonction get et on compare.
// Pareil pour get, l'idée serait d'avoir un utilsateur déjà créé dans la base (sans passer par save)

// Puis vient ce que vous avez fait qui est plus un test d'intégration
// où on teste l'ensemble des fonctionnalités ensemble.

// Pour l'exercice en C, une fonction main qui prouve que tout fonctionne bien aurait été bienvenue.
