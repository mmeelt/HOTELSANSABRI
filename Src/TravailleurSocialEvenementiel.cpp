#ifndef TRAVAILLEURSOCIALEVENEMENTIEL_H
#define TRAVAILLEURSOCIALEVENEMENTIEL_H

#include "TravailleurSocial.h"
#include "RespEvenementiel.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"
#include <vector>
#include <iostream>

using namespace std;

class TravailleurSocialEvenementiel : public TravailleurSocial, public RespEvenementiel {
public:
    // Constructors
    TravailleurSocialEvenementiel();
    TravailleurSocialEvenementiel(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp);

    // Copy Constructor
    TravailleurSocialEvenementiel(const TravailleurSocialEvenementiel& other);

    // Destructor
    virtual ~TravailleurSocialEvenementiel();

    // CRUD methods
    void modifierTravailleurSocialEvenementiel(vector<TravailleurSocialEvenementiel>& list, int idRecherche);
    void supprimerTravailleurSocialEvenementiel(vector<TravailleurSocialEvenementiel>& list, int idRecherche);

    // Specific Methods
    void inscrireAUneFormation(SansAbri s, Formation* f);
    void inscrireAUneAtelier(SansAbri s, Atelier* a);

    void planifierEvenement(Evenement* evenement);
    void annulerEvenement(Evenement* evenement);
    void modifierEvenement(Evenement* evenement);
    void ajouterEvenement(Evenement* evenement);
    void supprimerEvenement(Evenement* evenement);

    // Operator Overloading
    friend ostream& operator<<(ostream& os, const TravailleurSocialEvenementiel& tse);
    friend istream& operator>>(istream& is, TravailleurSocialEvenementiel& tse);
    bool operator==(const TravailleurSocialEvenementiel& other) const;  // New overload for ==
};

#endif // TRAVAILLEURSOCIALEVENEMENTIEL_H


#include "TravailleurSocialEvenementiel.h"

// Constructors
TravailleurSocialEvenementiel::TravailleurSocialEvenementiel() : TravailleurSocial(), RespEvenementiel() {}

TravailleurSocialEvenementiel::TravailleurSocialEvenementiel(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp)
    : Utilisateur(idValue, nom, prenom, age, username, mdp), TravailleurSocial(idValue, nom, prenom, age, username, mdp), RespEvenementiel(idValue, nom, prenom, age, username, mdp) {}

// Copy Constructor
TravailleurSocialEvenementiel::TravailleurSocialEvenementiel(const TravailleurSocialEvenementiel& other)
    : Utilisateur(other), TravailleurSocial(other), RespEvenementiel(other) {}

// Destructor
TravailleurSocialEvenementiel::~TravailleurSocialEvenementiel() {}

// CRUD Methods
void TravailleurSocialEvenementiel::modifierTravailleurSocialEvenementiel(vector<TravailleurSocialEvenementiel>& list, int idRecherche) {
    for (auto& tse : list) {
        if (tse.getId() == idRecherche) {  // Corrected comparison
            cout << "TravailleurSocialEvenementiel found: " << tse << endl;
            cout << "Modify information:" << endl;
            cin >> tse;
            return;
        }
    }
    cout << "TravailleurSocialEvenementiel not found!" << endl;
}

void TravailleurSocialEvenementiel::supprimerTravailleurSocialEvenementiel(vector<TravailleurSocialEvenementiel>& list, int idRecherche) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->getId() == idRecherche) {  // Corrected comparison
            list.erase(it);
            cout << "TravailleurSocialEvenementiel deleted!" << endl;
            return;
        }
    }
    cout << "TravailleurSocialEvenementiel not found!" << endl;
}

// Specific Methods
void TravailleurSocialEvenementiel::inscrireAUneFormation(SansAbri s, Formation* f) {
    RespEvenementiel::inscrireAUneFormation(s, f); // Call to RespEvenementiel method
}

void TravailleurSocialEvenementiel::inscrireAUneAtelier(SansAbri s, Atelier* a) {
    RespEvenementiel::inscrireAUneAtelier(s, a);
}

void TravailleurSocialEvenementiel::planifierEvenement(Evenement* evenement) {
    RespEvenementiel::planifierEvenement(evenement);
}

void TravailleurSocialEvenementiel::annulerEvenement(Evenement* evenement) {
    RespEvenementiel::annulerEvenement(evenement);
}

void TravailleurSocialEvenementiel::modifierEvenement(Evenement* evenement) {
    RespEvenementiel::modifierEvenement(evenement);
}

void TravailleurSocialEvenementiel::ajouterEvenement(Evenement* evenement) {
    RespEvenementiel::ajouterEvenement(evenement);
}

void TravailleurSocialEvenementiel::supprimerEvenement(Evenement* evenement) {
    RespEvenementiel::supprimerEvenement(evenement);
}

// Operator Overloading
ostream& operator<<(ostream& os, const TravailleurSocialEvenementiel& tse) {
    os << static_cast<const Utilisateur&>(tse); // Display Utilisateur details
    return os;
}

istream& operator>>(istream& is, TravailleurSocialEvenementiel& tse) {
    is >> static_cast<Utilisateur&>(tse); // Input for Utilisateur details
    return is;
}

// == Operator Overload
bool TravailleurSocialEvenementiel::operator==(const TravailleurSocialEvenementiel& other) const {
    return this->getId() == other.getId(); // Compare by ID for equality
}
