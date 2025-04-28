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
void TravailleurSocialEvenementiel::modifierTravailleurSocialEvenementiel(vector<TravailleurSocialEvenementiel*>& list, int idRecherche) {
    for (auto& tse : list) {
        if (*tse->getId()[0] == idRecherche) {
            cout << "TravailleurSocialEvenementiel found: " << *tse << endl;
            cout << "Modify information:" << endl;
            cin >> *tse;
            return;
        }
    }
    cout << "TravailleurSocialEvenementiel not found!" << endl;
}

void TravailleurSocialEvenementiel::supprimerTravailleurSocialEvenementiel(vector<TravailleurSocialEvenementiel*>& list, int idRecherche) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*(*it)->getId()[0] == idRecherche) {
            delete *it;
            list.erase(it);
            cout << "TravailleurSocialEvenementiel deleted!" << endl;
            return;
        }
    }
    cout << "TravailleurSocialEvenementiel not found!" << endl;
}

// Specific Methods
void TravailleurSocialEvenementiel::inscrireAUneFormation(SansAbri s, Formation* f) {
    RespEvenementiel::inscrireAUneFormation(s, f); // Appel direct à RespEvenementiel
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
    os << static_cast<const Utilisateur&>(tse); // Important d'afficher Utilisateur
    return os;
}

istream& operator>>(istream& is, TravailleurSocialEvenementiel& tse) {
    is >> static_cast<Utilisateur&>(tse);
    return is;
}
