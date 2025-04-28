#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Utilisateur.h"
#include <memory> // For smart pointers

class Administrateur : virtual public Utilisateur {
public:
    Administrateur(string nom, string prenom, int age, int id, string& username, string& mdp) 
        : Utilisateur(nom, prenom, age, id, username, mdp) {}
    virtual ~Administrateur();
    
    void createUser(string nom, string prenom, int age, int id, string& username, string& password, string& role, std::unique_ptr<Archive>& archive);
    void readUser(string& username, std::unique_ptr<Archive>& archive);
    void updateUser(string& username, string& newPassword, std::unique_ptr<Archive>& archive);
    void deleteUser(string& username, std::unique_ptr<Archive>& archive);
};

#endif // ADMINISTRATEUR_H