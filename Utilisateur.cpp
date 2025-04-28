#include "Utilisateur.h"

// Constructors
Utilisateur::Utilisateur() : Personne(), username(""), mdp("") {}

Utilisateur::Utilisateur(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp)
    : Personne(nom, prenom, age), username(username), mdp(mdp) {
    addId(idValue);  // Add the ID to the vector
}

// Copy Constructor
Utilisateur::Utilisateur(const Utilisateur& other)
    : Personne(other), username(other.username), mdp(other.mdp) {
    // Deep copy for dynamic parts
    for (const auto& ptr : other.id) {
        id.push_back(new int(*ptr));  // Copy integer values into new memory
    }
}

// Destructor
Utilisateur::~Utilisateur() {
    clearIds();  // Clean up dynamic memory
}

// CRUD Methods
void Utilisateur::modifierUtilisateur(vector<Utilisateur*>& utilisateurs, int idRecherche) {
    for (auto& utilisateur : utilisateurs) {
        if (*utilisateur->getId()[0] == idRecherche) {
            cout << "Utilisateur found: " << *utilisateur << endl;
            cout << "Modify information:" << endl;
            cin >> *utilisateur;  // Use overloaded >> to modify
            return;
        }
    }
    cout << "Utilisateur not found!" << endl;
}

void Utilisateur::supprimerUtilisateur(vector<Utilisateur*>& utilisateurs, int idRecherche) {
    for (auto it = utilisateurs.begin(); it != utilisateurs.end(); ++it) {
        if (*(*it)->getId()[0] == idRecherche) {
            delete *it;
            utilisateurs.erase(it);
            cout << "Utilisateur deleted!" << endl;
            return;
        }
    }
    cout << "Utilisateur not found!" << endl;
}

// Specific Methods
void Utilisateur::afficherProfil() const {
    cout << "Profile of " << getNom() << " " << getPrenom() << ":" << endl;
    cout << "Username: " << username << endl;
    cout << "Age: " << getAge() << endl;
    // Add more profile details if needed
}

bool Utilisateur::login(const string& username, const string& mdp) const {
    return this->username == username && this->mdp == mdp;
}

void Utilisateur::logout() const {
    cout << "Logged out!" << endl;
}

void Utilisateur::modifierMDP(const string& ancienMDP, const string& nouveauMDP) {
    if (mdp == ancienMDP) {
        mdp = nouveauMDP;
        cout << "Password changed!" << endl;
    } else {
        cout << "Incorrect old password!" << endl;
    }
}

// Getters and Setters
vector<int*> Utilisateur::getId() const {
    return id;
}

void Utilisateur::addId(int idValue) {
    id.push_back(new int(idValue));  // Dynamically allocate memory for ID
}

void Utilisateur::clearIds() {
    for (auto ptr : id) {
        delete ptr;  // Clean up dynamically allocated memory
    }
    id.clear();
}

string Utilisateur::getUsername() const {
    return username;
}

void Utilisateur::setUsername(const string& username) {
    this->username = username;
}

string Utilisateur::getMDP() const {
    return mdp;
}

void Utilisateur::setMDP(const string& mdp) {
    this->mdp = mdp;
}

// Surcharge operators
ostream& operator<<(ostream& os, const Utilisateur& u) {
    os << "Nom: " << u.getNom() << "\n";
    os << "Prenom: " << u.getPrenom() << "\n";
    os << "Username: " << u.getUsername() << "\n";
    os << "Age: " << u.getAge() << "\n";
    return os;
}

istream& operator>>(istream& is, Utilisateur& u) {
    cout << "Enter username: ";
    is >> u.username;
    cout << "Enter password: ";
    is >> u.mdp;
    // You can add more input prompts for other fields if needed
    return is;
}

bool Utilisateur::operator==(const Utilisateur& other) const {
    return username == other.username && mdp == other.mdp;
}
