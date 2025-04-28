#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "Personne.h"
#include <string>
#include <fstream> // ADD THIS for file management

class Utilisateur : public Personne
{
protected:
    int id;
    std::string username;
    std::string mdp;

public:
    // Constructors and Destructor
    Utilisateur() = default; // Default constructor
    Utilisateur(std::string nom, std::string prenom, int age, int id, std::string &username, std::string &mdp) 
        : Personne(nom, prenom, age), id(id), username(username), mdp(mdp) {}
    ~Utilisateur();

    // CRUD Methods
    int getId() const;
    void setId(int id);

    std::string getUsername() const;
    void setUsername(std::string &username);

    std::string getMdp() const;
    void setMdp(std::string &mdp);

    // Functional Methods
    void afficherProfil() const;
    bool login(std::string &username, std::string &mdp);
    void logout();
    bool modifierMDP(std::string &ancienmdp, std::string &nouveaumdp);

    // ✅ File management methods you asked for
    void ecrireDansFichier(std::ofstream& fichier) const;
    void lireDepuisFichier(std::ifstream& fichier);

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
