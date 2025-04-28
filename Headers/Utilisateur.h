#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "Personne.h"
#include <string>

class Utilisateur : public Personne
{
protected:
    int id;
    string username;
    string mdp;

public:
    // Constructors and Destructor
    Utilisateur() = default; // Default constructor
    Utilisateur(string nom, string prenom, int age, int id, string &username, string &mdp) : Personne(nom, prenom, age), id(id), username(username), mdp(mdp) {};
    ~Utilisateur();

    // CRUD Methods
    int getId() const;
    void setId(int id);

    string getUsername() const;
    void setUsername(string &username);

    // Getters and Setters for mdp
    string getMdp() const;
    void setMdp(string &mdp);


    // Functional Methods
    void afficherProfil() const;
    bool login(string &username, string &mdp);
    void logout();
    bool modifierMDP(string &ancienmdp, string &nouveaumdp);

    

    // Overload the << operator
    friend std::ostream &operator<<(std::ostream &os, const Utilisateur &utilisateur)
    {
        os << "ID: " << utilisateur.id << "\n"
           << "Username: " << utilisateur.username << "\n"
           << "Nom: " << utilisateur.nom << "\n"
           << "Prenom: " << utilisateur.prenom << "\n"
           << "Age: " << utilisateur.age;
        return os;
    }
};

#endif // UTILISATEUR_H