#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "Personne.h"
#include <vector>
#include <iostream>

using namespace std;

class Utilisateur : public Personne {
protected:
    vector<int*> id;  // Dynamic vector of integer pointers
    string username;
    string mdp;

public:
    // Constructors
    Utilisateur();
    Utilisateur(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp);

    // Copy Constructor
    Utilisateur(const Utilisateur& other);

    // Destructor
    virtual ~Utilisateur();

    // CRUD Methods (only modify and delete now)
    void modifierUtilisateur(vector<Utilisateur*>& utilisateurs, int idRecherche);
    void supprimerUtilisateur(vector<Utilisateur*>& utilisateurs, int idRecherche);

    // Specific Methods
    virtual void afficherProfil() const;
    bool login(const string& username, const string& mdp) const;
    void logout() const;
    void modifierMDP(const string& ancienMDP, const string& nouveauMDP);

    // Getters and Setters
    vector<int*> getId() const;
    void addId(int idValue);
    void clearIds();

    string getUsername() const;
    void setUsername(const string& username);

    string getMDP() const;
    void setMDP(const string& mdp);

    // Surcharge operators
    friend ostream& operator<<(ostream& os, const Utilisateur& u);
    friend istream& operator>>(istream& is, Utilisateur& u);
    bool operator==(const Utilisateur& other) const;
};

#endif // UTILISATEUR_H
