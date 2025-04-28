#include "Administrateur.h"

// Constructors
Administrateur::Administrateur() : Utilisateur(), role("") {}

Administrateur::Administrateur(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp, const string& role)
    : Utilisateur(idValue, nom, prenom, age, username, mdp), role(role) {}

// Copy Constructor
Administrateur::Administrateur(const Administrateur& other)
    : Utilisateur(other), role(other.role) {}

// Destructor
Administrateur::~Administrateur() {
    // No specific dynamic memory for now, handled by Utilisateur destructor
}

// CRUD Methods
void Administrateur::modifierAdministrateur(vector<Administrateur*>& administrateurs, int idRecherche) {
    for (auto& admin : administrateurs) {
        if (*admin->getId()[0] == idRecherche) {
            cout << "Administrateur found: " << *admin << endl;
            cout << "Modify information:" << endl;
            cin >> *admin;
            return;
        }
    }
    cout << "Administrateur not found!" << endl;
}

void Administrateur::supprimerAdministrateur(vector<Administrateur*>& administrateurs, int idRecherche) {
    for (auto it = administrateurs.begin(); it != administrateurs.end(); ++it) {
        if (*(*it)->getId()[0] == idRecherche) {
            delete *it;
            administrateurs.erase(it);
            cout << "Administrateur deleted!" << endl;
            return;
        }
    }
    cout << "Administrateur not found!" << endl;
}

// Specific Methods
void Administrateur::gererAcces(Utilisateur* utilisateur) {
    cout << "Access managed for user: " << utilisateur->getUsername() << endl;
}

void Administrateur::assignerRole(Utilisateur* utilisateur, const string& nouveauRole) {
    cout << "Assigned role '" << nouveauRole << "' to user: " << utilisateur->getUsername() << endl;
}

// Getter and Setter
string Administrateur::getRole() const {
    return role;
}

void Administrateur::setRole(const string& role) {
    this->role = role;
}

// Overloaded Operators
ostream& operator<<(ostream& os, const Administrateur& admin) {
    os << static_cast<const Utilisateur&>(admin); // Display Utilisateur info
    os << "Role: " << admin.role << endl;
    return os;
}

istream& operator>>(istream& is, Administrateur& admin) {
    cout << "Enter username: ";
    is >> admin.username;
    cout << "Enter password: ";
    is >> admin.mdp;
    cout << "Enter role: ";
    is >> admin.role;
    return is;
}

// Override afficherProfil
void Administrateur::afficherProfil() const {
    Utilisateur::afficherProfil(); // Call base class method
    cout << "Role: " << role << endl;
}
