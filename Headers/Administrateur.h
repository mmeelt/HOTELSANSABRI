#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Utilisateur.h"

class Administrateur : virtual public Utilisateur {
public:
    Administrateur(string nom, string prenom, int age, int id, string& username, string& mdp) : Utilisateur(nom, prenom, age, id, username, mdp) {}
    virtual ~Administrateur();
    
    void createUser(string nom, string prenom, int age, int id, string& username, string& password, string& role, Archive& archive);
    void readUser(string& username,Archive& archive);
    void updateUser(string& username, string& newPassword, Archive& archive);
    void deleteUser(string& username, Archive& archive);

};
#endif // ADMINISTRATEUR_H