#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Utilisateur.h"
#include <vector>
#include <iostream>

using namespace std;

class Administrateur : public Utilisateur {
private:
    string role;  // Specific attribute for Administrateur

public:
    // Constructors
    Administrateur();
    Administrateur(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp, const string& role);

    // Copy Constructor
    Administrateur(const Administrateur& other);

    // Destructor
    virtual ~Administrateur();

    // CRUD Methods
    void modifierAdministrateur(vector<Administrateur*>& administrateurs, int idRecherche);
    void supprimerAdministrateur(vector<Administrateur*>& administrateurs, int idRecherche);

    // Specific Methods
    void gererAcces(Utilisateur* utilisateur);
    void assignerRole(Utilisateur* utilisateur, const string& nouveauRole);

    // Getter and Setter
    string getRole() const;
    void setRole(const string& role);

    // Overloaded Operators
    friend ostream& operator<<(ostream& os, const Administrateur& admin);
    friend istream& operator>>(istream& is, Administrateur& admin);

    // Override afficherProfil
    void afficherProfil() const override;
};

#endif // ADMINISTRATEUR_H
